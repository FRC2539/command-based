#ifndef AIR_COMPRESSOR_H
#define AIR_COMPRESSOR_H

#include "Commands/Subsystem.h"
#include <Compressor.h>


class AirCompressor: public Subsystem {
public:
	AirCompressor();
	virtual ~AirCompressor();

protected:
	Compressor* compressor;
};

#endif