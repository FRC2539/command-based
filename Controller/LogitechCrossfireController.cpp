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
		{"DPadY", 2}
	};
	invertedAxes = {axes["LeftY"], axes["RightY"]};
}


