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
		{LeftX, 1},
		{LeftY, 2},
		{RightX, 3},
		{RightY, 4},
		{DPadX, 5},
		{DPadY, 6}
	};
	invertedAxes = {kLeftYAxis, kRightYAxis, kDPadYAxis};
}
