#include "FireCommandGroup.h"
#include "DrawBackCommandGroup.h"
#include "FireCommand.h"

FireCommandGroup::FireCommandGroup() {
	AddSequential(new FireCommand());
}
