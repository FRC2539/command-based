#include "AutoDefenseTraverseCommandGroup.h"

#include "AutoDefenseTraverse180.h"
#include "AutoDefenseTraverseZero.h"
#include "DriveToFloor.h"


AutoDefenseTraverseCommandGroup::AutoDefenseTraverseCommandGroup() : CommandGroup("AutoDefenseTraverse")
{
	AddSequential(new AutoDefenseTraverseZero());
	AddSequential(new AutoDefenseTraverse180());
	AddSequential(new DriveToFloor());
}