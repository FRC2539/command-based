#pragma once

#include <Commands/Subsystem.h>
#include "../Config.h"

#if defined(DEBUG)
#include <LiveWindow/LiveWindow.h>

#define DEBUG_SENSOR(sensor)\
	LiveWindow::GetInstance()->AddSensor(GetName().c_str(), #sensor, sensor)

#define DEBUG_MOTOR(motor)\
	LiveWindow::GetInstance()->AddActuator(GetName().c_str(), #motor, motor)

#else

#define DEBUG_SENSOR(sensor)
#define DEBUG_MOTOR(motor)

#endif