#ifndef CONTROLLER_MAP_H
#define CONTROLLER_MAP_H

#define ADD_CONTROLLER(type, port)\
	controllers[port] = new type(port);

#define ADD_AXIS(system, port, axis)\
	if (axes.count(#system) == 0)\
	{\
		axes.emplace(#system, std::vector<ControllerAxis*>());\
	}\
	lastAxis = new ControllerAxis(controllers[port], #axis);\
	axes[#system].push_back(lastAxis);

#define MODIFY_AXIS(modifier)\
	lastAxis->setModifier(modifier);

#define ADD_BUTTON(port, button, event, command)\
	buttons.push_back(new ControllerButton(controllers[port], #button));\
	buttons.back()->event(command);

#define ADD_SIMPLE_BUTTON(port, button, command_stem)\
	buttons.push_back(new ControllerButton(controllers[port], #button));\
	buttons.back()->WhenPressed(new command_stem##Command());


#include "ControllerLayouts/ProgrammersMap.h"


#endif
