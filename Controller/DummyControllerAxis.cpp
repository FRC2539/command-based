#include "DummyControllerAxis.h"

DummyControllerAxis::DummyControllerAxis() : ControllerAxis(0, 0) {}

DummyControllerAxis::~DummyControllerAxis() {}

float DummyControllerAxis::getValue()
{
	return 0;
}
