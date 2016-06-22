#pragma once

#include "../Types/InstantCommand.h"

class AssumeStartingConfigCommand : public InstantCommand {

public:
	explicit AssumeStartingConfigCommand(bool forward=false);
	void Initialize() override;

protected:
	bool m_facingForward;
};
