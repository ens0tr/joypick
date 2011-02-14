#ifndef QJOYSTICK_H
#define QJOYSTICK_H

#define MAX_AXES 32
#define MAX_BUTTONS 64

#include <QObject>
#include <QString>
#include <vector>

#include "SDL/SDL.h"

class QJoystick : public QObject
{
    Q_OBJECT
public:
    QJoystick();
    ~QJoystick();
    int availableJoysticks();
    int currentJoystick();
    QString joystickName(int id);
    int joystickNumAxes(int id);
    int joystickNumButtons(int id);
    float axis[MAX_AXES];
    unsigned int buttons[MAX_BUTTONS];
    void getdata();

            public slots:
    void setJoystick(int jsNumber);
    void detachJoystick();


signals:
    void axisEvent(int axis, int value);
    void buttonPress(int button);
    void buttonRelease(int button);
private:
    SDL_Joystick* m_joystick;
};

#endif // QJOYSTICK_H
