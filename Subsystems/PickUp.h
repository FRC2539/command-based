#ifndef PICK_UP_H
#define PICK_UP_H

#include "Commands/Subsystem.h"
#include <Victor.h>


class PickUp: public Subsystem {
public:
	PickUp();
	virtual ~PickUp();
	void InitDefaultCommand();

	void pickup(float direction);

protected:
	Victor* motor;
};

#endif
