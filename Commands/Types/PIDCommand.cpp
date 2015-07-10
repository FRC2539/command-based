/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2011. All Rights Reserved.							  */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/

#include "PIDCommand.h"

#include <PIDController.h>

PIDCommand::PIDCommand(const char *name, double p, double i, double d, double f, double period) :
DefaultCommand(name)
{
	m_controller = new PIDController(p, i, d, this, this, period);
	m_controller->SetTolerance(0.5);
}

PIDCommand::PIDCommand(double p, double i, double d, double f, double period)
{
	m_controller = new PIDController(p, i, d, f, this, this, period);
	m_controller->SetTolerance(0.5);
}

PIDCommand::PIDCommand(const char *name, double p, double i, double d) :
DefaultCommand(name)
{
	m_controller = new PIDController(p, i, d, this, this);
	m_controller->SetTolerance(0.5);
}

PIDCommand::PIDCommand(const char *name, double p, double i, double d, double period) :
DefaultCommand(name)
{
	m_controller = new PIDController(p, i, d, this, this, period);
	m_controller->SetTolerance(0.5);
}

PIDCommand::PIDCommand(double p, double i, double d)
{
	m_controller = new PIDController(p, i, d, this, this);
	m_controller->SetTolerance(0.5);
}

PIDCommand::PIDCommand(double p, double i, double d, double period)
{
	m_controller = new PIDController(p, i, d, this, this, period);
	m_controller->SetTolerance(0.5);
}

PIDCommand::~PIDCommand()
{
	delete m_controller;
}

void PIDCommand::_Initialize()
{
	m_controller->Enable();
}

bool PIDCommand::IsFinished()
{
	return m_controller->OnTarget();
}

void PIDCommand::_End()
{
	m_controller->Disable();
}

void PIDCommand::_Interrupted()
{
	_End();
}

void PIDCommand::SetSetpointRelative(double deltaSetpoint)
{
	SetSetpoint(GetSetpoint() + deltaSetpoint);
}

void PIDCommand::setAbsoluteError(double error)
{
	m_controller->SetAbsoluteTolerance(error);
}

void PIDCommand::setPercentError(double error)
{
	m_controller->SetPercentTolerance(error);
}

void PIDCommand::setMaxOutput(double output)
{
	m_controller->SetOutputRange(-output, output);
}

void PIDCommand::PIDWrite(float output)
{
	UsePIDOutput(output);
}

double PIDCommand::PIDGet() const
{
	return ReturnPIDInput();
}

PIDController *PIDCommand::GetPIDController()
{
	return m_controller;
}

void PIDCommand::SetSetpoint(double setpoint)
{
	double current = GetSetpoint();

	if (current < setpoint)
	{
		m_controller->SetInputRange(current, setpoint);
	}
	else
	{
		m_controller->SetInputRange(setpoint, current);
	}
	m_controller->SetSetpoint(setpoint);
}

double PIDCommand::GetSetpoint()
{
	return m_controller->GetSetpoint();
}

double PIDCommand::GetPosition()
{
	return ReturnPIDInput();
}

std::string PIDCommand::GetSmartDashboardType(){
	return "PIDCommand";
}
void PIDCommand::InitTable(ITable* table){
	m_controller->InitTable(table);
	Command::InitTable(table);
}
