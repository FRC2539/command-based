#ifndef GENERIC_CONTROLLER_H
#define GENERIC_CONTROLLER_H

#include "Joystick.h"

class GenericController : public Joystick {

public:
    explicit GenericController(UINT32 port);
    GenericController(UINT32 port, UINT32 numAxisTypes, UINT32 numButtonTypes);

    virtual void setInverted(bool invert);
    virtual float GetY();

protected:
    bool m_inverted_y;
};

#endif
