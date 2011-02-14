#include "qjoystick.h"

#include <QDebug>

#define POLL_INTERVAL 40

QJoystick::QJoystick()
{
    // Sure, we're only using the Joystick, but SDL doesn't work if video isn't initialised
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK);

    for(int i=0;i<MAX_AXES;i++)
    {
        axis[i]=0;
    }

}

int QJoystick::currentJoystick()
{
    return SDL_JoystickIndex(m_joystick);
}

QString QJoystick::joystickName(int js)
{
    Q_ASSERT(js < availableJoysticks());
    Q_ASSERT(js >= 0);
    return QString(SDL_JoystickName(js));
}

int QJoystick::joystickNumAxes(int js)
{
    Q_ASSERT(js < availableJoysticks());
    Q_ASSERT(js >= 0);
    return (SDL_JoystickNumAxes(m_joystick));
}

int QJoystick::joystickNumButtons(int js)
{
    Q_ASSERT(js < availableJoysticks());
    Q_ASSERT(js >= 0);
    return (SDL_JoystickNumButtons(m_joystick));
}


void QJoystick::setJoystick(int js)
{
    Q_ASSERT(js < availableJoysticks());
    Q_ASSERT(js >= 0);

    SDL_JoystickClose(m_joystick);
    m_joystick = SDL_JoystickOpen(js);
}

void QJoystick::detachJoystick()
{
    SDL_JoystickClose(m_joystick);

}

QJoystick::~QJoystick()
{
    SDL_JoystickClose(m_joystick);
    SDL_QuitSubSystem(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK);
}


int QJoystick::availableJoysticks()
{
     return SDL_NumJoysticks();
}

void QJoystick::getdata()
{
    SDL_Event event;

    while ( SDL_PollEvent(&event) )
    {
        switch(event.type)
        {
        case SDL_JOYAXISMOTION:
            axis[event.jaxis.axis] = event.jaxis.value;
            break;
        default:
            break;
        }

    }

    for(int i=0;i<SDL_JoystickNumButtons(m_joystick);i++)
    {
        buttons[i]=SDL_JoystickGetButton(m_joystick,i);
    }

}
