/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2011. All Rights Reserved.							  */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/

#include "SensorCommand.h"

#include <PIDController.h>
#include "../../Custom/Netconsole.h"

SensorCommand::SensorCommand(const char *name, double target, double p, double i, double d, double f, double period) :
DefaultCommand(name)
{
	Setup(target, p, i, d, f, period);
}

SensorCommand::SensorCommand(double target, double p, double i, double d, double f, double period)
{
	Setup(target, p, i, d, f, period);
}

void SensorCommand::Setup(double target, double p, double i, double d, double f, double period)
{
	m_target = target;
	m_fixedRange = false;
	m_rangeMin = target;
	m_rangeMax = target;

	m_controller = new PIDController(p, i, d, f, this, this, period);
	m_controller->SetTolerance(0.5);
	m_controller->SetToleranceBuffer(1);
}

SensorCommand::~SensorCommand()
{
	delete m_controller;
}

void SensorCommand::_Initialize()
{
	m_controller->Reset();
	m_controller->Enable();
}

void SensorCommand::Initialize()
{
    SetSetpoint(m_target);
}

bool SensorCommand::IsFinished()
{
	return m_controller->OnTarget();
}

void SensorCommand::_End()
{
	Netconsole::instant("Disable Controller", 0);
	m_controller->Disable();
	Netconsole::instant("Controller", m_controller->IsEnabled());
}

void SensorCommand::_Interrupted()
{
	_End();
}

void SensorCommand::SetSetpointRelative(double deltaSetpoint)
{
	SetSetpoint(GetSetpoint() + deltaSetpoint);
}

void SensorCommand::setAbsoluteError(double error)
{
	m_controller->SetAbsoluteTolerance(error);
}

void SensorCommand::setPercentError(double error)
{
	m_controller->SetPercentTolerance(error);
}

void SensorCommand::setMaxOutput(double output)
{
	m_controller->SetOutputRange(-output, output);
}

void SensorCommand::setOutputRange(double min, double max)
{
	m_controller->SetOutputRange(min, max);
}

void SensorCommand::setInputRange(double min, double max)
{
	m_controller->SetInputRange(min, max);
	m_fixedRange = true;
}

void SensorCommand::PIDWrite(float output)
{
	if (IsRunning())
	{
		UsePIDOutput(output);
	}
}

double SensorCommand::PIDGet()
{
	return ReturnPIDInput();
}

PIDController *SensorCommand::GetPIDController()
{
	return m_controller;
}

void SensorCommand::SetSetpoint(double setpoint)
{
	double current = GetSetpoint();

	if ( ! m_fixedRange)
	{
		modifyRange(current, setpoint);
	}
	m_controller->SetSetpoint(setpoint);
}

double SensorCommand::GetSetpoint()
{
	return m_controller->GetSetpoint();
}

double SensorCommand::GetPosition()
{
	return ReturnPIDInput();
}

void SensorCommand::modifyRange(double current, double next)
{
	if (current < next)
	{
		if (current < m_rangeMin)
		{
			m_rangeMin = current;
		}
		if (next > m_rangeMax)
		{
			m_rangeMax = next;
		}
	}
	else
	{
		if (next < m_rangeMin)
		{
			m_rangeMin = next;
		}
		if (current > m_rangeMax)
		{
			m_rangeMax = current;
		}
	}
	m_controller->SetInputRange(m_rangeMin, m_rangeMax);
}

std::string SensorCommand::GetSmartDashboardType(){
	return "SensorCommand";
}
void SensorCommand::InitTable(std::shared_ptr<ITable> table){
	m_controller->InitTable(table);
	Command::InitTable(table);
}
