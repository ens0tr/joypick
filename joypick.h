#ifndef JOYPICK_H
#define JOYPICK_H

#include <QWidget>
#include <QProgressBar>
#include <QRadioButton>
#include <QVBoxLayout>
#include <QTimer>
#include <QLabel>
#include <QCheckBox>
#include <QList>
#include "qjoystick.h"
#define MAX_JOYSTICK 32 // UP TO 32 JOYSTICKS

namespace Ui {
    class Joypick;
}

// Joystick indicators:
// Axes
class QProgressBar;
// Buttons
class QCheckBox;
class QLabel;

class Joypick : public QWidget {
    Q_OBJECT
public:
    Joypick(QWidget *parent = 0);
    ~Joypick();

    // Structure created for each joystick encountered
    struct joydata{
        unsigned int number_axes;
        unsigned int number_btn;
        QList<int> axis;
        QList<bool> button;
    };

    // Available joystick count. Only set at initialization
    int joysavail;

    // List of joystick data
    QList<joydata*> joystick;

    // current_joystick is dynamic, set by the user selection
    int current_joystick;

    void pollJoystick();
    void exttoggle(bool);

protected:
    void changeEvent(QEvent *e);

private:
    Ui::Joypick *ui;
QJoystick *joy;
    void init_joysticks();
    QTimer *data_timer;
    QList<QProgressBar*> pbarlist;
    //QProgressBar *pbararray[MAX_AXES];
   QList<QLabel*> pbarlablist;
   QList<QCheckBox*> checklist;
   //QLabel *pbarlabel[MAX_AXES];
 //   QCheckBox *checkarray[MAX_BUTTONS];
  //  QLabel *checklabel[MAX_BUTTONS];
   // QVBoxLayout *pbarlayout[MAX_AXES];

private slots:
    void updateSelection(int index);
    void updateData();
    void toggleSampling(bool down);

};

#endif // JOYPICK_H
