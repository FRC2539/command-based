#ifndef DEBUGGING_SUBSYSTEM
#define DEBUGGING_SUBSYSTEM

#include <Commands/Subsystem.h>
#include "../RobotMap.h"

#ifdef DEBUG
#include <LiveWindow/LiveWindow.h>
#define DEBUG_SENSOR(sensor)\
	LiveWindow::GetInstance()->AddSensor(GetName().c_str(), #sensor, sensor);
#else
#define DEBUG_SENSOR(sensor)
#endif

#endif