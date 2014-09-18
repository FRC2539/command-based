// These are logical axes, and do not correspond to any actual axis on a real
// controller. Any axis used by a command (or anything else that needs an axis
// value outside of OI) must be defined in here. If you add more axes, make sure
// that you update the total number of axes as well.
//
// The numbering of axes is entirely arbitrary, but should be sequential,
// starting at 0.

#define DRIVE_AXIS_Y 0
#define DRIVE_AXIS_X 1
#define DRIVE_AXIS_ROTATE 2

#define TOTAL_LOGICAL_AXES 3