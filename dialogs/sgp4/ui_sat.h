/********************************************************************************
** Form generated from reading UI file 'sat.ui'
**
** Created: Sun 7. Oct 19:23:25 2012
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAT_H
#define UI_SAT_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDateTimeEdit>
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
            SatDialog->setObjectName(QString::fromUtf8("SatDialog"));
        SatDialog->resize(320, 400);
        SatDialog->setLocale(QLocale(QLocale::C, QLocale::AnyCountry));
        gridLayout = new QGridLayout(SatDialog);
#ifndef Q_OS_MAC
        gridLayout->setSpacing(6);
#endif
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        buttonBox = new QDialogButtonBox(SatDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 8, 2, 1, 1);

        btnDefault = new QPushButton(SatDialog);
        btnDefault->setObjectName(QString::fromUtf8("btnDefault"));

        gridLayout->addWidget(btnDefault, 8, 0, 1, 2);

        scrollArea = new QScrollArea(SatDialog);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, -256, 300, 865));
        formLayout = new QFormLayout(scrollAreaWidgetContents);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        btnIcon = new QToolButton(scrollAreaWidgetContents);
        btnIcon->setObjectName(QString::fromUtf8("btnIcon"));
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
        checkName->setObjectName(QString::fromUtf8("checkName"));
        checkName->setCheckable(true);
        formLayout_2 = new QFormLayout(checkName);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        labelNameX = new QLabel(checkName);
        labelNameX->setObjectName(QString::fromUtf8("labelNameX"));
        labelNameX->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, labelNameX);

        labelNameY = new QLabel(checkName);
        labelNameY->setObjectName(QString::fromUtf8("labelNameY"));
        labelNameY->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_2->setWidget(3, QFormLayout::LabelRole, labelNameY);

        spinNameY = new QSpinBox(checkName);
        spinNameY->setObjectName(QString::fromUtf8("spinNameY"));
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
        spinNameX->setObjectName(QString::fromUtf8("spinNameX"));
        sizePolicy1.setHeightForWidth(spinNameX->sizePolicy().hasHeightForWidth());
        spinNameX->setSizePolicy(sizePolicy1);
        spinNameX->setMinimum(-9999);
        spinNameX->setMaximum(9999);
        spinNameX->setSingleStep(5);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, spinNameX);

        lineEditName = new QLineEdit(checkName);
        lineEditName->setObjectName(QString::fromUtf8("lineEditName"));

        formLayout_2->setWidget(0, QFormLayout::SpanningRole, lineEditName);

        btnFont = new QToolButton(checkName);
        btnFont->setObjectName(QString::fromUtf8("btnFont"));
        sizePolicy1.setHeightForWidth(btnFont->sizePolicy().hasHeightForWidth());
        btnFont->setSizePolicy(sizePolicy1);
        btnFont->setAutoRaise(true);

        formLayout_2->setWidget(4, QFormLayout::SpanningRole, btnFont);

        btnColorName = new QToolButton(checkName);
        btnColorName->setObjectName(QString::fromUtf8("btnColorName"));
        sizePolicy1.setHeightForWidth(btnColorName->sizePolicy().hasHeightForWidth());
        btnColorName->setSizePolicy(sizePolicy1);
        btnColorName->setAutoFillBackground(true);
        btnColorName->setToolButtonStyle(Qt::ToolButtonTextOnly);
        btnColorName->setAutoRaise(true);

        formLayout_2->setWidget(5, QFormLayout::SpanningRole, btnColorName);


        formLayout->setWidget(2, QFormLayout::SpanningRole, checkName);

        groupCoords = new QGroupBox(scrollAreaWidgetContents);
        groupCoords->setObjectName(QString::fromUtf8("groupCoords"));
        groupCoords->setCheckable(false);
        formLayout_3 = new QFormLayout(groupCoords);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        label_5 = new QLabel(groupCoords);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_5);

        lineEditOmg = new QLineEdit(groupCoords);
        lineEditOmg->setObjectName(QString::fromUtf8("lineEditOmg"));

        formLayout_3->setWidget(1, QFormLayout::FieldRole, lineEditOmg);

        label_6 = new QLabel(groupCoords);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_6);

        lineEditE = new QLineEdit(groupCoords);
        lineEditE->setObjectName(QString::fromUtf8("lineEditE"));

        formLayout_3->setWidget(2, QFormLayout::FieldRole, lineEditE);

        label_9 = new QLabel(groupCoords);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_3->setWidget(2, QFormLayout::LabelRole, label_9);

        lineEditI = new QLineEdit(groupCoords);
        lineEditI->setObjectName(QString::fromUtf8("lineEditI"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEditI->sizePolicy().hasHeightForWidth());
        lineEditI->setSizePolicy(sizePolicy2);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, lineEditI);

        lineEditW = new QLineEdit(groupCoords);
        lineEditW->setObjectName(QString::fromUtf8("lineEditW"));

        formLayout_3->setWidget(3, QFormLayout::FieldRole, lineEditW);

        label_7 = new QLabel(groupCoords);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_3->setWidget(3, QFormLayout::LabelRole, label_7);

        lineEditM0 = new QLineEdit(groupCoords);
        lineEditM0->setObjectName(QString::fromUtf8("lineEditM0"));

        formLayout_3->setWidget(4, QFormLayout::FieldRole, lineEditM0);

        label_8 = new QLabel(groupCoords);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_3->setWidget(4, QFormLayout::LabelRole, label_8);

        lineEditN = new QLineEdit(groupCoords);
        lineEditN->setObjectName(QString::fromUtf8("lineEditN"));

        formLayout_3->setWidget(5, QFormLayout::FieldRole, lineEditN);

        label_10 = new QLabel(groupCoords);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_3->setWidget(5, QFormLayout::LabelRole, label_10);

        lineEditBStar = new QLineEdit(groupCoords);
        lineEditBStar->setObjectName(QString::fromUtf8("lineEditBStar"));

        formLayout_3->setWidget(6, QFormLayout::FieldRole, lineEditBStar);

        label_11 = new QLabel(groupCoords);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_3->setWidget(6, QFormLayout::LabelRole, label_11);

        lineEditTime = new QLineEdit(groupCoords);
        lineEditTime->setObjectName(QString::fromUtf8("lineEditTime"));

        formLayout_3->setWidget(7, QFormLayout::FieldRole, lineEditTime);

        label_12 = new QLabel(groupCoords);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_3->setWidget(7, QFormLayout::LabelRole, label_12);

        dateTimeEdit = new QDateTimeEdit(groupCoords);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        dateTimeEdit->setFrame(true);
        dateTimeEdit->setReadOnly(true);
        dateTimeEdit->setButtonSymbols(QAbstractSpinBox::NoButtons);
        dateTimeEdit->setTimeSpec(Qt::UTC);

        formLayout_3->setWidget(8, QFormLayout::FieldRole, dateTimeEdit);


        formLayout->setWidget(3, QFormLayout::SpanningRole, groupCoords);

        checkZrv = new QGroupBox(scrollAreaWidgetContents);
        checkZrv->setObjectName(QString::fromUtf8("checkZrv"));
        checkZrv->setFlat(false);
        checkZrv->setCheckable(true);
        formLayout_4 = new QFormLayout(checkZrv);
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        checkZrvEnable = new QCheckBox(checkZrv);
        checkZrvEnable->setObjectName(QString::fromUtf8("checkZrvEnable"));
        checkZrvEnable->setChecked(true);

        formLayout_4->setWidget(0, QFormLayout::SpanningRole, checkZrvEnable);

        btnColorZrv = new QToolButton(checkZrv);
        btnColorZrv->setObjectName(QString::fromUtf8("btnColorZrv"));
        sizePolicy1.setHeightForWidth(btnColorZrv->sizePolicy().hasHeightForWidth());
        btnColorZrv->setSizePolicy(sizePolicy1);
        btnColorZrv->setAutoFillBackground(true);
        btnColorZrv->setToolButtonStyle(Qt::ToolButtonTextOnly);
        btnColorZrv->setAutoRaise(true);

        formLayout_4->setWidget(3, QFormLayout::SpanningRole, btnColorZrv);

        label_3 = new QLabel(checkZrv);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_4->setWidget(1, QFormLayout::LabelRole, label_3);

        spinZRV = new QDoubleSpinBox(checkZrv);
        spinZRV->setObjectName(QString::fromUtf8("spinZRV"));
        sizePolicy2.setHeightForWidth(spinZRV->sizePolicy().hasHeightForWidth());
        spinZRV->setSizePolicy(sizePolicy2);
        spinZRV->setDecimals(3);
        spinZRV->setMaximum(90);
        spinZRV->setSingleStep(0.5);
        spinZRV->setValue(0);

        formLayout_4->setWidget(1, QFormLayout::FieldRole, spinZRV);


        formLayout->setWidget(4, QFormLayout::SpanningRole, checkZrv);

        checkZrvLines = new QGroupBox(scrollAreaWidgetContents);
        checkZrvLines->setObjectName(QString::fromUtf8("checkZrvLines"));
        checkZrvLines->setCheckable(true);
        formLayout_5 = new QFormLayout(checkZrvLines);
        formLayout_5->setObjectName(QString::fromUtf8("formLayout_5"));
        labelWidth = new QLabel(checkZrvLines);
        labelWidth->setObjectName(QString::fromUtf8("labelWidth"));
        labelWidth->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_5->setWidget(0, QFormLayout::LabelRole, labelWidth);

        spinLines = new QDoubleSpinBox(checkZrvLines);
        spinLines->setObjectName(QString::fromUtf8("spinLines"));
        sizePolicy2.setHeightForWidth(spinLines->sizePolicy().hasHeightForWidth());
        spinLines->setSizePolicy(sizePolicy2);
        spinLines->setDecimals(1);
        spinLines->setMaximum(10);
        spinLines->setSingleStep(0.1);

        formLayout_5->setWidget(0, QFormLayout::FieldRole, spinLines);

        btnColorLines = new QToolButton(checkZrvLines);
        btnColorLines->setObjectName(QString::fromUtf8("btnColorLines"));
        sizePolicy1.setHeightForWidth(btnColorLines->sizePolicy().hasHeightForWidth());
        btnColorLines->setSizePolicy(sizePolicy1);
        btnColorLines->setAutoFillBackground(true);
        btnColorLines->setToolButtonStyle(Qt::ToolButtonTextOnly);
        btnColorLines->setAutoRaise(true);

        formLayout_5->setWidget(1, QFormLayout::SpanningRole, btnColorLines);


        formLayout->setWidget(5, QFormLayout::SpanningRole, checkZrvLines);

        checkTrack = new QGroupBox(scrollAreaWidgetContents);
        checkTrack->setObjectName(QString::fromUtf8("checkTrack"));
        checkTrack->setCheckable(true);
        formLayout_6 = new QFormLayout(checkTrack);
        formLayout_6->setObjectName(QString::fromUtf8("formLayout_6"));
        spinTrack = new QDoubleSpinBox(checkTrack);
        spinTrack->setObjectName(QString::fromUtf8("spinTrack"));
        sizePolicy2.setHeightForWidth(spinTrack->sizePolicy().hasHeightForWidth());
        spinTrack->setSizePolicy(sizePolicy2);
        spinTrack->setSingleStep(0.5);
        spinTrack->setValue(0.5);

        formLayout_6->setWidget(0, QFormLayout::FieldRole, spinTrack);

        labelLength = new QLabel(checkTrack);
        labelLength->setObjectName(QString::fromUtf8("labelLength"));
        labelLength->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_6->setWidget(0, QFormLayout::LabelRole, labelLength);

        btnColorTrack = new QToolButton(checkTrack);
        btnColorTrack->setObjectName(QString::fromUtf8("btnColorTrack"));
        sizePolicy1.setHeightForWidth(btnColorTrack->sizePolicy().hasHeightForWidth());
        btnColorTrack->setSizePolicy(sizePolicy1);
        btnColorTrack->setAutoFillBackground(true);
        btnColorTrack->setToolButtonStyle(Qt::ToolButtonTextOnly);
        btnColorTrack->setAutoRaise(true);

        formLayout_6->setWidget(1, QFormLayout::SpanningRole, btnColorTrack);


        formLayout->setWidget(6, QFormLayout::SpanningRole, checkTrack);

        comboModel = new QComboBox(scrollAreaWidgetContents);
        comboModel->setObjectName(QString::fromUtf8("comboModel"));

        formLayout->setWidget(8, QFormLayout::SpanningRole, comboModel);

        labelModel = new QLabel(scrollAreaWidgetContents);
        labelModel->setObjectName(QString::fromUtf8("labelModel"));

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
        SatDialog->setWindowTitle(QApplication::translate("SatDialog", "Satellite", 0, QApplication::UnicodeUTF8));
        btnDefault->setText(QApplication::translate("SatDialog", "Default", 0, QApplication::UnicodeUTF8));
        btnIcon->setText(QString());
        checkName->setTitle(QApplication::translate("SatDialog", "Name", 0, QApplication::UnicodeUTF8));
        labelNameX->setText(QApplication::translate("SatDialog", "X", 0, QApplication::UnicodeUTF8));
        labelNameY->setText(QApplication::translate("SatDialog", "Y", 0, QApplication::UnicodeUTF8));
        btnFont->setText(QApplication::translate("SatDialog", "Font", 0, QApplication::UnicodeUTF8));
        btnColorName->setText(QApplication::translate("SatDialog", "Color", 0, QApplication::UnicodeUTF8));
        groupCoords->setTitle(QApplication::translate("SatDialog", "Coords", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("SatDialog", "Inclination", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("SatDialog", "Ascending node", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("SatDialog", "Eccentricity", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("SatDialog", "Arg. perigee lat.", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("SatDialog", "Mean anomaly", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("SatDialog", "Mean motion", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("SatDialog", "Ballistic coeff.", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("SatDialog", "Timestamp", 0, QApplication::UnicodeUTF8));
        dateTimeEdit->setDisplayFormat(QApplication::translate("SatDialog", "dd.MM.yyyy H:mm:ss.zzz", 0, QApplication::UnicodeUTF8));
        checkZrv->setTitle(QApplication::translate("SatDialog", "Zone", 0, QApplication::UnicodeUTF8));
        checkZrvEnable->setText(QApplication::translate("SatDialog", "Enabled", 0, QApplication::UnicodeUTF8));
        btnColorZrv->setText(QApplication::translate("SatDialog", "Color", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("SatDialog", "Width", 0, QApplication::UnicodeUTF8));
        checkZrvLines->setTitle(QApplication::translate("SatDialog", "Zone contour", 0, QApplication::UnicodeUTF8));
        labelWidth->setText(QApplication::translate("SatDialog", "Width", 0, QApplication::UnicodeUTF8));
        btnColorLines->setText(QApplication::translate("SatDialog", "Color", 0, QApplication::UnicodeUTF8));
        checkTrack->setTitle(QApplication::translate("SatDialog", "Track", 0, QApplication::UnicodeUTF8));
        labelLength->setText(QApplication::translate("SatDialog", "Length", 0, QApplication::UnicodeUTF8));
        btnColorTrack->setText(QApplication::translate("SatDialog", "Color", 0, QApplication::UnicodeUTF8));
        labelModel->setText(QApplication::translate("SatDialog", "Model", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SatDialog: public Ui_SatDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAT_H
