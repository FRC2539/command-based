#include "DrawBackCommand.h"
#include "../Robotmap.h"
#include <iostream>

DrawBackCommand::DrawBackCommand() {

	Requires(shooter);
}

void DrawBackCommand::Initialize() {
	shooter->retractLauncher();
}

void DrawBackCommand::Execute()
{
}

bool DrawBackCommand::IsFinished() {
	printf("DrawBackCommand is over \n");
	return false;
}

void DrawBackCommand::End() {
	shooter->off();
	printf("end\n");
}

void DrawBackCommand::Interrupted() {
	shooter->off();
	printf("off\n");
}

