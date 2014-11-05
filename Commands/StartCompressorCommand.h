#ifndef START_COMPRESSOR_COMMAND_H
#define START_COMPRESSOR_COMMAND_H

#include "Types/DefaultCommand.h"

/* Even though this command could be an InstantCommand, because it is used as
 * the default command for the AirCompressor subsystem, it is made a
 * DefaultCommand. An InstantCommand would be restarted constantly.
 */

class StartCompressorCommand : public DefaultCommand {

public:
	StartCompressorCommand();
	void Initialize();
};

#endif
