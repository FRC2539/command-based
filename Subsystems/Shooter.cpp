#include "Shooter.h"

#include "../Config.h"

#include <networktables/NetworkTable.h>
#include <vector>

Shooter::Shooter() : Subsystem("Shooter"),
	m_ballDetector(Config::Shooter::ballDetectorID),
	m_tallMotorLeft(Config::Shooter::tallMotorLeftID),
	m_tallMotorRight(Config::Shooter::tallMotorRightID),
	m_indexWheel(Config::Shooter::indexWheelID),
	m_shooterWheel(Config::Shooter::shooterWheelID),
	m_cameraWidth(640)
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

	m_gripOutput = NetworkTable::GetTable("GRIP/myContoursReport");
	m_targetInfo = NetworkTable::GetTable("cameraTarget");

	DEBUG_MOTOR(m_tallMotorLeft);
	DEBUG_MOTOR(m_tallMotorRight);
	DEBUG_MOTOR(m_indexWheel);
	DEBUG_MOTOR(m_shooterWheel);

	DEBUG_SENSOR(m_ballDetector);
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
