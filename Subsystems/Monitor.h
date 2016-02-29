#pragma once

#include <Commands/Subsystem.h>

/*
 * This subsystem exists to run checks that need to happen continually. It
 * starts MonitorCommand. Place checks in its Execute method;
 */
class Monitor: public Subsystem {
public:
	Monitor();

	virtual void InitDefaultCommand();
};