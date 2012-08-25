/********************************************************************************
** Form generated from reading UI file 'loc.ui'
**
** Created: Fri 24. Aug 12:25:53 2012
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOC_H
#define UI_LOC_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSpinBox>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LocDialog
{
public:
    QGridLayout *gridLayout;
    QDialogButtonBox *buttonBox;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QFormLayout *formLayout_3;
    QToolButton *btnIcon;
    QGroupBox *checkName;
    QFormLayout *formLayout;
    QSpinBox *spinNameX;
    QSpinBox *spinNameY;
    QLabel *labelNameX;
    QLabel *labelNameY;
    QToolButton *btnColorName;
    QToolButton *btnFont;
    QLineEdit *lineEditName;
    QGroupBox *checkZrv;
    QFormLayout *formLayout_2;
    QLineEdit *lineEditWidth;
    QToolButton *btnColorZrv;
    QLabel *label_21;
    QCheckBox *checkZrvEnable;
    QLineEdit *lineEditAzimuth;
    QLabel *label_17;
    QLabel *label_22;
    QLineEdit *lineEditRange;
    QGroupBox *checkZrvLines;
    QFormLayout *formLayout_4;
    QDoubleSpinBox *spinLines;
    QLabel *labelWidth;
    QToolButton *btnColorLines;
    QGroupBox *groupCoords;
    QFormLayout *formLayout_5;
    QLabel *label_18;
    QLineEdit *lineEditLat;
    QLabel *label_19;
    QLineEdit *lineEditLon;
    QLabel *label_20;
    QLineEdit *lineEditHeight;
    QPushButton *btnDefault;

    void setupUi(QDialog *LocDialog)
    {
        if (LocDialog->objectName().isEmpty())
            LocDialog->setObjectName(QString::fromUtf8("LocDialog"));
        LocDialog->resize(320, 400);
        LocDialog->setLocale(QLocale(QLocale::C, QLocale::AnyCountry));
        gridLayout = new QGridLayout(LocDialog);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(0);
        gridLayout->setVerticalSpacing(6);
        buttonBox = new QDialogButtonBox(LocDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setLocale(QLocale(QLocale::C, QLocale::AnyCountry));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 27, 1, 1, 1);

        scrollArea = new QScrollArea(LocDialog);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 300, 590));
        formLayout_3 = new QFormLayout(scrollAreaWidgetContents);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        formLayout_3->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        btnIcon = new QToolButton(scrollAreaWidgetContents);
        btnIcon->setObjectName(QString::fromUtf8("btnIcon"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnIcon->sizePolicy().hasHeightForWidth());
        btnIcon->setSizePolicy(sizePolicy);
        btnIcon->setCursor(QCursor(Qt::PointingHandCursor));
        btnIcon->setLocale(QLocale(QLocale::C, QLocale::AnyCountry));
        btnIcon->setIconSize(QSize(64, 64));
        btnIcon->setPopupMode(QToolButton::DelayedPopup);
        btnIcon->setAutoRaise(true);
        btnIcon->setArrowType(Qt::NoArrow);

        formLayout_3->setWidget(0, QFormLayout::LabelRole, btnIcon);

        checkName = new QGroupBox(scrollAreaWidgetContents);
        checkName->setObjectName(QString::fromUtf8("checkName"));
        checkName->setFlat(false);
        checkName->setCheckable(true);
        formLayout = new QFormLayout(checkName);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        spinNameX = new QSpinBox(checkName);
        spinNameX->setObjectName(QString::fromUtf8("spinNameX"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(spinNameX->sizePolicy().hasHeightForWidth());
        spinNameX->setSizePolicy(sizePolicy1);
        spinNameX->setMinimum(-9999);
        spinNameX->setMaximum(9999);
        spinNameX->setSingleStep(5);

        formLayout->setWidget(3, QFormLayout::FieldRole, spinNameX);

        spinNameY = new QSpinBox(checkName);
        spinNameY->setObjectName(QString::fromUtf8("spinNameY"));
        sizePolicy1.setHeightForWidth(spinNameY->sizePolicy().hasHeightForWidth());
        spinNameY->setSizePolicy(sizePolicy1);
        spinNameY->setMinimum(-9999);
        spinNameY->setMaximum(9999);
        spinNameY->setSingleStep(5);

        formLayout->setWidget(4, QFormLayout::FieldRole, spinNameY);

        labelNameX = new QLabel(checkName);
        labelNameX->setObjectName(QString::fromUtf8("labelNameX"));
        labelNameX->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(3, QFormLayout::LabelRole, labelNameX);

        labelNameY = new QLabel(checkName);
        labelNameY->setObjectName(QString::fromUtf8("labelNameY"));
        labelNameY->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(4, QFormLayout::LabelRole, labelNameY);

        btnColorName = new QToolButton(checkName);
        btnColorName->setObjectName(QString::fromUtf8("btnColorName"));
        sizePolicy1.setHeightForWidth(btnColorName->sizePolicy().hasHeightForWidth());
        btnColorName->setSizePolicy(sizePolicy1);
        btnColorName->setAutoFillBackground(true);
        btnColorName->setLocale(QLocale(QLocale::C, QLocale::AnyCountry));
        btnColorName->setToolButtonStyle(Qt::ToolButtonTextOnly);
        btnColorName->setAutoRaise(true);

        formLayout->setWidget(6, QFormLayout::SpanningRole, btnColorName);

        btnFont = new QToolButton(checkName);
        btnFont->setObjectName(QString::fromUtf8("btnFont"));
        sizePolicy1.setHeightForWidth(btnFont->sizePolicy().hasHeightForWidth());
        btnFont->setSizePolicy(sizePolicy1);
        btnFont->setLocale(QLocale(QLocale::C, QLocale::AnyCountry));
        btnFont->setAutoRaise(true);

        formLayout->setWidget(5, QFormLayout::SpanningRole, btnFont);

        lineEditName = new QLineEdit(checkName);
        lineEditName->setObjectName(QString::fromUtf8("lineEditName"));
        sizePolicy1.setHeightForWidth(lineEditName->sizePolicy().hasHeightForWidth());
        lineEditName->setSizePolicy(sizePolicy1);
        lineEditName->setLocale(QLocale(QLocale::C, QLocale::AnyCountry));

        formLayout->setWidget(1, QFormLayout::SpanningRole, lineEditName);


        formLayout_3->setWidget(1, QFormLayout::SpanningRole, checkName);

        checkZrv = new QGroupBox(scrollAreaWidgetContents);
        checkZrv->setObjectName(QString::fromUtf8("checkZrv"));
        checkZrv->setCheckable(true);
        formLayout_2 = new QFormLayout(checkZrv);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        lineEditWidth = new QLineEdit(checkZrv);
        lineEditWidth->setObjectName(QString::fromUtf8("lineEditWidth"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, lineEditWidth);

        btnColorZrv = new QToolButton(checkZrv);
        btnColorZrv->setObjectName(QString::fromUtf8("btnColorZrv"));
        sizePolicy1.setHeightForWidth(btnColorZrv->sizePolicy().hasHeightForWidth());
        btnColorZrv->setSizePolicy(sizePolicy1);
        btnColorZrv->setAutoFillBackground(true);
        btnColorZrv->setLocale(QLocale(QLocale::C, QLocale::AnyCountry));
        btnColorZrv->setToolButtonStyle(Qt::ToolButtonTextOnly);
        btnColorZrv->setAutoRaise(true);

        formLayout_2->setWidget(7, QFormLayout::SpanningRole, btnColorZrv);

        label_21 = new QLabel(checkZrv);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_21);

        checkZrvEnable = new QCheckBox(checkZrv);
        checkZrvEnable->setObjectName(QString::fromUtf8("checkZrvEnable"));
        checkZrvEnable->setChecked(true);

        formLayout_2->setWidget(0, QFormLayout::SpanningRole, checkZrvEnable);

        lineEditAzimuth = new QLineEdit(checkZrv);
        lineEditAzimuth->setObjectName(QString::fromUtf8("lineEditAzimuth"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, lineEditAzimuth);

        label_17 = new QLabel(checkZrv);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_17);

        label_22 = new QLabel(checkZrv);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_22);

        lineEditRange = new QLineEdit(checkZrv);
        lineEditRange->setObjectName(QString::fromUtf8("lineEditRange"));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, lineEditRange);


        formLayout_3->setWidget(5, QFormLayout::SpanningRole, checkZrv);

        checkZrvLines = new QGroupBox(scrollAreaWidgetContents);
        checkZrvLines->setObjectName(QString::fromUtf8("checkZrvLines"));
        checkZrvLines->setCheckable(true);
        formLayout_4 = new QFormLayout(checkZrvLines);
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        spinLines = new QDoubleSpinBox(checkZrvLines);
        spinLines->setObjectName(QString::fromUtf8("spinLines"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(spinLines->sizePolicy().hasHeightForWidth());
        spinLines->setSizePolicy(sizePolicy2);
        spinLines->setDecimals(1);
        spinLines->setMaximum(10);
        spinLines->setSingleStep(0.1);

        formLayout_4->setWidget(1, QFormLayout::FieldRole, spinLines);

        labelWidth = new QLabel(checkZrvLines);
        labelWidth->setObjectName(QString::fromUtf8("labelWidth"));
        labelWidth->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_4->setWidget(1, QFormLayout::LabelRole, labelWidth);

        btnColorLines = new QToolButton(checkZrvLines);
        btnColorLines->setObjectName(QString::fromUtf8("btnColorLines"));
        sizePolicy1.setHeightForWidth(btnColorLines->sizePolicy().hasHeightForWidth());
        btnColorLines->setSizePolicy(sizePolicy1);
        btnColorLines->setAutoFillBackground(true);
        btnColorLines->setLocale(QLocale(QLocale::C, QLocale::AnyCountry));
        btnColorLines->setToolButtonStyle(Qt::ToolButtonTextOnly);
        btnColorLines->setAutoRaise(true);

        formLayout_4->setWidget(2, QFormLayout::SpanningRole, btnColorLines);


        formLayout_3->setWidget(6, QFormLayout::SpanningRole, checkZrvLines);

        groupCoords = new QGroupBox(scrollAreaWidgetContents);
        groupCoords->setObjectName(QString::fromUtf8("groupCoords"));
        formLayout_5 = new QFormLayout(groupCoords);
        formLayout_5->setObjectName(QString::fromUtf8("formLayout_5"));
        label_18 = new QLabel(groupCoords);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_5->setWidget(0, QFormLayout::LabelRole, label_18);

        lineEditLat = new QLineEdit(groupCoords);
        lineEditLat->setObjectName(QString::fromUtf8("lineEditLat"));

        formLayout_5->setWidget(0, QFormLayout::FieldRole, lineEditLat);

        label_19 = new QLabel(groupCoords);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_5->setWidget(1, QFormLayout::LabelRole, label_19);

        lineEditLon = new QLineEdit(groupCoords);
        lineEditLon->setObjectName(QString::fromUtf8("lineEditLon"));

        formLayout_5->setWidget(1, QFormLayout::FieldRole, lineEditLon);

        label_20 = new QLabel(groupCoords);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_5->setWidget(2, QFormLayout::LabelRole, label_20);

        lineEditHeight = new QLineEdit(groupCoords);
        lineEditHeight->setObjectName(QString::fromUtf8("lineEditHeight"));

        formLayout_5->setWidget(2, QFormLayout::FieldRole, lineEditHeight);


        formLayout_3->setWidget(0, QFormLayout::FieldRole, groupCoords);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 7, 0, 1, 2);

        btnDefault = new QPushButton(LocDialog);
        btnDefault->setObjectName(QString::fromUtf8("btnDefault"));

        gridLayout->addWidget(btnDefault, 27, 0, 1, 1);

#ifndef QT_NO_SHORTCUT
        labelNameX->setBuddy(spinNameX);
        labelNameY->setBuddy(spinNameY);
        label_21->setBuddy(lineEditWidth);
        label_17->setBuddy(lineEditAzimuth);
        label_22->setBuddy(lineEditRange);
        labelWidth->setBuddy(spinLines);
        label_18->setBuddy(lineEditLat);
        label_19->setBuddy(lineEditLon);
        label_20->setBuddy(lineEditHeight);
#endif // QT_NO_SHORTCUT

        retranslateUi(LocDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), LocDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), LocDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(LocDialog);
    } // setupUi

    void retranslateUi(QDialog *LocDialog)
    {
        LocDialog->setWindowTitle(QApplication::translate("LocDialog", "Location", 0, QApplication::UnicodeUTF8));
        btnIcon->setText(QString());
        checkName->setTitle(QApplication::translate("LocDialog", "Name", 0, QApplication::UnicodeUTF8));
        labelNameX->setText(QApplication::translate("LocDialog", "X", 0, QApplication::UnicodeUTF8));
        labelNameY->setText(QApplication::translate("LocDialog", "Y", 0, QApplication::UnicodeUTF8));
        btnColorName->setText(QApplication::translate("LocDialog", "Color", 0, QApplication::UnicodeUTF8));
        btnFont->setText(QApplication::translate("LocDialog", "Font", 0, QApplication::UnicodeUTF8));
        checkZrv->setTitle(QApplication::translate("LocDialog", "Zone", 0, QApplication::UnicodeUTF8));
        btnColorZrv->setText(QApplication::translate("LocDialog", "Color", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("LocDialog", "Width", 0, QApplication::UnicodeUTF8));
        checkZrvEnable->setText(QApplication::translate("LocDialog", "Enabled", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("LocDialog", "Azimuth", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("LocDialog", "Range", 0, QApplication::UnicodeUTF8));
        checkZrvLines->setTitle(QApplication::translate("LocDialog", "Zone contour", 0, QApplication::UnicodeUTF8));
        labelWidth->setText(QApplication::translate("LocDialog", "Width", 0, QApplication::UnicodeUTF8));
        btnColorLines->setText(QApplication::translate("LocDialog", "Color", 0, QApplication::UnicodeUTF8));
        groupCoords->setTitle(QApplication::translate("LocDialog", "Coords", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("LocDialog", "Latitude", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("LocDialog", "Longitude", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("LocDialog", "Altitude", 0, QApplication::UnicodeUTF8));
        btnDefault->setText(QApplication::translate("LocDialog", "Default", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LocDialog: public Ui_LocDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOC_H
