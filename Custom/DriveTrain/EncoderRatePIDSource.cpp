#include "EncoderRatePIDSource.h"

#include <Encoder.h>

EncoderRatePIDSource::EncoderRatePIDSource(Encoder* encoder) :
	m_encoder(encoder) {}

double EncoderRatePIDSource::PIDGet()
{
	return m_encoder->GetRate();
}

