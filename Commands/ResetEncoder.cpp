#include "ResetEncoder.h"

ResetEncoder::ResetEncoder() : InstantCommand("ResetEncoder")
{
	SetRunWhenDisabled(true);
}

void ResetEncoder::Initialize()
{
	shooter->resetEncoder();
}


