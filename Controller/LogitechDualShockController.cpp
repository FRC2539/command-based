#include "LogitechDualShockController.h"

LogitechDualShockController::LogitechDualShockController(UINT32 port)
	: GenericController(port) {
		m_inverted_y = true;
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
		m_inverted_y = true;
	}


