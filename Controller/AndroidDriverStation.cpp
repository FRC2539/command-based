#include "AndroidDriverStation.h"

AndroidDriverStation::AndroidDriverStation(UINT32 port)
	: GenericController(1) {
		init();
	}

AndroidDriverStation::AndroidDriverStation(
		UINT32 port,
		UINT32 numAxisTypes,
		UINT32 numButtonTypes
	): GenericController(
		1,
		numAxisTypes,
		numButtonTypes
	) {
		init();
	}

AndroidDriverStation::~AndroidDriverStation()
{
	delete secondJoystick;
}

void AndroidDriverStation::init()
{
	axes = {
		{"LeftX", 1},
		{"LeftY", 2},
		{"RightX", 3},
		{"RightY", 4}
	};

	buttons = {
		{"RightNE", 1},
		{"RightNW", 2},
		{"RightSE", 3},
		{"RightSW", 4},
		{"LeftNE", 5},
		{"LeftNW", 6},
		{"LeftSE" , 7},
		{"LeftSW", 8}
	};

	invertedAxes = {axes["LeftY"], axes["RightY"]};

	secondJoystick = new Joystick(2);
}

float AndroidDriverStation::GetAxis(const char* axis)
{
	if (axes[axis] <= 2)
	{
		return GenericController::GetAxis(axes[axis]);
	}

	UINT32 axisNumber = axes[axis] - 2;

	if (isInverted(axes[axis]))
	{
		return -1 * secondJoystick->GetRawAxis(axisNumber);
	}

	return secondJoystick->GetRawAxis(axisNumber);
}
