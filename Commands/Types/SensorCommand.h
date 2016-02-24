#pragma once

// This is based on the PIDCommand provided by WPILib, to make it
// inherit from DefaultCommand and add some nice defaults

#include <PIDSource.h>
#include <PIDOutput.h>

#include "DefaultCommand.h"

class PIDController;

class SensorCommand : public DefaultCommand, public PIDOutput, public PIDSource
{
public:
	SensorCommand(
		const char *name,
		double target,
		double p,
		double i,
		double d,
		double f=0,
		double period=0.05
	);
	SensorCommand(
		double target,
		double p,
		double i,
		double d,
		double f=0,
		double period=0.05
	);
	virtual ~SensorCommand();

	void SetSetpointRelative(double deltaSetpoint);

	// PIDOutput interface
	virtual void PIDWrite(float output);

	// PIDSource interface
	virtual double PIDGet();

	void setPercentError(double error);
	void setAbsoluteError(double error);
	void setMaxOutput(double output);
	void setOutputRange(double min, double max);
	void setInputRange(double min, double max);

	virtual void Initialize();
	virtual bool IsFinished();

protected:
	PIDController *GetPIDController();
	void Setup(
		double target,
		double p,
		double i,
		double d,
		double f=0,
		double period=0.05
	);
	virtual void _Initialize();
	virtual void _Interrupted();
	virtual void _End();
	void SetSetpoint(double setpoint);
	double GetSetpoint();
	double GetPosition();

	void modifyRange(double current, double next);

	double m_target;
	bool m_fixedRange;
	double m_rangeMin;
	double m_rangeMax;

	virtual double ReturnPIDInput() const = 0;
	virtual void UsePIDOutput(double output) = 0;

	/** The internal {@link PIDController} */
	PIDController *m_controller;

public:
	virtual void InitTable(std::shared_ptr< ITable > table);
	virtual std::string GetSmartDashboardType();
};
