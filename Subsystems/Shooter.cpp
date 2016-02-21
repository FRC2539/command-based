#include "Shooter.h"

#include "../Config.h"

#include <networktables/NetworkTable.h>
#include <vector>

Shooter::Shooter() : Subsystem("Shooter"),
	m_ballDetector(Config::Shooter::ballDetectorID),
	m_leftPivotMotor(Config::Shooter::leftPivotMotorID),
	m_rightPivotMotor(Config::Shooter::rightPivotMotorID),
	m_indexWheel(Config::Shooter::indexWheelID),
	m_shooterWheel(Config::Shooter::shooterWheelID),
	m_cameraWidth(640)
{
	m_indexWheel.SetControlMode(CANTalon::kPercentVbus);
	m_indexWheel.ConfigNeutralMode(CANTalon::kNeutralMode_Coast);

	m_shooterWheel.SetControlMode(CANTalon::kSpeed);
	m_shooterWheel.ConfigNeutralMode(CANTalon::kNeutralMode_Coast);
	m_shooterWheel.SetI(Config::Shooter::I);

	m_leftPivotMotor.SetControlMode(CANTalon::kPosition);
	m_leftPivotMotor.ConfigSoftPositionLimits(
		Config::Shooter::maxHeight,
		Config::Shooter::minHeight
	);
	m_leftPivotMotor.SetP(Config::Shooter::P);

	m_rightPivotMotor.SetControlMode(CANTalon::kPosition);
	m_rightPivotMotor.ConfigSoftPositionLimits(
		Config::Shooter::maxHeight,
		Config::Shooter::minHeight
	);
	m_rightPivotMotor.SetP(Config::PickupArms::P);

	m_gripOutput = NetworkTable::GetTable("GRIP/myContoursReport");
	m_targetInfo = NetworkTable::GetTable("cameraTarget");

	DEBUG_MOTOR(m_leftPivotMotor);
	DEBUG_MOTOR(m_rightPivotMotor);
	DEBUG_MOTOR(m_indexWheel);
	DEBUG_MOTOR(m_shooterWheel);

	DEBUG_SENSOR(m_ballDetector);
}

void Shooter::pivotToHeight(double position)
{
	m_leftPivotMotor.SetPosition(position);
	m_rightPivotMotor.SetPosition(position);
}

void Shooter::setIndexerSpeed(float speed)
{
	m_indexWheel.Set(speed);
}

void Shooter::setShooterSpeed(float speed)
{
	m_shooterWheel.SetControlMode(CANTalon::kSpeed);
	m_shooterWheel.Set(speed);
}

void Shooter::stopShooter()
{
	m_shooterWheel.SetControlMode(CANTalon::kPercentVbus);
	m_shooterWheel.Set(0);
}

bool Shooter::readyToFire()
{
	if (m_shooterWheel.GetSetpoint() != Config::Shooter::firingSpeed)
	{
		return false;
	}
	return std::abs(m_shooterWheel.GetClosedLoopError()) < 100;
}

bool Shooter::hasBall()
{
	return m_ballDetector.Get();
}

void Shooter::calculateTargetPosition(){
	std::vector<double> heights = m_gripOutput->GetNumberArray(
		"height",
		llvm::ArrayRef<double>()
	);
	std::vector<double> widths = m_gripOutput->GetNumberArray(
		"width",
		llvm::ArrayRef<double>()
	);
	std::vector<double> centerX = m_gripOutput->GetNumberArray(
		"centerX",
		llvm::ArrayRef<double>()
	);

	if (heights.size() == 0)
	{
		m_targetInfo->PutBoolean("hasTarget", false);
	}

	std::vector<double> scores;

	int i = 0;
	double aspect = 12/20;
	m_cameraWidth = 640;

	for (double height : heights)
	{
		double aspectError = std::abs(height / widths[i] - aspect);
		double positionError = std::abs(centerX[i] - m_cameraWidth / 2);
		positionError = positionError / m_cameraWidth;

		scores.push_back(aspectError + positionError);
		i++;
	}

	int best = 0;
	i = 0;
	double leastError = 10000;
	for (double score : scores)
	{
		if (score < leastError)
		{
			leastError = score;
			best = i;
		}
		i++;
	}

	m_targetInfo->PutBoolean("hasTarget", true);
	m_targetInfo->PutNumber("distance", 29.847575 - 0.332564 * widths[best]);
	m_targetInfo->PutNumber("centerX", centerX[best] - m_cameraWidth / 2);
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
