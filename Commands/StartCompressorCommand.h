#ifndef START_COMPRESSOR_COMMAND_H
#define START_COMPRESSOR_COMMAND_H

#include "../CommandBase.h"

class StartCompressorCommand : public CommandBase {

public:
	StartCompressorCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

protected:

};

#endif
