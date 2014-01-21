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
	invertedAxes = {kLeftYAxis, kRightYAxis, kDPadYAxis};
}
