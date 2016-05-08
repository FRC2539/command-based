#include "Shooter.h"

#include "../Config.h"

#include <networktables/NetworkTable.h>
#include <Preferences.h>
#include <vector>

#include <CameraServer.h>
#include <USBCamera.h>
#include <nivision.h>
constexpr char const *USBCamera::kDefaultCameraName;

Shooter::Shooter() : Subsystem("Shooter"),
	m_ballDetector(Config::Shooter::ballDetectorID),
	m_leftPivotMotor(Config::Shooter::leftPivotMotorID),
	m_rightPivotMotor(Config::Shooter::rightPivotMotorID),
	m_indexWheel(Config::Shooter::indexWheelID),
	m_shooterWheel(Config::Shooter::shooterWheelID),
	m_settingsLoaded(false),
	m_sendFrame(true)
{
	m_indexWheel.SetControlMode(CANTalon::kPercentVbus);
	m_indexWheel.ConfigNeutralMode(CANTalon::kNeutralMode_Coast);
	m_indexWheel.SetInverted(true);

	m_shooterWheel.SetControlMode(CANTalon::kSpeed);
	m_shooterWheel.ConfigNeutralMode(CANTalon::kNeutralMode_Coast);
	m_shooterWheel.SetPID(Config::Shooter::shootingPID);
	m_shooterWheel.SetInverted(true);

	m_rightPivotMotor.SetControlMode(CANTalon::kPosition);
	/*m_leftPivotMotor.ConfigSoftPositionLimits(
		Config::Shooter::maxHeight,
		Config::Shooter::minHeight
	);*/
	m_rightPivotMotor.SetPID(Config::Shooter::pivotHoldPID);
	m_rightPivotMotor.ConfigMaxOutputVoltage(4);
	m_rightPivotMotor.SetInverted(true);

	m_leftPivotMotor.SetControlMode(CANTalon::kFollower);
	m_leftPivotMotor.Set(Config::Shooter::rightPivotMotorID);
	m_leftPivotMotor.SetClosedLoopOutputDirection(true);

	dashboard = CameraServer::GetInstance();
	camera = std::make_shared<USBCamera>(USBCamera::kDefaultCameraName, true);
	camera->OpenCamera();
	camera->StartCapture();

	m_targetInfo = NetworkTable::GetTable("cameraTarget");

	DEBUG_MOTOR(m_leftPivotMotor);
	DEBUG_MOTOR(m_rightPivotMotor);
	DEBUG_MOTOR(m_indexWheel);
	DEBUG_MOTOR(m_shooterWheel);

	DEBUG_SENSOR(m_ballDetector);
}

void Shooter::move(Shooter::Direction direction)
{
	m_direction = direction;
	if (atKnownPosition() == false)
	{
		return;
	}

	m_rightPivotMotor.ClearIaccum();
	m_rightPivotMotor.SetControlMode(CANTalon::kSpeed);
	m_rightPivotMotor.SetPID(Config::Shooter::pivotMovePID);

	if (direction == UP)
	{
		m_rightPivotMotor.Set(Config::Shooter::pivotSpeed);
	}
	else if (direction == DOWN)
	{
		m_rightPivotMotor.Set(-Config::Shooter::pivotSpeed);
	}
}

void Shooter::holdAt(int position)
{
	if (atKnownPosition() == false)
	{
		return;
	}

	m_rightPivotMotor.SetControlMode(CANTalon::kPosition);
	m_rightPivotMotor.SetPID(Config::Shooter::pivotHoldPID);
	m_rightPivotMotor.Set(position);
}

void Shooter::setIndexerSpeed(double speed)
{
	m_indexWheel.Set(speed);
}

void Shooter::setShooterSpeed(double speed)
{
	m_shooterWheel.SetControlMode(CANTalon::kSpeed);
	m_shooterWheel.Set(speed);
}

void Shooter::stopShooter()
{
	manualShooter(0);
}

void Shooter::manualPivot(double power)
{
	m_rightPivotMotor.SetControlMode(CANTalon::kPercentVbus);
	m_rightPivotMotor.Set(power);
}

void Shooter::manualShooter(double power)
{
	m_shooterWheel.SetControlMode(CANTalon::kPercentVbus);
	m_shooterWheel.Set(power);
}

bool Shooter::readyToFire()
{
	if (m_shooterWheel.GetSetpoint() != Config::Shooter::firingSpeed)
	{
		return false;
	}
	return std::abs(m_shooterWheel.GetClosedLoopError()) < 100;
}

int Shooter::getHeight()
{
	return m_rightPivotMotor.GetPosition();
}

bool Shooter::atTopLimit()
{
	return m_rightPivotMotor.IsRevLimitSwitchClosed();
}

bool Shooter::atBottomLimit()
{
	return m_rightPivotMotor.IsFwdLimitSwitchClosed();
}

void Shooter::setEncoderPosition(int position)
{
	m_rightPivotMotor.SetPosition(position);

	Preferences* preferences = Preferences::GetInstance();
	preferences->PutInt("shooterPosition", position);

	m_settingsLoaded = true;
}

void Shooter::storeEncoderPosition()
{
	if (atKnownPosition())
	{
		setEncoderPosition(getHeight());
	}
}

bool Shooter::hasBall()
{
	return m_ballDetector.Get();
}

Shooter::Target Shooter::getTarget()
{
	Target target;

	if (m_targetInfo->GetBoolean("hasTarget", false) == false)
	{
		return target;
	}

	target.found = true;
	target.position = m_targetInfo->GetNumber("centerX", 0);
	target.distance = m_targetInfo->GetNumber("distance", 0);

	return target;
}

bool Shooter::atKnownPosition()
{
	if ( ! m_settingsLoaded)
	{
		Preferences* preferences = Preferences::GetInstance();
		if (preferences->ContainsKey("shooterPosition"))
		{
			m_rightPivotMotor.SetPosition(preferences->GetInt("shooterPosition"));
			m_settingsLoaded = true;
		}
	}

	return m_settingsLoaded;
}

void Shooter::flipImage()
{
	if (m_sendFrame == false)
	{
		m_sendFrame = true;
		return;
	}

	Image* frame = imaqCreateImage(IMAQ_IMAGE_RGB, 0);
	camera->GetImage(frame);
	imaqFlip(frame, frame, IMAQ_HORIZONTAL_AXIS);
	dashboard->SetImage(frame);

	// We don't need to delete the frame because that is done by SetImage.
	// Probably.

	m_sendFrame = false;
}
