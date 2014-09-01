#include "AndroidDriverStation.h"

AndroidDriverStation::AndroidDriverStation(UINT32 port)
	: GenericController(port) {
		init();
	}

AndroidDriverStation::AndroidDriverStation(
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
}
