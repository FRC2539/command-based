#ifndef OI_H
#define OI_H

#include "Controller/GenericController.h"
#include "Robotmap.h"

class OI {
public:
	OI();
	~OI();
	GenericController* getController();

protected:
	GenericController* controller;
};

#endif
