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
	invertedAxes = {kLeftYAxis, kRightYAxis};
}


