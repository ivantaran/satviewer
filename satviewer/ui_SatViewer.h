/********************************************************************************
** Form generated from reading UI file 'SatViewer.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SATVIEWER_H
#define UI_SATVIEWER_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QFrame *frameMain;
    QVBoxLayout *verticalLayout_2;
    QFrame *frameMap;
    QFrame *frameTime;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *tlBtnOptions;
    QFrame *line_4;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QDateTimeEdit *dateTimeEdit;
    QComboBox *comboBoxTimeType;
    QFrame *line;
    QFrame *line_5;
    QToolButton *tlBtnTime;
    QToolButton *tlBtnPlay;
    QToolButton *tlBtnBackward;
    QToolButton *tlBtnForward;
    QFrame *line_2;
    QLabel *label_2;
    QSpinBox *spinBoxStep;
    QComboBox *comboBoxStep;
    QLabel *label_3;
    QSpinBox *spinBoxTimeX;
    QSpacerItem *horizontalSpacer;
    QToolButton *btnFullScreen;
    QFrame *line_3;
    QToolButton *tlBtnExit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(682, 480);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QStringLiteral(":/options/satviewer.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setLocale(QLocale(QLocale::C, QLocale::AnyCountry));
        MainWindow->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        frameMain = new QFrame(centralwidget);
        frameMain->setObjectName(QStringLiteral("frameMain"));
        frameMain->setCursor(QCursor(Qt::ArrowCursor));
        frameMain->setFrameShape(QFrame::NoFrame);
        frameMain->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frameMain);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        frameMap = new QFrame(frameMain);
        frameMap->setObjectName(QStringLiteral("frameMap"));
        frameMap->setCursor(QCursor(Qt::CrossCursor));
        frameMap->setFrameShape(QFrame::Panel);
        frameMap->setFrameShadow(QFrame::Plain);
        frameMap->setLineWidth(2);

        verticalLayout_2->addWidget(frameMap);

        frameTime = new QFrame(frameMain);
        frameTime->setObjectName(QStringLiteral("frameTime"));
        frameTime->setMinimumSize(QSize(0, 32));
        frameTime->setMaximumSize(QSize(16777215, 32));
        horizontalLayout_2 = new QHBoxLayout(frameTime);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        tlBtnOptions = new QToolButton(frameTime);
        tlBtnOptions->setObjectName(QStringLiteral("tlBtnOptions"));
        sizePolicy.setHeightForWidth(tlBtnOptions->sizePolicy().hasHeightForWidth());
        tlBtnOptions->setSizePolicy(sizePolicy);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/toolbar/utilities.png"), QSize(), QIcon::Normal, QIcon::Off);
        tlBtnOptions->setIcon(icon1);
        tlBtnOptions->setIconSize(QSize(24, 24));
        tlBtnOptions->setAutoRaise(true);

        horizontalLayout_2->addWidget(tlBtnOptions);

        line_4 = new QFrame(frameTime);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line_4);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        label = new QLabel(frameTime);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_2->addWidget(label);

        dateTimeEdit = new QDateTimeEdit(frameTime);
        dateTimeEdit->setObjectName(QStringLiteral("dateTimeEdit"));
        dateTimeEdit->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(dateTimeEdit->sizePolicy().hasHeightForWidth());
        dateTimeEdit->setSizePolicy(sizePolicy1);
        dateTimeEdit->setMaximumSize(QSize(16777215, 16777215));
        dateTimeEdit->setSpecialValueText(QStringLiteral(""));
        dateTimeEdit->setCorrectionMode(QAbstractSpinBox::CorrectToNearestValue);
        dateTimeEdit->setDisplayFormat(QStringLiteral("dd.MM.yyyy H:mm:ss"));
        dateTimeEdit->setCalendarPopup(true);
        dateTimeEdit->setCurrentSectionIndex(0);

        horizontalLayout_2->addWidget(dateTimeEdit);

        comboBoxTimeType = new QComboBox(frameTime);
        comboBoxTimeType->setObjectName(QStringLiteral("comboBoxTimeType"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(comboBoxTimeType->sizePolicy().hasHeightForWidth());
        comboBoxTimeType->setSizePolicy(sizePolicy2);
        comboBoxTimeType->setMinimumSize(QSize(0, 32));
        comboBoxTimeType->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        horizontalLayout_2->addWidget(comboBoxTimeType);

        line = new QFrame(frameTime);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line);

        line_5 = new QFrame(frameTime);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line_5);

        tlBtnTime = new QToolButton(frameTime);
        tlBtnTime->setObjectName(QStringLiteral("tlBtnTime"));
        sizePolicy.setHeightForWidth(tlBtnTime->sizePolicy().hasHeightForWidth());
        tlBtnTime->setSizePolicy(sizePolicy);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/toolbar/player_eject.png"), QSize(), QIcon::Normal, QIcon::Off);
        tlBtnTime->setIcon(icon2);
        tlBtnTime->setIconSize(QSize(24, 24));
        tlBtnTime->setCheckable(true);
        tlBtnTime->setAutoRaise(true);

        horizontalLayout_2->addWidget(tlBtnTime);

        tlBtnPlay = new QToolButton(frameTime);
        tlBtnPlay->setObjectName(QStringLiteral("tlBtnPlay"));
        tlBtnPlay->setEnabled(false);
        sizePolicy.setHeightForWidth(tlBtnPlay->sizePolicy().hasHeightForWidth());
        tlBtnPlay->setSizePolicy(sizePolicy);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/toolbar/player_play.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon3.addFile(QStringLiteral(":/toolbar/player_pause.png"), QSize(), QIcon::Normal, QIcon::On);
        tlBtnPlay->setIcon(icon3);
        tlBtnPlay->setIconSize(QSize(24, 24));
        tlBtnPlay->setCheckable(true);
        tlBtnPlay->setAutoRaise(true);

        horizontalLayout_2->addWidget(tlBtnPlay);

        tlBtnBackward = new QToolButton(frameTime);
        tlBtnBackward->setObjectName(QStringLiteral("tlBtnBackward"));
        tlBtnBackward->setEnabled(false);
        sizePolicy.setHeightForWidth(tlBtnBackward->sizePolicy().hasHeightForWidth());
        tlBtnBackward->setSizePolicy(sizePolicy);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/toolbar/player_rew.png"), QSize(), QIcon::Normal, QIcon::Off);
        tlBtnBackward->setIcon(icon4);
        tlBtnBackward->setIconSize(QSize(24, 24));
        tlBtnBackward->setCheckable(true);
        tlBtnBackward->setChecked(false);
        tlBtnBackward->setAutoRaise(true);

        horizontalLayout_2->addWidget(tlBtnBackward);

        tlBtnForward = new QToolButton(frameTime);
        tlBtnForward->setObjectName(QStringLiteral("tlBtnForward"));
        tlBtnForward->setEnabled(false);
        sizePolicy.setHeightForWidth(tlBtnForward->sizePolicy().hasHeightForWidth());
        tlBtnForward->setSizePolicy(sizePolicy);
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/toolbar/player_fwd.png"), QSize(), QIcon::Normal, QIcon::Off);
        tlBtnForward->setIcon(icon5);
        tlBtnForward->setIconSize(QSize(24, 24));
        tlBtnForward->setCheckable(true);
        tlBtnForward->setChecked(true);
        tlBtnForward->setAutoRaise(true);

        horizontalLayout_2->addWidget(tlBtnForward);

        line_2 = new QFrame(frameTime);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line_2);

        label_2 = new QLabel(frameTime);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy3);

        horizontalLayout_2->addWidget(label_2);

        spinBoxStep = new QSpinBox(frameTime);
        spinBoxStep->setObjectName(QStringLiteral("spinBoxStep"));
        sizePolicy3.setHeightForWidth(spinBoxStep->sizePolicy().hasHeightForWidth());
        spinBoxStep->setSizePolicy(sizePolicy3);
        spinBoxStep->setMinimum(-99);
        spinBoxStep->setValue(1);

        horizontalLayout_2->addWidget(spinBoxStep);

        comboBoxStep = new QComboBox(frameTime);
        comboBoxStep->setObjectName(QStringLiteral("comboBoxStep"));
        sizePolicy3.setHeightForWidth(comboBoxStep->sizePolicy().hasHeightForWidth());
        comboBoxStep->setSizePolicy(sizePolicy3);

        horizontalLayout_2->addWidget(comboBoxStep);

        label_3 = new QLabel(frameTime);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        spinBoxTimeX = new QSpinBox(frameTime);
        spinBoxTimeX->setObjectName(QStringLiteral("spinBoxTimeX"));
        sizePolicy3.setHeightForWidth(spinBoxTimeX->sizePolicy().hasHeightForWidth());
        spinBoxTimeX->setSizePolicy(sizePolicy3);
        spinBoxTimeX->setMinimum(1);
        spinBoxTimeX->setMaximum(100);
        spinBoxTimeX->setSingleStep(5);
        spinBoxTimeX->setValue(20);

        horizontalLayout_2->addWidget(spinBoxTimeX);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btnFullScreen = new QToolButton(frameTime);
        btnFullScreen->setObjectName(QStringLiteral("btnFullScreen"));
        sizePolicy.setHeightForWidth(btnFullScreen->sizePolicy().hasHeightForWidth());
        btnFullScreen->setSizePolicy(sizePolicy);
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/toolbar/fullscreen.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnFullScreen->setIcon(icon6);
        btnFullScreen->setIconSize(QSize(24, 24));
        btnFullScreen->setAutoRaise(true);

        horizontalLayout_2->addWidget(btnFullScreen);

        line_3 = new QFrame(frameTime);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line_3);

        tlBtnExit = new QToolButton(frameTime);
        tlBtnExit->setObjectName(QStringLiteral("tlBtnExit"));
        sizePolicy.setHeightForWidth(tlBtnExit->sizePolicy().hasHeightForWidth());
        tlBtnExit->setSizePolicy(sizePolicy);
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/toolbar/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        tlBtnExit->setIcon(icon7);
        tlBtnExit->setIconSize(QSize(24, 24));
        tlBtnExit->setAutoRaise(true);

        horizontalLayout_2->addWidget(tlBtnExit);


        verticalLayout_2->addWidget(frameTime);


        horizontalLayout->addWidget(frameMain);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);
#ifndef QT_NO_SHORTCUT
        label->setBuddy(dateTimeEdit);
        label_2->setBuddy(spinBoxStep);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(tlBtnOptions, dateTimeEdit);
        QWidget::setTabOrder(dateTimeEdit, comboBoxTimeType);
        QWidget::setTabOrder(comboBoxTimeType, tlBtnTime);
        QWidget::setTabOrder(tlBtnTime, tlBtnPlay);
        QWidget::setTabOrder(tlBtnPlay, tlBtnBackward);
        QWidget::setTabOrder(tlBtnBackward, tlBtnForward);
        QWidget::setTabOrder(tlBtnForward, spinBoxStep);
        QWidget::setTabOrder(spinBoxStep, comboBoxStep);
        QWidget::setTabOrder(comboBoxStep, spinBoxTimeX);
        QWidget::setTabOrder(spinBoxTimeX, tlBtnExit);

        retranslateUi(MainWindow);
        QObject::connect(tlBtnExit, SIGNAL(clicked()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "SatViewer", 0));
#ifndef QT_NO_TOOLTIP
        tlBtnOptions->setToolTip(QApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", 0));
#endif // QT_NO_TOOLTIP
        tlBtnOptions->setText(QString());
        label->setText(QApplication::translate("MainWindow", "Time:", 0));
        comboBoxTimeType->clear();
        comboBoxTimeType->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Local", 0)
         << QApplication::translate("MainWindow", "UTC", 0)
        );
        tlBtnTime->setText(QString());
        tlBtnPlay->setText(QString());
        tlBtnBackward->setText(QString());
        tlBtnForward->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "Step:", 0));
        comboBoxStep->clear();
        comboBoxStep->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "sec", 0)
         << QApplication::translate("MainWindow", "min", 0)
         << QApplication::translate("MainWindow", "hour", 0)
         << QApplication::translate("MainWindow", "day", 0)
        );
        label_3->setText(QApplication::translate("MainWindow", " X ", 0));
#ifndef QT_NO_TOOLTIP
        btnFullScreen->setToolTip(QApplication::translate("MainWindow", "Ctlr+F", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        tlBtnExit->setToolTip(QApplication::translate("MainWindow", "Quit", 0));
#endif // QT_NO_TOOLTIP
        tlBtnExit->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SATVIEWER_H
