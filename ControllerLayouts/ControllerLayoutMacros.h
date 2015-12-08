// Macros to make defining inputs simpler

#define ADD_CONTROLLER(type, port)\
	controllers[port] = new type(port);\
	type *ControllerHack##port = 0

#define ADD_AXIS(port, axis, handle)\
	delete axes[handle];\
	axes[handle] = new ControllerAxis(controllers[port], ControllerHack##port->axis)

#define MODIFY_AXIS(handle, modifier)\
	axes[handle]->setModifier(modifier)

#define INVERT_AXIS(handle)\
	axes[handle]->invert()

#define THROTTLE_SCALE_AXIS(handle)\
	axes[handle]->makeThrottle()

#define ADD_BUTTON(port, button, event, command)\
	lastCommand = command;\
	buttonIntValue = ControllerHack##port->button;\
	if (buttonIntValue >= 20)\
	{\
		buttons.push_back(new POVButton(controllers[port], (buttonIntValue - 20) * 90));\
	}\
	else\
	{\
		buttons.push_back(new ControllerButton(controllers[port], buttonIntValue));\
	}\
	buttons.back()->event(lastCommand)

#define ADD_SIMPLE_BUTTON(port, button, command_class)\
	ADD_BUTTON(port, button, WhenPressed, new command_class())

#define ADD_TOGGLE_BUTTON(port, button, command)\
	ADD_BUTTON(port, button, ToggleWhenPressed, command)
