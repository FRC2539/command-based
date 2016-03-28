#pragma once

#include <Commands/Subsystem.h>
#include <LiveWindow/LiveWindow.h>

#define DEBUG_SENSOR(sensor)\
	LiveWindow::GetInstance()->AddSensor(GetName(), #sensor, sensor)

#define DEBUG_MOTOR(motor)\
	LiveWindow::GetInstance()->AddActuator(GetName(), #motor, motor)
