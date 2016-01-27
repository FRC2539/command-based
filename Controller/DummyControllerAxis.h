#pragma once

/* This class exists as a placeholder for logical axes that are not hooked to
 * real axes on a controller. It will always have a value of 0.
 */

#include "ControllerAxis.h"

class DummyControllerAxis : public ControllerAxis {
public:
	DummyControllerAxis();
	virtual ~DummyControllerAxis();

	virtual float getValue();
};
