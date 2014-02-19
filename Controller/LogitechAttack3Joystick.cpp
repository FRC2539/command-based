#include "LogitechAttack3Joystick.h"

LogitechAttack3Joystick::LogitechAttack3Joystick(UINT32 port)
	: GenericController(port) {
		init();
	}

LogitechAttack3Joystick::LogitechAttack3Joystick(
		UINT32 port,
		UINT32 numAxisTypes,
		UINT32 numButtonTypes
	): GenericController(
		port,
		numAxisTypes,
		numButtonTypes
	){
		init();
	}

void LogitechAttack3Joystick::init()
{
	axes = {
		{"X", 1},
		{"Y", 2},
		{"Throttle", 3}
	};

	buttons = {
		{"Trigger", 1},
		{"Top", 2},
		{"2",  2},
		{"3",  3},
		{"4",  4},
		{"5",  5},
		{"6",  6},
		{"7",  7},
		{"8",  8},
		{"9",  9},
		{"10",  10},
		{"11",  11},
	};

	invertedAxes = {axes["Y"], axes["Throttle"]};
}
	
