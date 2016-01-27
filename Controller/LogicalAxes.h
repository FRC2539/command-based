#pragma once

// These are logical axes, and do not correspond to any actual axis on a real
// controller. Any axis used by a command (or anything else that needs an axis
// value outside of OI) must be defined in here.

namespace logicalAxes {
	enum Axes {
		DriveY,
		DriveX,
		DriveRotate,
		NumOfAxes // Must always be last
	};
}