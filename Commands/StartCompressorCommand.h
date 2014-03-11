#ifndef START_COMPRESSOR_COMMAND_H
#define START_COMPRESSOR_COMMAND_H

#include "Types/InstantCommand.h"

class StartCompressorCommand : public InstantCommand {

public:
	StartCompressorCommand();
	void Initialize();
};

#endif
