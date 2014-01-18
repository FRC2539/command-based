#include "GenericController.h"

GenericController::GenericController(UINT32 port):
    Joystick(port),
    m_inverted_y(false) {}

GenericController::GenericController(
        UINT32 port,
        UINT32 numAxisTypes,
        UINT32 numButtonTypes
    ): Joystick(
        port,
        numAxisTypes,
        numButtonTypes
    ),
    m_inverted_y(false) {}

void GenericController::setInverted(bool invert)
{
    m_inverted_y = invert;
}

float GenericController::GetY()
{
    if (m_inverted_y)
    {
        return -1 * Joystick::GetY();
    }
    else
    {
        return Joystick::GetY();
    }
}
