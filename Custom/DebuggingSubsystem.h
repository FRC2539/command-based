#pragma once

#include <Commands/Subsystem.h>
#include <LiveWindow/LiveWindow.h>

#define DEBUG_SENSOR(sensor)\
	LiveWindow::GetInstance()->AddSensor(GetName(), #sensor, sensor)

#define DEBUG_MOTOR(motor)\
	LiveWindow::GetInstance()->AddActuator(GetName(), #motor, motor)

// Stupid macro tricks: http://stackoverflow.com/questions/35879594
#define COUNT_ARGS_(A, B, C, N, ...) N
#define COUNT_ARGS(...) COUNT_ARGS_(__VA_ARGS__, 3, 2, 1)

#define CONCAT_(A, B) A##B
#define CONCAT(A, B) CONCAT_(A, B)

#define SetPID_1(PID) SetPID(PID[0], PID[1], PID[2])
#define SetPID_3(P, I, D) SetPID(P, I, D)
#define SetPID(...) CONCAT(SetPID_, COUNT_ARGS(__VA_ARGS__))(__VA_ARGS__)
