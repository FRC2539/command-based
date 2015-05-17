#include "POVButton.h"

POVButton::POVButton(GenericHID *joystick, int angle, bool mutuallyExclusive) :
	m_joystick(joystick),
	m_angle(angle),
	m_mutuallyExclusive(mutuallyExclusive)
{
	m_angle_more = (angle + 30) % 360;
	m_angle_less = angle - 30;
	if (m_angle_less < 0)
	{
		m_angle_less += 360;
	}
}

bool POVButton::Get()
{
	int angle = m_joystick->GetPOV(0);
	
	bool pressed = (angle == m_angle);

	if (m_mutuallyExclusive || pressed)
	{
		return pressed;
	}

	return (angle == m_angle_less || angle == m_angle_more);
}
