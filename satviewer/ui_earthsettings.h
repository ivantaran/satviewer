/********************************************************************************
** Form generated from reading UI file 'earthsettings.ui'
**
** Created: Fri 15. Jun 11:32:01 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EARTHSETTINGS_H
#define UI_EARTHSETTINGS_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFormLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QScrollArea>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EarthWidgetSettings
{
public:
    QVBoxLayout *verticalLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupPosition;
    QFormLayout *formLayout_2;
    QLabel *labelZoom;
    QDoubleSpinBox *spinZoom;
    QLabel *labelX;
    QDoubleSpinBox *spinX;
    QLabel *labelY;
    QDoubleSpinBox *spinY;
    QGroupBox *groupRotation;
    QFormLayout *formLayout;
    QDoubleSpinBox *spinRotX;
    QDoubleSpinBox *spinRotY;
    QDoubleSpinBox *spinRotZ;
    QLabel *labelRotX;
    QLabel *labelRotY;
    QLabel *labelRotZ;
    QLabel *labelMap;
    QToolButton *btnMapFile;
    QCheckBox *checkSun;
    QCheckBox *checkNight;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *EarthWidgetSettings)
    {
        if (EarthWidgetSettings->objectName().isEmpty())
            EarthWidgetSettings->setObjectName(QString::fromUtf8("EarthWidgetSettings"));
        EarthWidgetSettings->setEnabled(true);
        EarthWidgetSettings->resize(320, 268);
        EarthWidgetSettings->setLocale(QLocale(QLocale::C, QLocale::AnyCountry));
        verticalLayout_2 = new QVBoxLayout(EarthWidgetSettings);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        scrollArea = new QScrollArea(EarthWidgetSettings);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setFrameShadow(QFrame::Plain);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, -74, 304, 342));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupPosition = new QGroupBox(scrollAreaWidgetContents);
        groupPosition->setObjectName(QString::fromUtf8("groupPosition"));
        formLayout_2 = new QFormLayout(groupPosition);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        labelZoom = new QLabel(groupPosition);
        labelZoom->setObjectName(QString::fromUtf8("labelZoom"));
        labelZoom->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, labelZoom);

        spinZoom = new QDoubleSpinBox(groupPosition);
        spinZoom->setObjectName(QString::fromUtf8("spinZoom"));
        spinZoom->setMinimum(1);
        spinZoom->setMaximum(15);
        spinZoom->setSingleStep(0.5);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, spinZoom);

        labelX = new QLabel(groupPosition);
        labelX->setObjectName(QString::fromUtf8("labelX"));
        labelX->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, labelX);

        spinX = new QDoubleSpinBox(groupPosition);
        spinX->setObjectName(QString::fromUtf8("spinX"));
        spinX->setMaximum(5);
        spinX->setSingleStep(0.05);
        spinX->setValue(0);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, spinX);

        labelY = new QLabel(groupPosition);
        labelY->setObjectName(QString::fromUtf8("labelY"));
        labelY->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_2->setWidget(2, QFormLayout::LabelRole, labelY);

        spinY = new QDoubleSpinBox(groupPosition);
        spinY->setObjectName(QString::fromUtf8("spinY"));
        spinY->setMinimum(-5);
        spinY->setMaximum(5);
        spinY->setSingleStep(0.05);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, spinY);


        verticalLayout->addWidget(groupPosition);

        groupRotation = new QGroupBox(scrollAreaWidgetContents);
        groupRotation->setObjectName(QString::fromUtf8("groupRotation"));
        formLayout = new QFormLayout(groupRotation);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        spinRotX = new QDoubleSpinBox(groupRotation);
        spinRotX->setObjectName(QString::fromUtf8("spinRotX"));
        spinRotX->setMinimum(-180);
        spinRotX->setMaximum(180);
        spinRotX->setSingleStep(5);

        formLayout->setWidget(1, QFormLayout::FieldRole, spinRotX);

        spinRotY = new QDoubleSpinBox(groupRotation);
        spinRotY->setObjectName(QString::fromUtf8("spinRotY"));
        spinRotY->setMinimum(-180);
        spinRotY->setMaximum(180);
        spinRotY->setSingleStep(5);

        formLayout->setWidget(2, QFormLayout::FieldRole, spinRotY);

        spinRotZ = new QDoubleSpinBox(groupRotation);
        spinRotZ->setObjectName(QString::fromUtf8("spinRotZ"));
        spinRotZ->setMinimum(-180);
        spinRotZ->setMaximum(180);
        spinRotZ->setSingleStep(5);

        formLayout->setWidget(3, QFormLayout::FieldRole, spinRotZ);

        labelRotX = new QLabel(groupRotation);
        labelRotX->setObjectName(QString::fromUtf8("labelRotX"));

        formLayout->setWidget(1, QFormLayout::LabelRole, labelRotX);

        labelRotY = new QLabel(groupRotation);
        labelRotY->setObjectName(QString::fromUtf8("labelRotY"));

        formLayout->setWidget(2, QFormLayout::LabelRole, labelRotY);

        labelRotZ = new QLabel(groupRotation);
        labelRotZ->setObjectName(QString::fromUtf8("labelRotZ"));

        formLayout->setWidget(3, QFormLayout::LabelRole, labelRotZ);


        verticalLayout->addWidget(groupRotation);

        labelMap = new QLabel(scrollAreaWidgetContents);
        labelMap->setObjectName(QString::fromUtf8("labelMap"));
        labelMap->setEnabled(false);

        verticalLayout->addWidget(labelMap);

        btnMapFile = new QToolButton(scrollAreaWidgetContents);
        btnMapFile->setObjectName(QString::fromUtf8("btnMapFile"));
        btnMapFile->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnMapFile->sizePolicy().hasHeightForWidth());
        btnMapFile->setSizePolicy(sizePolicy);
        btnMapFile->setToolButtonStyle(Qt::ToolButtonTextOnly);
        btnMapFile->setAutoRaise(false);

        verticalLayout->addWidget(btnMapFile);

        checkSun = new QCheckBox(scrollAreaWidgetContents);
        checkSun->setObjectName(QString::fromUtf8("checkSun"));
        checkSun->setEnabled(false);
        checkSun->setChecked(true);

        verticalLayout->addWidget(checkSun);

        checkNight = new QCheckBox(scrollAreaWidgetContents);
        checkNight->setObjectName(QString::fromUtf8("checkNight"));
        checkNight->setEnabled(false);
        checkNight->setChecked(true);

        verticalLayout->addWidget(checkNight);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_2->addWidget(scrollArea);

#ifndef QT_NO_SHORTCUT
        labelZoom->setBuddy(spinZoom);
        labelX->setBuddy(spinX);
        labelY->setBuddy(spinY);
        labelMap->setBuddy(btnMapFile);
#endif // QT_NO_SHORTCUT

        retranslateUi(EarthWidgetSettings);

        QMetaObject::connectSlotsByName(EarthWidgetSettings);
    } // setupUi

    void retranslateUi(QWidget *EarthWidgetSettings)
    {
        EarthWidgetSettings->setWindowTitle(QApplication::translate("EarthWidgetSettings", "Earth Settings", 0, QApplication::UnicodeUTF8));
        groupPosition->setTitle(QApplication::translate("EarthWidgetSettings", "Position", 0, QApplication::UnicodeUTF8));
        labelZoom->setText(QApplication::translate("EarthWidgetSettings", "Zoom", 0, QApplication::UnicodeUTF8));
        labelX->setText(QApplication::translate("EarthWidgetSettings", "X", 0, QApplication::UnicodeUTF8));
        labelY->setText(QApplication::translate("EarthWidgetSettings", "Y", 0, QApplication::UnicodeUTF8));
        groupRotation->setTitle(QApplication::translate("EarthWidgetSettings", "Rotation", 0, QApplication::UnicodeUTF8));
        labelRotX->setText(QApplication::translate("EarthWidgetSettings", "X", 0, QApplication::UnicodeUTF8));
        labelRotY->setText(QApplication::translate("EarthWidgetSettings", "Y", 0, QApplication::UnicodeUTF8));
        labelRotZ->setText(QApplication::translate("EarthWidgetSettings", "Z", 0, QApplication::UnicodeUTF8));
        labelMap->setText(QApplication::translate("EarthWidgetSettings", "Map", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        btnMapFile->setToolTip(QApplication::translate("EarthWidgetSettings", "Map", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        btnMapFile->setText(QString());
        checkSun->setText(QApplication::translate("EarthWidgetSettings", "Sun", 0, QApplication::UnicodeUTF8));
        checkNight->setText(QApplication::translate("EarthWidgetSettings", "Night", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class EarthWidgetSettings: public Ui_EarthWidgetSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EARTHSETTINGS_H
