#include "DrawBackCommandGroup.h"

#include "DrawBackCommand.h"
#include "RunBackCommand.h"

DrawBackCommandGroup::DrawBackCommandGroup() {
	AddSequential(new DrawBackCommand());
	AddSequential(new RunBackCommand());
}
