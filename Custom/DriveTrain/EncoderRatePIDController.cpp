#include "EncoderRatePIDController.h"

#include <PIDSource.h>
#include <PIDOutput.h>

EncoderRatePIDController::EncoderRatePIDController(
	float p, float i, float d, float f, PIDSource* source, PIDOutput* output
): PIDController(p, i, d, f, source, output) {}

void EncoderRatePIDController::StartLiveWindowMode() {}
