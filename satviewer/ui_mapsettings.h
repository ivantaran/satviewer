/********************************************************************************
** Form generated from reading UI file 'mapsettings.ui'
**
** Created: Sun 7. Oct 19:10:52 2012
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAPSETTINGS_H
#define UI_MAPSETTINGS_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFormLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MapWidgetSettings
{
public:
    QFormLayout *formLayout;
    QSpacerItem *verticalSpacer;
    QToolButton *btnMapFile;
    QLabel *labelMap;
    QComboBox *comboBoxColor;
    QToolButton *btnColor;
    QPushButton *btnFontNet;
    QDoubleSpinBox *spinZoom;
    QDoubleSpinBox *spinX;
    QDoubleSpinBox *spinY;
    QCheckBox *checkSun;
    QCheckBox *checkNight;
    QLabel *labelZoom;
    QLabel *labelX;
    QLabel *labelY;

    void setupUi(QWidget *MapWidgetSettings)
    {
        if (MapWidgetSettings->objectName().isEmpty())
            MapWidgetSettings->setObjectName(QString::fromUtf8("MapWidgetSettings"));
        MapWidgetSettings->resize(320, 268);
        MapWidgetSettings->setLocale(QLocale(QLocale::C, QLocale::AnyCountry));
        formLayout = new QFormLayout(MapWidgetSettings);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(10, QFormLayout::LabelRole, verticalSpacer);

        btnMapFile = new QToolButton(MapWidgetSettings);
        btnMapFile->setObjectName(QString::fromUtf8("btnMapFile"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnMapFile->sizePolicy().hasHeightForWidth());
        btnMapFile->setSizePolicy(sizePolicy);
        btnMapFile->setToolButtonStyle(Qt::ToolButtonTextOnly);
        btnMapFile->setAutoRaise(false);

        formLayout->setWidget(1, QFormLayout::SpanningRole, btnMapFile);

        labelMap = new QLabel(MapWidgetSettings);
        labelMap->setObjectName(QString::fromUtf8("labelMap"));

        formLayout->setWidget(0, QFormLayout::SpanningRole, labelMap);

        comboBoxColor = new QComboBox(MapWidgetSettings);
        comboBoxColor->setObjectName(QString::fromUtf8("comboBoxColor"));
        sizePolicy.setHeightForWidth(comboBoxColor->sizePolicy().hasHeightForWidth());
        comboBoxColor->setSizePolicy(sizePolicy);

        formLayout->setWidget(2, QFormLayout::SpanningRole, comboBoxColor);

        btnColor = new QToolButton(MapWidgetSettings);
        btnColor->setObjectName(QString::fromUtf8("btnColor"));
        sizePolicy.setHeightForWidth(btnColor->sizePolicy().hasHeightForWidth());
        btnColor->setSizePolicy(sizePolicy);
        btnColor->setAutoFillBackground(true);
        btnColor->setAutoRaise(true);

        formLayout->setWidget(3, QFormLayout::SpanningRole, btnColor);

        btnFontNet = new QPushButton(MapWidgetSettings);
        btnFontNet->setObjectName(QString::fromUtf8("btnFontNet"));
        sizePolicy.setHeightForWidth(btnFontNet->sizePolicy().hasHeightForWidth());
        btnFontNet->setSizePolicy(sizePolicy);

        formLayout->setWidget(4, QFormLayout::SpanningRole, btnFontNet);

        spinZoom = new QDoubleSpinBox(MapWidgetSettings);
        spinZoom->setObjectName(QString::fromUtf8("spinZoom"));
        spinZoom->setMinimum(1);

        formLayout->setWidget(5, QFormLayout::FieldRole, spinZoom);

        spinX = new QDoubleSpinBox(MapWidgetSettings);
        spinX->setObjectName(QString::fromUtf8("spinX"));
        spinX->setMinimum(-99.99);
        spinX->setMaximum(99.99);
        spinX->setSingleStep(0.05);

        formLayout->setWidget(6, QFormLayout::FieldRole, spinX);

        spinY = new QDoubleSpinBox(MapWidgetSettings);
        spinY->setObjectName(QString::fromUtf8("spinY"));
        spinY->setMinimum(-99.99);
        spinY->setMaximum(99.99);
        spinY->setSingleStep(0.05);
        spinY->setValue(0);

        formLayout->setWidget(7, QFormLayout::FieldRole, spinY);

        checkSun = new QCheckBox(MapWidgetSettings);
        checkSun->setObjectName(QString::fromUtf8("checkSun"));
        checkSun->setChecked(true);

        formLayout->setWidget(8, QFormLayout::SpanningRole, checkSun);

        checkNight = new QCheckBox(MapWidgetSettings);
        checkNight->setObjectName(QString::fromUtf8("checkNight"));
        checkNight->setChecked(true);

        formLayout->setWidget(9, QFormLayout::SpanningRole, checkNight);

        labelZoom = new QLabel(MapWidgetSettings);
        labelZoom->setObjectName(QString::fromUtf8("labelZoom"));
        labelZoom->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(5, QFormLayout::LabelRole, labelZoom);

        labelX = new QLabel(MapWidgetSettings);
        labelX->setObjectName(QString::fromUtf8("labelX"));
        labelX->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(6, QFormLayout::LabelRole, labelX);

        labelY = new QLabel(MapWidgetSettings);
        labelY->setObjectName(QString::fromUtf8("labelY"));
        labelY->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(7, QFormLayout::LabelRole, labelY);

#ifndef QT_NO_SHORTCUT
        labelMap->setBuddy(btnMapFile);
        labelZoom->setBuddy(spinZoom);
        labelX->setBuddy(spinX);
        labelY->setBuddy(spinY);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(btnMapFile, comboBoxColor);
        QWidget::setTabOrder(comboBoxColor, btnColor);
        QWidget::setTabOrder(btnColor, btnFontNet);
        QWidget::setTabOrder(btnFontNet, spinZoom);
        QWidget::setTabOrder(spinZoom, spinX);
        QWidget::setTabOrder(spinX, spinY);
        QWidget::setTabOrder(spinY, checkSun);
        QWidget::setTabOrder(checkSun, checkNight);

        retranslateUi(MapWidgetSettings);

        QMetaObject::connectSlotsByName(MapWidgetSettings);
    } // setupUi

    void retranslateUi(QWidget *MapWidgetSettings)
    {
        MapWidgetSettings->setWindowTitle(QApplication::translate("MapWidgetSettings", "Map Settings", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        btnMapFile->setToolTip(QApplication::translate("MapWidgetSettings", "Map", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        btnMapFile->setText(QString());
        labelMap->setText(QApplication::translate("MapWidgetSettings", "Map", 0, QApplication::UnicodeUTF8));
        comboBoxColor->clear();
        comboBoxColor->insertItems(0, QStringList()
         << QApplication::translate("MapWidgetSettings", "Net", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MapWidgetSettings", "Fontnet", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MapWidgetSettings", "Night", 0, QApplication::UnicodeUTF8)
        );
        btnColor->setText(QApplication::translate("MapWidgetSettings", "Color", 0, QApplication::UnicodeUTF8));
        btnFontNet->setText(QApplication::translate("MapWidgetSettings", "Netfont", 0, QApplication::UnicodeUTF8));
        checkSun->setText(QApplication::translate("MapWidgetSettings", "Sun", 0, QApplication::UnicodeUTF8));
        checkNight->setText(QApplication::translate("MapWidgetSettings", "Night", 0, QApplication::UnicodeUTF8));
        labelZoom->setText(QApplication::translate("MapWidgetSettings", "Zoom", 0, QApplication::UnicodeUTF8));
        labelX->setText(QApplication::translate("MapWidgetSettings", "X", 0, QApplication::UnicodeUTF8));
        labelY->setText(QApplication::translate("MapWidgetSettings", "Y", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MapWidgetSettings: public Ui_MapWidgetSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAPSETTINGS_H
