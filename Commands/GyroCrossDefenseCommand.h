#pragma once

#include "Types/InstantCommand.h"

class GyroCrossDefenseCommand : public InstantCommand {

public:
	explicit GyroCrossDefenseCommand();
    virtual ~GyroCrossDefenseCommand();
	void Initialize() override;

protected:
	Command* m_toCourtyard;
	Command* m_toNeutralZone;
	Command* m_currentCommand;
};
