#include "RatePIDController.h"

#include <PIDSource.h>
#include <PIDOutput.h>
#include <HAL/cpp/Synchronized.hpp>

RatePIDController::RatePIDController(
	float p, float i, float d, float f, PIDSource* source, PIDOutput* output
): SanePIDController(p, i, d, f, source, output) {}

/* Overrides the default calculate to pass along the current value as a feed
 * forward value.
 */
void RatePIDController::Calculate()
{
	bool enabled;
	PIDSource *pidInput;
	PIDOutput *pidOutput;

	CRITICAL_REGION(m_semaphore)
	{
		pidInput = m_pidInput;
		pidOutput = m_pidOutput;
		enabled = m_enabled;
		pidInput = m_pidInput;
	}
	END_REGION;

	if (pidInput == NULL) return;
	if (pidOutput == NULL) return;

	if (enabled)
	{
		{
			Synchronized sync(m_semaphore);
			float input = pidInput->PIDGet();
			float result;
			PIDOutput *pidOutput;

			m_error = m_setpoint - input;
			if (m_continuous)
			{
				if (fabs(m_error) > (m_maximumInput - m_minimumInput) / 2)
				{
					if (m_error > 0)
					{
						m_error = m_error - m_maximumInput + m_minimumInput;
					}
					else
					{
						m_error = m_error + m_maximumInput - m_minimumInput;
					}
				}
			}

			if(m_I != 0)
			{
				double potentialIGain = (m_totalError + m_error) * m_I;
				if (potentialIGain < m_maximumOutput)
				{
					if (potentialIGain > m_minimumOutput)
						m_totalError += m_error;
					else
						m_totalError = m_minimumOutput / m_I;
				}
				else
				{
					m_totalError = m_maximumOutput / m_I;
				}
			}

			m_result = m_P * m_error + m_I * m_totalError + m_D * (m_error - m_prevError) + m_result;
			m_prevError = m_error;

			if (m_result > m_maximumOutput) m_result = m_maximumOutput;
			else if (m_result < m_minimumOutput) m_result = m_minimumOutput;

			pidOutput = m_pidOutput;
			result = m_result;

			pidOutput->PIDWrite(result);
		}
	}
}

void RatePIDController::StartLiveWindowMode() {}
