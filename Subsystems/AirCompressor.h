#ifndef AIR_COMPRESSOR_H
#define AIR_COMPRESSOR_H

#include "Commands/Subsystem.h"

class Compressor;


class AirCompressor: public Subsystem {
public:
	AirCompressor();
	virtual ~AirCompressor();
	void start();
	void InitDefaultCommand();

protected:
	Compressor* compressor;
};

#endif