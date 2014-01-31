#include "LogitechCrossfireController.h"

LogitechCrossfireController::LogitechCrossfireController(UINT32 port)
	: GenericController(port) {
		init();
	}

LogitechCrossfireController::LogitechCrossfireController(
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

void LogitechCrossfireController::init()
{
	axes = {
		{"LeftX", 1},
		{"LeftY", 2},
		{"RightX", 4},
		{"RightY", 5},
		{"LeftTrigger", 3},
		{"RightTrigger", 3},
		{"DPadX", 6},
		{"DPadY", 2},
	};

	buttons = {
		{"A", 1},
		{"B", 2},
		{"X", 3},
		{"Y", 4},
		{"LeftBumper", 5},
		{"RightBumper", 6},
		{"Back", 7},
		{"Start", 8},
		{"LeftJoystick", 9},
		{"RightJoystick", 10}
	};
	invertedAxes = {axes["LeftY"], axes["RightY"]};
}


