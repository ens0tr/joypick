#include "joypick.h"
#include "ui_joypick.h"

Joypick::Joypick(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::Joypick)
{
    joy = new QJoystick;
    data_timer = new QTimer;

    data_timer->setInterval(50);

    ui->setupUi(this);
    // Initialize joysticks
    init_joysticks();

    // If there's a joystick present, initialize axes and buttons displays
    // and start the update timer.
    if(joysavail>0)
    {
        updateSelection(0);
        connect(data_timer,SIGNAL(timeout()),this,SLOT(updateData()));
        connect(ui->avail_box,SIGNAL(currentIndexChanged(int)),this,SLOT(updateSelection(int)));
        connect(ui->sample_box,SIGNAL(toggled(bool)),this,SLOT(toggleSampling(bool)));
        if(ui->sample_box->isChecked())
            data_timer->start();
    }

}

Joypick::~Joypick()
{
    joy->~QJoystick();
    delete ui;
}

void Joypick::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

// Initialize Joystick information
// Get # of joysticks available
// Populate # of axes and buttons
void Joypick::init_joysticks()
{
    ui->avail_box->clear();

    // Find number of joysticks present
    joysavail=joy->availableJoysticks();

    // Create joysticks list
    for(int i=0;i<joysavail;i++)
    {
        joydata *tempjoy;
        tempjoy = new joydata;
        joystick.append(tempjoy);
    }

    // Populate labels depending on the number of joysticks found
    switch (joysavail)
    {
    case 0:
        ui->avail_label->setText(QString("No joysticks found"));
        ui->avail_box->setDisabled(true);
        break;
    default:
        if(joysavail==1)
            ui->avail_label->setText(QString("%1 joystick found").arg(joysavail));
        else
        ui->avail_label->setText(QString("%1 joysticks found").arg(joysavail));

        // Populate data structure for all joysticks
        for(int i=0; i<joysavail;i++)
        {
            joy->setJoystick(i);

            // Populate ComboBox
            ui->avail_box->addItem(joy->joystickName(i));

            // Axes
            joystick.at(i)->number_axes = joy->joystickNumAxes(i);

            for(unsigned int j=0; j<joystick.at(i)->number_axes;j++)
            {
                joystick.at(i)->axis.append(0);
            }

            // Buttons
            joystick.at(i)->number_btn  = joy->joystickNumButtons(i);

            for(unsigned int j=0; j<joystick.at(i)->number_btn;j++)
            {
                joystick.at(i)->button.append(false);
            }
        }

        current_joystick = 0;
        ui->num_axbtnlabel->setText(QString("%1 axes - %2 buttons").arg(joystick.at(0)->number_axes).arg(joystick.at(0)->number_btn));

        joy->setJoystick(ui->avail_box->currentIndex());

        break;
    }

}

// Lay out progress bars for axes and buttons
void Joypick::updateSelection(int index)
{
    QLayoutItem *child;
    while ((child = ui->axes_Layout->takeAt(0)) != 0) {
        delete child->widget();
        delete child;
    }

    for(int j=0;j<pbarlist.size();j++)
    {
        pbarlist.at(j)->deleteLater();
        pbarlablist.at(j)->deleteLater();

    }
    pbarlist.clear();
    pbarlablist.clear();

    while(!ui->buttons_Layout->isEmpty())
    {
        ui->buttons_Layout->removeWidget(ui->buttons_Layout->takeAt(0)->widget());
    }

    for(int j=0;j<checklist.size();j++)
    {
        checklist.at(j)->deleteLater();
    }
    checklist.clear();

    current_joystick=index;

    ui->num_axbtnlabel->setText(QString("%1 axes - %2 buttons").arg(joystick.at(index)->number_axes).arg(joystick.at(index)->number_btn));
    joy->setJoystick(ui->avail_box->currentIndex());

    for(unsigned int i=0;i<joystick.at(index)->number_axes;i++)
    {

        QLabel *templabel = new QLabel(QString("0"));
        QFont font;
        font.setPointSize(9);
        templabel->setAlignment(Qt::AlignLeft);
        templabel->setFont(font);
        templabel->setFixedWidth(50);

        QProgressBar *tempbar = new QProgressBar;
        tempbar->setOrientation(Qt::Vertical);
        tempbar->setTextVisible(false);
        tempbar->setMinimum(-32768);
        tempbar->setMaximum(32768);
        tempbar->setValue(0);
        tempbar->setAlignment(Qt::AlignRight);

        pbarlist.append(tempbar);
        pbarlablist.append(templabel);

        QVBoxLayout *pbarlayout = new QVBoxLayout;
        pbarlayout->addWidget(pbarlist.at(i));
        pbarlayout->addWidget(pbarlablist.at(i));

        ui->axes_Layout->addLayout(pbarlayout);
    }

    for(unsigned int j=0;j<joystick.at(current_joystick)->number_btn;j++)
    {
        QCheckBox *tempbox = new QCheckBox;
        tempbox->setChecked(false);
        checklist.append(tempbox);
        ui->buttons_Layout->addWidget(checklist[j]);
    }
}

void Joypick::updateData()
{
    joy->getdata();
    pollJoystick();
    for(unsigned int i=0;i<joystick.at(current_joystick)->number_axes;i++)
    {
        pbarlist[i]->setValue(joystick.at(current_joystick)->axis[i]);
        pbarlablist[i]->setText(QString("%1").arg(joystick.at(current_joystick)->axis[i]));
    }

    for(unsigned int i=0;i<joystick.at(current_joystick)->number_btn;i++)
    {
        checklist[i]->setChecked(joystick.at(current_joystick)->button[i]);
    }
//    this->update();
}

// Extracts data from QJoystick class
void Joypick::pollJoystick()
{
    joy->getdata();
    for(unsigned int i=0;i<joystick.at(current_joystick)->number_axes;i++)
    {
        joystick.at(current_joystick)->axis[i]=joy->axis[i];
    }

    for(unsigned int i=0;i<joystick.at(current_joystick)->number_btn;i++)
    {
        joystick.at(current_joystick)->button[i] = joy->buttons[i];
    }

}

// toggleSampling is offered as a function a parent widget/class can call
void Joypick::toggleSampling(bool down)
{
    if(down)
        data_timer->start();
    else
        data_timer->stop();
}

void Joypick::exttoggle(bool on)
{
    if(on)
    {
        //        data_timer->start();
        ui->sample_box->setChecked(true);
    }
    else
    {
        //        data_timer->stop();
        ui->sample_box->setChecked(false);
    }
}
