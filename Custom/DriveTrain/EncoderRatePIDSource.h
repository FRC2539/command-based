#ifndef ENCODER_RATE_PID_SOURCE_H
#define ENCODER_RATE_PID_SOURCE_H

/**
 * The Encoder class, quite sensibly, only allows itself to be used as a PID
 * source for one type of value (Position or Rate) at a time. However, we need
 * to violate that assumption in order to control the rate while we move to a
 * position.
 */

#include <PIDSource.h>
class Encoder;

class EncoderRatePIDSource : public PIDSource {
public:
	EncoderRatePIDSource(Encoder* encoder);
	virtual double PIDGet();

protected:
	Encoder* m_encoder;
};

#endif
