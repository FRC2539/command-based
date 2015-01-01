// Macros to make defining inputs simpler

#define ADD_CONTROLLER(type, port)\
	controllers[port] = new type(port);\
	type *ControllerHack##port = 0;

#define ADD_AXIS(port, axis, handle)\
	delete axes[handle];\
	axes[handle] = new ControllerAxis(controllers[port], ControllerHack##port->axis);

#define MODIFY_AXIS(handle, modifier)\
	axes[handle]->setModifier(modifier);

#define INVERT_AXIS(handle)\
	axes[handle]->invert();

#define THROTTLE_SCALE_AXIS(handle)\
	axes[handle]->makeThrottle();

#define ADD_BUTTON(port, button, event, command)\
	lastCommand = command;\
	buttons.push_back(new ControllerButton(controllers[port], ControllerHack##port->button));\
	buttons.back()->event(lastCommand);

#define ADD_SIMPLE_BUTTON(port, button, command_class)\
	lastCommand = new command_class();\
	buttons.push_back(new ControllerButton(controllers[port], ControllerHack##port->button));\
	buttons.back()->WhenPressed(lastCommand);

#define ADD_TOGGLE_BUTTON(port, button, command_class)\
	lastCommand = new ToggleCommand(new command_class());\
	buttons.push_back(new ControllerButton(controllers[port], ControllerHack##port->button));\
	buttons.back()->WhenPressed(lastCommand);
