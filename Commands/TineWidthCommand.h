#ifndef TINE_WIDTH_COMMAND_H
#define TINE_WIDTH_COMMAND_H

#include "../Types/PIDCommand.h"

class TineWidthCommand : public PIDCommand {

public:
	TineWidthCommand(float width);
	void Initialize();
	bool IsFinished();

protected:
	bool isStalled();

	virtual double ReturnPIDInput() const;
	virtual void UsePIDOutput(double output);

	float m_lastWidth;
	unsigned int m_stalledCount;
	bool m_closing;
};

#endif