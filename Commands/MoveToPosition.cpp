#include "MoveToPosition.h"

MoveToPosition::MoveToPosition() : InstantCommand("MoveToPosition")
{}

void MoveToPosition::Initialize()
{
	shooter->pivotToHeight(-112);
}

