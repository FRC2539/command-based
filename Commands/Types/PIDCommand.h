#ifndef PID_COMMAND_H
#define PID_COMMAND_H

// This is copied directly from the PIDCommand provided by WPILib, to make it
// inherit from DefaultCommand and add some nice defaults

#include <PIDSource.h>
#include <PIDOutput.h>

#include "DefaultCommand.h"

class PIDController;

class PIDCommand : public DefaultCommand, public PIDOutput, public PIDSource
{
public:
	PIDCommand(const char *name, double p, double i, double d);
	PIDCommand(const char *name, double p, double i, double d, double period);
	PIDCommand(const char *name, double p, double i, double d, double f, double perioid);
	PIDCommand(double p, double i, double d);
	PIDCommand(double p, double i, double d, double period);
	PIDCommand(double p, double i, double d, double f, double period);
	virtual ~PIDCommand();

	void SetSetpointRelative(double deltaSetpoint);

	// PIDOutput interface
	virtual void PIDWrite(float output);

	// PIDSource interface
	virtual double PIDGet() const;

	void setPercentError(double error);
	void setAbsoluteError(double error);
	void setMaxOutput(double output);

	virtual bool IsFinished();

protected:
	PIDController *GetPIDController();
	virtual void _Initialize();
	virtual void _Interrupted();
	virtual void _End();
	void SetSetpoint(double setpoint);
	double GetSetpoint();
	double GetPosition();

	virtual double ReturnPIDInput() const = 0;
	virtual void UsePIDOutput(double output) = 0;

private:
	/** The internal {@link PIDController} */
	PIDController *m_controller;

public:
	virtual void InitTable(ITable* table);
	virtual std::string GetSmartDashboardType();
};

#endif
