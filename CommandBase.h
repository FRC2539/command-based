#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <Commands/Command.h>

// These should not be converted to forward declaration, as the full subsystem
// definitions are required by the Commands.
#include "Config.h"
#include "Subsystems/DriveTrain.h"
#include "Subsystems/Elevator.h"
#include "Subsystems/Tines.h"
#include "OI.h"

/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code use CommandBase::examplesubsystem
 */
class CommandBase: public Command {
public:
	CommandBase(const char *name, double timeout);
	CommandBase(const char *name);
	CommandBase(double timeout);
	CommandBase();
	virtual ~CommandBase();
	static void init();

	// Create a single static instance of each of your subsystems
	static DriveTrain *drivetrain;
	static Elevator *elevator;
	static Tines *tines;
	static OI *oi;
};

#endif
