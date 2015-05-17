#ifndef POV_BUTTON_H
#define POV_BUTTON_H

#include <GenericHID.h>
#include <Buttons/Button.h>

class POVButton : public Button
{
public:
	POVButton(GenericHID *joystick, int angle, bool mutuallyExclusive=false);
	virtual ~POVButton() {}

	virtual bool Get();

private:
	GenericHID *m_joystick;
	int m_angle_less;
	int m_angle;
	int m_angle_more;
	bool m_mutuallyExclusive;
};

#endif
