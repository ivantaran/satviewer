/********************************************************************************
** Form generated from reading UI file 'sat.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAT_H
#define UI_SAT_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SatDialog
{
public:
    QGridLayout *gridLayout;
    QDialogButtonBox *buttonBox;
    QPushButton *btnDefault;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QFormLayout *formLayout;
    QToolButton *btnIcon;
    QGroupBox *checkName;
    QFormLayout *formLayout_2;
    QLabel *labelNameX;
    QLabel *labelNameY;
    QSpinBox *spinNameY;
    QSpinBox *spinNameX;
    QLineEdit *lineEditName;
    QToolButton *btnFont;
    QToolButton *btnColorName;
    QGroupBox *groupCoords;
    QFormLayout *formLayout_3;
    QLabel *label_5;
    QLineEdit *lineEditOmg;
    QLabel *label_6;
    QLineEdit *lineEditE;
    QLabel *label_9;
    QLineEdit *lineEditI;
    QLineEdit *lineEditW;
    QLabel *label_7;
    QLineEdit *lineEditM0;
    QLabel *label_8;
    QLineEdit *lineEditN;
    QLabel *label_10;
    QLineEdit *lineEditBStar;
    QLabel *label_11;
    QLineEdit *lineEditTime;
    QLabel *label_12;
    QDateTimeEdit *dateTimeEdit;
    QGroupBox *checkZrv;
    QFormLayout *formLayout_4;
    QCheckBox *checkZrvEnable;
    QToolButton *btnColorZrv;
    QLabel *label_3;
    QDoubleSpinBox *spinZRV;
    QGroupBox *checkZrvLines;
    QFormLayout *formLayout_5;
    QLabel *labelWidth;
    QDoubleSpinBox *spinLines;
    QToolButton *btnColorLines;
    QGroupBox *checkTrack;
    QFormLayout *formLayout_6;
    QDoubleSpinBox *spinTrack;
    QLabel *labelLength;
    QToolButton *btnColorTrack;
    QComboBox *comboModel;
    QLabel *labelModel;

    void setupUi(QDialog *SatDialog)
    {
        if (SatDialog->objectName().isEmpty())
            SatDialog->setObjectName(QStringLiteral("SatDialog"));
        SatDialog->resize(320, 400);
        SatDialog->setLocale(QLocale(QLocale::C, QLocale::AnyCountry));
        gridLayout = new QGridLayout(SatDialog);
#ifndef Q_OS_MAC
        gridLayout->setSpacing(6);
#endif
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        buttonBox = new QDialogButtonBox(SatDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 8, 2, 1, 1);

        btnDefault = new QPushButton(SatDialog);
        btnDefault->setObjectName(QStringLiteral("btnDefault"));

        gridLayout->addWidget(btnDefault, 8, 0, 1, 2);

        scrollArea = new QScrollArea(SatDialog);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, -256, 300, 865));
        formLayout = new QFormLayout(scrollAreaWidgetContents);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        btnIcon = new QToolButton(scrollAreaWidgetContents);
        btnIcon->setObjectName(QStringLiteral("btnIcon"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnIcon->sizePolicy().hasHeightForWidth());
        btnIcon->setSizePolicy(sizePolicy);
        btnIcon->setCursor(QCursor(Qt::PointingHandCursor));
        btnIcon->setIconSize(QSize(64, 64));
        btnIcon->setPopupMode(QToolButton::DelayedPopup);
        btnIcon->setAutoRaise(true);
        btnIcon->setArrowType(Qt::NoArrow);

        formLayout->setWidget(0, QFormLayout::LabelRole, btnIcon);

        checkName = new QGroupBox(scrollAreaWidgetContents);
        checkName->setObjectName(QStringLiteral("checkName"));
        checkName->setCheckable(true);
        formLayout_2 = new QFormLayout(checkName);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        labelNameX = new QLabel(checkName);
        labelNameX->setObjectName(QStringLiteral("labelNameX"));
        labelNameX->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, labelNameX);

        labelNameY = new QLabel(checkName);
        labelNameY->setObjectName(QStringLiteral("labelNameY"));
        labelNameY->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_2->setWidget(3, QFormLayout::LabelRole, labelNameY);

        spinNameY = new QSpinBox(checkName);
        spinNameY->setObjectName(QStringLiteral("spinNameY"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(spinNameY->sizePolicy().hasHeightForWidth());
        spinNameY->setSizePolicy(sizePolicy1);
        spinNameY->setMinimum(-9999);
        spinNameY->setMaximum(9999);
        spinNameY->setSingleStep(5);

        formLayout_2->setWidget(3, QFormLayout::FieldRole, spinNameY);

        spinNameX = new QSpinBox(checkName);
        spinNameX->setObjectName(QStringLiteral("spinNameX"));
        sizePolicy1.setHeightForWidth(spinNameX->sizePolicy().hasHeightForWidth());
        spinNameX->setSizePolicy(sizePolicy1);
        spinNameX->setMinimum(-9999);
        spinNameX->setMaximum(9999);
        spinNameX->setSingleStep(5);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, spinNameX);

        lineEditName = new QLineEdit(checkName);
        lineEditName->setObjectName(QStringLiteral("lineEditName"));

        formLayout_2->setWidget(0, QFormLayout::SpanningRole, lineEditName);

        btnFont = new QToolButton(checkName);
        btnFont->setObjectName(QStringLiteral("btnFont"));
        sizePolicy1.setHeightForWidth(btnFont->sizePolicy().hasHeightForWidth());
        btnFont->setSizePolicy(sizePolicy1);
        btnFont->setAutoRaise(true);

        formLayout_2->setWidget(4, QFormLayout::SpanningRole, btnFont);

        btnColorName = new QToolButton(checkName);
        btnColorName->setObjectName(QStringLiteral("btnColorName"));
        sizePolicy1.setHeightForWidth(btnColorName->sizePolicy().hasHeightForWidth());
        btnColorName->setSizePolicy(sizePolicy1);
        btnColorName->setAutoFillBackground(true);
        btnColorName->setToolButtonStyle(Qt::ToolButtonTextOnly);
        btnColorName->setAutoRaise(true);

        formLayout_2->setWidget(5, QFormLayout::SpanningRole, btnColorName);


        formLayout->setWidget(2, QFormLayout::SpanningRole, checkName);

        groupCoords = new QGroupBox(scrollAreaWidgetContents);
        groupCoords->setObjectName(QStringLiteral("groupCoords"));
        groupCoords->setCheckable(false);
        formLayout_3 = new QFormLayout(groupCoords);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        label_5 = new QLabel(groupCoords);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_5);

        lineEditOmg = new QLineEdit(groupCoords);
        lineEditOmg->setObjectName(QStringLiteral("lineEditOmg"));

        formLayout_3->setWidget(1, QFormLayout::FieldRole, lineEditOmg);

        label_6 = new QLabel(groupCoords);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_6);

        lineEditE = new QLineEdit(groupCoords);
        lineEditE->setObjectName(QStringLiteral("lineEditE"));

        formLayout_3->setWidget(2, QFormLayout::FieldRole, lineEditE);

        label_9 = new QLabel(groupCoords);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_3->setWidget(2, QFormLayout::LabelRole, label_9);

        lineEditI = new QLineEdit(groupCoords);
        lineEditI->setObjectName(QStringLiteral("lineEditI"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEditI->sizePolicy().hasHeightForWidth());
        lineEditI->setSizePolicy(sizePolicy2);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, lineEditI);

        lineEditW = new QLineEdit(groupCoords);
        lineEditW->setObjectName(QStringLiteral("lineEditW"));

        formLayout_3->setWidget(3, QFormLayout::FieldRole, lineEditW);

        label_7 = new QLabel(groupCoords);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_3->setWidget(3, QFormLayout::LabelRole, label_7);

        lineEditM0 = new QLineEdit(groupCoords);
        lineEditM0->setObjectName(QStringLiteral("lineEditM0"));

        formLayout_3->setWidget(4, QFormLayout::FieldRole, lineEditM0);

        label_8 = new QLabel(groupCoords);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_3->setWidget(4, QFormLayout::LabelRole, label_8);

        lineEditN = new QLineEdit(groupCoords);
        lineEditN->setObjectName(QStringLiteral("lineEditN"));

        formLayout_3->setWidget(5, QFormLayout::FieldRole, lineEditN);

        label_10 = new QLabel(groupCoords);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_3->setWidget(5, QFormLayout::LabelRole, label_10);

        lineEditBStar = new QLineEdit(groupCoords);
        lineEditBStar->setObjectName(QStringLiteral("lineEditBStar"));

        formLayout_3->setWidget(6, QFormLayout::FieldRole, lineEditBStar);

        label_11 = new QLabel(groupCoords);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_3->setWidget(6, QFormLayout::LabelRole, label_11);

        lineEditTime = new QLineEdit(groupCoords);
        lineEditTime->setObjectName(QStringLiteral("lineEditTime"));

        formLayout_3->setWidget(7, QFormLayout::FieldRole, lineEditTime);

        label_12 = new QLabel(groupCoords);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_3->setWidget(7, QFormLayout::LabelRole, label_12);

        dateTimeEdit = new QDateTimeEdit(groupCoords);
        dateTimeEdit->setObjectName(QStringLiteral("dateTimeEdit"));
        dateTimeEdit->setFrame(true);
        dateTimeEdit->setReadOnly(true);
        dateTimeEdit->setButtonSymbols(QAbstractSpinBox::NoButtons);
        dateTimeEdit->setTimeSpec(Qt::UTC);

        formLayout_3->setWidget(8, QFormLayout::FieldRole, dateTimeEdit);


        formLayout->setWidget(3, QFormLayout::SpanningRole, groupCoords);

        checkZrv = new QGroupBox(scrollAreaWidgetContents);
        checkZrv->setObjectName(QStringLiteral("checkZrv"));
        checkZrv->setFlat(false);
        checkZrv->setCheckable(true);
        formLayout_4 = new QFormLayout(checkZrv);
        formLayout_4->setObjectName(QStringLiteral("formLayout_4"));
        checkZrvEnable = new QCheckBox(checkZrv);
        checkZrvEnable->setObjectName(QStringLiteral("checkZrvEnable"));
        checkZrvEnable->setChecked(true);

        formLayout_4->setWidget(0, QFormLayout::SpanningRole, checkZrvEnable);

        btnColorZrv = new QToolButton(checkZrv);
        btnColorZrv->setObjectName(QStringLiteral("btnColorZrv"));
        sizePolicy1.setHeightForWidth(btnColorZrv->sizePolicy().hasHeightForWidth());
        btnColorZrv->setSizePolicy(sizePolicy1);
        btnColorZrv->setAutoFillBackground(true);
        btnColorZrv->setToolButtonStyle(Qt::ToolButtonTextOnly);
        btnColorZrv->setAutoRaise(true);

        formLayout_4->setWidget(3, QFormLayout::SpanningRole, btnColorZrv);

        label_3 = new QLabel(checkZrv);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_4->setWidget(1, QFormLayout::LabelRole, label_3);

        spinZRV = new QDoubleSpinBox(checkZrv);
        spinZRV->setObjectName(QStringLiteral("spinZRV"));
        sizePolicy2.setHeightForWidth(spinZRV->sizePolicy().hasHeightForWidth());
        spinZRV->setSizePolicy(sizePolicy2);
        spinZRV->setDecimals(3);
        spinZRV->setMaximum(90);
        spinZRV->setSingleStep(0.5);
        spinZRV->setValue(0);

        formLayout_4->setWidget(1, QFormLayout::FieldRole, spinZRV);


        formLayout->setWidget(4, QFormLayout::SpanningRole, checkZrv);

        checkZrvLines = new QGroupBox(scrollAreaWidgetContents);
        checkZrvLines->setObjectName(QStringLiteral("checkZrvLines"));
        checkZrvLines->setCheckable(true);
        formLayout_5 = new QFormLayout(checkZrvLines);
        formLayout_5->setObjectName(QStringLiteral("formLayout_5"));
        labelWidth = new QLabel(checkZrvLines);
        labelWidth->setObjectName(QStringLiteral("labelWidth"));
        labelWidth->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_5->setWidget(0, QFormLayout::LabelRole, labelWidth);

        spinLines = new QDoubleSpinBox(checkZrvLines);
        spinLines->setObjectName(QStringLiteral("spinLines"));
        sizePolicy2.setHeightForWidth(spinLines->sizePolicy().hasHeightForWidth());
        spinLines->setSizePolicy(sizePolicy2);
        spinLines->setDecimals(1);
        spinLines->setMaximum(10);
        spinLines->setSingleStep(0.1);

        formLayout_5->setWidget(0, QFormLayout::FieldRole, spinLines);

        btnColorLines = new QToolButton(checkZrvLines);
        btnColorLines->setObjectName(QStringLiteral("btnColorLines"));
        sizePolicy1.setHeightForWidth(btnColorLines->sizePolicy().hasHeightForWidth());
        btnColorLines->setSizePolicy(sizePolicy1);
        btnColorLines->setAutoFillBackground(true);
        btnColorLines->setToolButtonStyle(Qt::ToolButtonTextOnly);
        btnColorLines->setAutoRaise(true);

        formLayout_5->setWidget(1, QFormLayout::SpanningRole, btnColorLines);


        formLayout->setWidget(5, QFormLayout::SpanningRole, checkZrvLines);

        checkTrack = new QGroupBox(scrollAreaWidgetContents);
        checkTrack->setObjectName(QStringLiteral("checkTrack"));
        checkTrack->setCheckable(true);
        formLayout_6 = new QFormLayout(checkTrack);
        formLayout_6->setObjectName(QStringLiteral("formLayout_6"));
        spinTrack = new QDoubleSpinBox(checkTrack);
        spinTrack->setObjectName(QStringLiteral("spinTrack"));
        sizePolicy2.setHeightForWidth(spinTrack->sizePolicy().hasHeightForWidth());
        spinTrack->setSizePolicy(sizePolicy2);
        spinTrack->setSingleStep(0.5);
        spinTrack->setValue(0.5);

        formLayout_6->setWidget(0, QFormLayout::FieldRole, spinTrack);

        labelLength = new QLabel(checkTrack);
        labelLength->setObjectName(QStringLiteral("labelLength"));
        labelLength->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_6->setWidget(0, QFormLayout::LabelRole, labelLength);

        btnColorTrack = new QToolButton(checkTrack);
        btnColorTrack->setObjectName(QStringLiteral("btnColorTrack"));
        sizePolicy1.setHeightForWidth(btnColorTrack->sizePolicy().hasHeightForWidth());
        btnColorTrack->setSizePolicy(sizePolicy1);
        btnColorTrack->setAutoFillBackground(true);
        btnColorTrack->setToolButtonStyle(Qt::ToolButtonTextOnly);
        btnColorTrack->setAutoRaise(true);

        formLayout_6->setWidget(1, QFormLayout::SpanningRole, btnColorTrack);


        formLayout->setWidget(6, QFormLayout::SpanningRole, checkTrack);

        comboModel = new QComboBox(scrollAreaWidgetContents);
        comboModel->setObjectName(QStringLiteral("comboModel"));

        formLayout->setWidget(8, QFormLayout::SpanningRole, comboModel);

        labelModel = new QLabel(scrollAreaWidgetContents);
        labelModel->setObjectName(QStringLiteral("labelModel"));

        formLayout->setWidget(7, QFormLayout::LabelRole, labelModel);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 3);

#ifndef QT_NO_SHORTCUT
        labelNameX->setBuddy(spinNameX);
        labelNameY->setBuddy(spinNameY);
        label_5->setBuddy(lineEditI);
        label_6->setBuddy(lineEditOmg);
        label_9->setBuddy(lineEditE);
        label_7->setBuddy(lineEditW);
        label_8->setBuddy(lineEditM0);
        label_10->setBuddy(lineEditN);
        label_11->setBuddy(lineEditBStar);
        label_12->setBuddy(lineEditTime);
        label_3->setBuddy(spinZRV);
        labelWidth->setBuddy(spinLines);
        labelLength->setBuddy(spinTrack);
        labelModel->setBuddy(comboModel);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(scrollArea, btnIcon);
        QWidget::setTabOrder(btnIcon, checkName);
        QWidget::setTabOrder(checkName, lineEditName);
        QWidget::setTabOrder(lineEditName, spinNameX);
        QWidget::setTabOrder(spinNameX, spinNameY);
        QWidget::setTabOrder(spinNameY, btnFont);
        QWidget::setTabOrder(btnFont, btnColorName);
        QWidget::setTabOrder(btnColorName, checkZrv);
        QWidget::setTabOrder(checkZrv, checkZrvEnable);
        QWidget::setTabOrder(checkZrvEnable, spinZRV);
        QWidget::setTabOrder(spinZRV, btnColorZrv);
        QWidget::setTabOrder(btnColorZrv, checkZrvLines);
        QWidget::setTabOrder(checkZrvLines, spinLines);
        QWidget::setTabOrder(spinLines, btnColorLines);
        QWidget::setTabOrder(btnColorLines, checkTrack);
        QWidget::setTabOrder(checkTrack, spinTrack);
        QWidget::setTabOrder(spinTrack, btnColorTrack);
        QWidget::setTabOrder(btnColorTrack, btnDefault);
        QWidget::setTabOrder(btnDefault, buttonBox);

        retranslateUi(SatDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), SatDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SatDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(SatDialog);
    } // setupUi

    void retranslateUi(QDialog *SatDialog)
    {
        SatDialog->setWindowTitle(QApplication::translate("SatDialog", "Satellite", 0));
        btnDefault->setText(QApplication::translate("SatDialog", "Default", 0));
        btnIcon->setText(QString());
        checkName->setTitle(QApplication::translate("SatDialog", "Name", 0));
        labelNameX->setText(QApplication::translate("SatDialog", "X", 0));
        labelNameY->setText(QApplication::translate("SatDialog", "Y", 0));
        btnFont->setText(QApplication::translate("SatDialog", "Font", 0));
        btnColorName->setText(QApplication::translate("SatDialog", "Color", 0));
        groupCoords->setTitle(QApplication::translate("SatDialog", "Coords", 0));
        label_5->setText(QApplication::translate("SatDialog", "Inclination", 0));
        label_6->setText(QApplication::translate("SatDialog", "Ascending node", 0));
        label_9->setText(QApplication::translate("SatDialog", "Eccentricity", 0));
        label_7->setText(QApplication::translate("SatDialog", "Arg. perigee lat.", 0));
        label_8->setText(QApplication::translate("SatDialog", "Mean anomaly", 0));
        label_10->setText(QApplication::translate("SatDialog", "Mean motion", 0));
        label_11->setText(QApplication::translate("SatDialog", "Ballistic coeff.", 0));
        label_12->setText(QApplication::translate("SatDialog", "Timestamp", 0));
        dateTimeEdit->setDisplayFormat(QApplication::translate("SatDialog", "dd.MM.yyyy H:mm:ss.zzz", 0));
        checkZrv->setTitle(QApplication::translate("SatDialog", "Zone", 0));
        checkZrvEnable->setText(QApplication::translate("SatDialog", "Enabled", 0));
        btnColorZrv->setText(QApplication::translate("SatDialog", "Color", 0));
        label_3->setText(QApplication::translate("SatDialog", "Width", 0));
        checkZrvLines->setTitle(QApplication::translate("SatDialog", "Zone contour", 0));
        labelWidth->setText(QApplication::translate("SatDialog", "Width", 0));
        btnColorLines->setText(QApplication::translate("SatDialog", "Color", 0));
        checkTrack->setTitle(QApplication::translate("SatDialog", "Track", 0));
        labelLength->setText(QApplication::translate("SatDialog", "Length", 0));
        btnColorTrack->setText(QApplication::translate("SatDialog", "Color", 0));
        labelModel->setText(QApplication::translate("SatDialog", "Model", 0));
    } // retranslateUi

};

namespace Ui {
    class SatDialog: public Ui_SatDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAT_H
