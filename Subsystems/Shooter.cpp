#include "Shooter.h"
#include "../Config.h"
#include <DigitalInput.h>


Shooter::Shooter() : Subsystem("Shooter"),
	m_maxTallLS(Config::Shooter::maxTallLSID),
	m_minTallLS(Config::Shooter::minTallLSID),

	m_ballDetector(Config::Shooter::ballDetectorID),

	m_tallMotorLeft(Config::Shooter::tallMotorLeftID),
	m_tallMotorRight(Config::Shooter::tallMotorRightID),
	m_indexWheel(Config::Shooter::indexWheelID),
	m_shooterWheel(Config::Shooter::shooterWheelID)
{
	m_indexWheel.SetControlMode(CANTalon::kPercentVbus);

	m_shooterWheel.SetControlMode(CANTalon::kSpeed);
	m_shooterWheel.SetI(Config::Shooter::I);

	m_tallMotorLeft.SetControlMode(CANTalon::kPosition);
	m_tallMotorLeft.ConfigSoftPositionLimits(
		Config::Shooter::maxTall,
		Config::Shooter::minTall
	);
	m_tallMotorLeft.SetP(Config::Shooter::P);

	m_tallMotorRight.SetControlMode(CANTalon::kPosition);
	m_tallMotorRight.ConfigSoftPositionLimits(
		Config::Shooter::maxTall,
		Config::Shooter::minTall
	);
	m_tallMotorRight.SetP(Config::PickupArms::P);

	DEBUG_MOTOR(m_tallMotorLeft);
	DEBUG_MOTOR(m_tallMotorRight);
	DEBUG_MOTOR(m_indexWheel);
	DEBUG_MOTOR(m_shooterWheel);
}

void Shooter::pivotToHeight(double position)
{
	m_tallMotorLeft.SetPosition(position);
	m_tallMotorRight.SetPosition(position);
}

void Shooter::setPickerUpperRotateSpeed(float speed)
{
	m_indexWheel.Set(speed);
}

void Shooter::setShooterSpeed(float speed)
{
	m_shooterWheel.Set(speed);
}

bool Shooter::hasBall()
{
	return m_ballDetector.Get();
}

void Shooter::getTarget(){
	std::shared_ptr<NetworkTable> table;
	table = NetworkTable::GetTable("GRIP/myContoursReport");
	std::vector<double> heights = table->GetNumberArray("height", llvm::ArrayRef<double>());
	std::vector<double> width = table->GetNumberArray("width", llvm::ArrayRef<double>());
	std::vector<double> centerX = table->GetNumberArray("centerX", llvm::ArrayRef<double>());

	std::vector<double> scores;

	int i = 0;
	double aspect = 12/20;
	CameraWidth = 640;

	for (double height : heights){
		double aspectError = std::abs((height/width[i])-aspect);
		double positionError = std::abs(centerX[i] - CameraWidth / 2);
		positionError = positionError / CameraWidth;

		scores.push_back(aspectError + positionError);
		i++;
	}

	int best = 0;
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
		table->PutNumber("Distance", -0.332564 * width[best] + 29.847575);
		table->PutNumber("targetCenterX", centerX[best] - CameraWidth /2);
}

