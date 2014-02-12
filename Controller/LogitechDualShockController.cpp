#include "LogitechDualShockController.h"

LogitechDualShockController::LogitechDualShockController(UINT32 port)
	: GenericController(port) {
		init();
	}

LogitechDualShockController::LogitechDualShockController(
		UINT32 port,
		UINT32 numAxisTypes,
		UINT32 numButtonTypes
	): GenericController(
		port,
		numAxisTypes,
		numButtonTypes
	) {
		init();
	}

void LogitechDualShockController::init()
{
	axes = {
		{"LeftX", 1},
		{"LeftY", 2},
		{"RightX", 3},
		{"RightY", 4},
		{"DPadX", 5},
		{"DPadY", 6}
	};

	buttons = {
		{"A", 2},
		{"B", 3},
		{"X", 1},
		{"Y", 4},
		{"LeftBumper", 5},
		{"RightBumper", 6},
		{"LeftTrigger" , 7},
		{"RightTrigger", 8},
		{"Back", 9},
		{"Start", 10},
		{"LeftJoystick", 11},
		{"RightJoystick", 12}
	};

	invertedAxes = {axes["LeftY"], axes["RightY"], axes["DPadY"]};
}
