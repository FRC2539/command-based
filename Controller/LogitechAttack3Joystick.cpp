#include "LogitechAttack3Joystick.h"

LogitechAttack3Joystick::LogitechAttack3Joystick(UINT32 port)
	: GenericController(port) {
		m_inverted_y = true;
	}

LogitechAttack3Joystick::LogitechAttack3Joystick(
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

