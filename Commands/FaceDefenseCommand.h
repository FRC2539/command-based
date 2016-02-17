#pragma once

#include "Types/DefaultCommand.h"

class FaceDefenseCommand : public DefaultCommand {

public:
	explicit FaceDefenseCommand();
    virtual ~FaceDefenseCommand();
	void Initialize() override;
	bool IsFinished() override;

protected:
	Command* m_faceCourtyard;
	Command* m_faceNeutralZone;
	Command* m_currentCommand;
};
