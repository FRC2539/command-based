#include "Autonomous.h"
#include "RunMotor.h"
#include "StopMotor.h"

Autonomous::Autonomous() {
	AddSequential(new RunMotor(.2, 5));
	AddSequential(new StopMotor());
}
