/********************************************************************************
** Form generated from reading UI file 'earthsettings.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EARTHSETTINGS_H
#define UI_EARTHSETTINGS_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

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
            EarthWidgetSettings->setObjectName(QStringLiteral("EarthWidgetSettings"));
        EarthWidgetSettings->setEnabled(true);
        EarthWidgetSettings->resize(320, 268);
        EarthWidgetSettings->setLocale(QLocale(QLocale::C, QLocale::AnyCountry));
        verticalLayout_2 = new QVBoxLayout(EarthWidgetSettings);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        scrollArea = new QScrollArea(EarthWidgetSettings);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setFrameShadow(QFrame::Plain);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, -74, 304, 342));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupPosition = new QGroupBox(scrollAreaWidgetContents);
        groupPosition->setObjectName(QStringLiteral("groupPosition"));
        formLayout_2 = new QFormLayout(groupPosition);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        labelZoom = new QLabel(groupPosition);
        labelZoom->setObjectName(QStringLiteral("labelZoom"));
        labelZoom->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, labelZoom);

        spinZoom = new QDoubleSpinBox(groupPosition);
        spinZoom->setObjectName(QStringLiteral("spinZoom"));
        spinZoom->setMinimum(1);
        spinZoom->setMaximum(15);
        spinZoom->setSingleStep(0.5);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, spinZoom);

        labelX = new QLabel(groupPosition);
        labelX->setObjectName(QStringLiteral("labelX"));
        labelX->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, labelX);

        spinX = new QDoubleSpinBox(groupPosition);
        spinX->setObjectName(QStringLiteral("spinX"));
        spinX->setMaximum(5);
        spinX->setSingleStep(0.05);
        spinX->setValue(0);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, spinX);

        labelY = new QLabel(groupPosition);
        labelY->setObjectName(QStringLiteral("labelY"));
        labelY->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_2->setWidget(2, QFormLayout::LabelRole, labelY);

        spinY = new QDoubleSpinBox(groupPosition);
        spinY->setObjectName(QStringLiteral("spinY"));
        spinY->setMinimum(-5);
        spinY->setMaximum(5);
        spinY->setSingleStep(0.05);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, spinY);


        verticalLayout->addWidget(groupPosition);

        groupRotation = new QGroupBox(scrollAreaWidgetContents);
        groupRotation->setObjectName(QStringLiteral("groupRotation"));
        formLayout = new QFormLayout(groupRotation);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        spinRotX = new QDoubleSpinBox(groupRotation);
        spinRotX->setObjectName(QStringLiteral("spinRotX"));
        spinRotX->setMinimum(-180);
        spinRotX->setMaximum(180);
        spinRotX->setSingleStep(5);

        formLayout->setWidget(1, QFormLayout::FieldRole, spinRotX);

        spinRotY = new QDoubleSpinBox(groupRotation);
        spinRotY->setObjectName(QStringLiteral("spinRotY"));
        spinRotY->setMinimum(-180);
        spinRotY->setMaximum(180);
        spinRotY->setSingleStep(5);

        formLayout->setWidget(2, QFormLayout::FieldRole, spinRotY);

        spinRotZ = new QDoubleSpinBox(groupRotation);
        spinRotZ->setObjectName(QStringLiteral("spinRotZ"));
        spinRotZ->setMinimum(-180);
        spinRotZ->setMaximum(180);
        spinRotZ->setSingleStep(5);

        formLayout->setWidget(3, QFormLayout::FieldRole, spinRotZ);

        labelRotX = new QLabel(groupRotation);
        labelRotX->setObjectName(QStringLiteral("labelRotX"));

        formLayout->setWidget(1, QFormLayout::LabelRole, labelRotX);

        labelRotY = new QLabel(groupRotation);
        labelRotY->setObjectName(QStringLiteral("labelRotY"));

        formLayout->setWidget(2, QFormLayout::LabelRole, labelRotY);

        labelRotZ = new QLabel(groupRotation);
        labelRotZ->setObjectName(QStringLiteral("labelRotZ"));

        formLayout->setWidget(3, QFormLayout::LabelRole, labelRotZ);


        verticalLayout->addWidget(groupRotation);

        labelMap = new QLabel(scrollAreaWidgetContents);
        labelMap->setObjectName(QStringLiteral("labelMap"));
        labelMap->setEnabled(false);

        verticalLayout->addWidget(labelMap);

        btnMapFile = new QToolButton(scrollAreaWidgetContents);
        btnMapFile->setObjectName(QStringLiteral("btnMapFile"));
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
        checkSun->setObjectName(QStringLiteral("checkSun"));
        checkSun->setEnabled(false);
        checkSun->setChecked(true);

        verticalLayout->addWidget(checkSun);

        checkNight = new QCheckBox(scrollAreaWidgetContents);
        checkNight->setObjectName(QStringLiteral("checkNight"));
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
        EarthWidgetSettings->setWindowTitle(QApplication::translate("EarthWidgetSettings", "Earth Settings", 0));
        groupPosition->setTitle(QApplication::translate("EarthWidgetSettings", "Position", 0));
        labelZoom->setText(QApplication::translate("EarthWidgetSettings", "Zoom", 0));
        labelX->setText(QApplication::translate("EarthWidgetSettings", "X", 0));
        labelY->setText(QApplication::translate("EarthWidgetSettings", "Y", 0));
        groupRotation->setTitle(QApplication::translate("EarthWidgetSettings", "Rotation", 0));
        labelRotX->setText(QApplication::translate("EarthWidgetSettings", "X", 0));
        labelRotY->setText(QApplication::translate("EarthWidgetSettings", "Y", 0));
        labelRotZ->setText(QApplication::translate("EarthWidgetSettings", "Z", 0));
        labelMap->setText(QApplication::translate("EarthWidgetSettings", "Map", 0));
#ifndef QT_NO_TOOLTIP
        btnMapFile->setToolTip(QApplication::translate("EarthWidgetSettings", "Map", 0));
#endif // QT_NO_TOOLTIP
        btnMapFile->setText(QString());
        checkSun->setText(QApplication::translate("EarthWidgetSettings", "Sun", 0));
        checkNight->setText(QApplication::translate("EarthWidgetSettings", "Night", 0));
    } // retranslateUi

};

namespace Ui {
    class EarthWidgetSettings: public Ui_EarthWidgetSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EARTHSETTINGS_H
