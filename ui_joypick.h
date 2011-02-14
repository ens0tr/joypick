/********************************************************************************
** Form generated from reading UI file 'joypick.ui'
**
** Created: Sun Feb 13 19:55:21 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JOYPICK_H
#define UI_JOYPICK_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Joypick
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *avail_label;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QComboBox *avail_box;
    QSpacerItem *horizontalSpacer;
    QCheckBox *sample_box;
    QSpacerItem *horizontalSpacer_3;
    QLabel *num_axbtnlabel;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *axes_Layout;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *buttons_Layout;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *Joypick)
    {
        if (Joypick->objectName().isEmpty())
            Joypick->setObjectName(QString::fromUtf8("Joypick"));
        Joypick->resize(460, 357);
        Joypick->setAutoFillBackground(true);
        verticalLayout = new QVBoxLayout(Joypick);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        avail_label = new QLabel(Joypick);
        avail_label->setObjectName(QString::fromUtf8("avail_label"));
        avail_label->setMinimumSize(QSize(0, 50));
        avail_label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(avail_label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        avail_box = new QComboBox(Joypick);
        avail_box->setObjectName(QString::fromUtf8("avail_box"));
        avail_box->setMinimumSize(QSize(250, 0));

        horizontalLayout->addWidget(avail_box);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        sample_box = new QCheckBox(Joypick);
        sample_box->setObjectName(QString::fromUtf8("sample_box"));

        horizontalLayout->addWidget(sample_box);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout);

        num_axbtnlabel = new QLabel(Joypick);
        num_axbtnlabel->setObjectName(QString::fromUtf8("num_axbtnlabel"));
        num_axbtnlabel->setMinimumSize(QSize(100, 50));
        num_axbtnlabel->setBaseSize(QSize(100, 50));
        num_axbtnlabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(num_axbtnlabel);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout->addItem(verticalSpacer_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        axes_Layout = new QHBoxLayout();
        axes_Layout->setSpacing(10);
        axes_Layout->setObjectName(QString::fromUtf8("axes_Layout"));
        axes_Layout->setSizeConstraint(QLayout::SetDefaultConstraint);

        horizontalLayout_2->addLayout(axes_Layout);

        horizontalSpacer_5 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        buttons_Layout = new QHBoxLayout();
        buttons_Layout->setSpacing(6);
        buttons_Layout->setObjectName(QString::fromUtf8("buttons_Layout"));

        horizontalLayout_3->addLayout(buttons_Layout);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout->addItem(verticalSpacer_2);


        retranslateUi(Joypick);

        QMetaObject::connectSlotsByName(Joypick);
    } // setupUi

    void retranslateUi(QWidget *Joypick)
    {
        Joypick->setWindowTitle(QApplication::translate("Joypick", "Pick-a-Joystick", 0, QApplication::UnicodeUTF8));
        avail_label->setText(QApplication::translate("Joypick", "Joysticks available", 0, QApplication::UnicodeUTF8));
        sample_box->setText(QApplication::translate("Joypick", "Continuous sampling", 0, QApplication::UnicodeUTF8));
        num_axbtnlabel->setText(QApplication::translate("Joypick", "Axis", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Joypick: public Ui_Joypick {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JOYPICK_H
