#ifndef TINE_WIDTH_COMMAND_H
#define TINE_WIDTH_COMMAND_H

#include "Types/PIDCommand.h"

class TineWidthCommand : public PIDCommand {

public:
	TineWidthCommand(float width);
	void Initialize();
	void Execute();

protected:
	virtual double ReturnPIDInput() const;
	virtual void UsePIDOutput(double output);

	float m_lastWidth;
	unsigned int m_stalledCount;
	bool m_isOpening;
};

#endif