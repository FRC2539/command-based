#pragma once

#include "Joystick.h"
#include <unordered_set>
#include <unordered_map>

class GenericController : public Joystick {

	friend class ControllerAxis;
	friend class ControllerButton;

public:
	
	explicit GenericController(uint32_t port);
	GenericController(uint32_t port, uint32_t numAxisTypes, uint32_t numButtonTypes);

	virtual float GetX();
	virtual float GetY();
	virtual float GetZ();
	virtual float GetTwist();
	virtual float GetThrottle();
	virtual float GetAxisValue(uint32_t axis);
	virtual bool IsButtonPressed(unsigned int button);

protected:
	virtual bool isInverted(uint32_t axis);
	std::unordered_set<int> invertedAxes;
	virtual void init() = 0;
};

#define CONTROLLER_SETUP(name)\
	name::name(uint32_t port)\
		: GenericController(port) { init(); }\
	\
	name::name(\
		uint32_t port,\
		uint32_t numAxisTypes,\
		uint32_t numButtonTypes\
	): GenericController(\
		port,\
		numAxisTypes,\
		numButtonTypes\
	){ init(); }
