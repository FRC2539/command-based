#ifndef START_COMPRESSOR_COMMAND_H
#define START_COMPRESSOR_COMMAND_H

#include "Types/DefaultCommand.h"

/* Since this command is the default command of the AirCompressor subsystem,
 * it subclasses DefaultCommand. An InstantCommand would end and restart
 * on every tick, wasting processor time.
 */
class StartCompressorCommand : public DefaultCommand {

public:
	StartCompressorCommand();
	void Initialize();
};

#endif
