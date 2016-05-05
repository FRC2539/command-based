#pragma once

#include "../Types/TimedCommand.h"

class ManualDriveCommand : public TimedCommand {

public:
	template<typename TimeUnit>
	ManualDriveCommand(std::chrono::duration<TimeUnit> timeout)
		: TimedCommand("ManualDrive", timeout)
	{
		Requires(drivetrain);
	};
	void Execute() override;
	void End() override;
};
