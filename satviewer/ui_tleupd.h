/********************************************************************************
** Form generated from reading UI file 'tleupd.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TLEUPD_H
#define UI_TLEUPD_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListView>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Updater
{
public:
    QVBoxLayout *verticalLayout;
    QListView *listView;
    QPlainTextEdit *textStatus;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QToolButton *btnUpdate;
    QToolButton *btnAbort;
    QFrame *line_2;
    QToolButton *btnSave;
    QToolButton *btnAdd;
    QToolButton *btnRemove;
    QToolButton *btnClear;
    QSpacerItem *horizontalSpacer;
    QProgressBar *progressBar;

    void setupUi(QWidget *Updater)
    {
        if (Updater->objectName().isEmpty())
            Updater->setObjectName(QStringLiteral("Updater"));
        Updater->resize(320, 240);
        Updater->setLocale(QLocale(QLocale::C, QLocale::AnyCountry));
        verticalLayout = new QVBoxLayout(Updater);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        listView = new QListView(Updater);
        listView->setObjectName(QStringLiteral("listView"));

        verticalLayout->addWidget(listView);

        textStatus = new QPlainTextEdit(Updater);
        textStatus->setObjectName(QStringLiteral("textStatus"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(textStatus->sizePolicy().hasHeightForWidth());
        textStatus->setSizePolicy(sizePolicy);
        textStatus->setMinimumSize(QSize(0, 66));
        textStatus->setMaximumSize(QSize(16777215, 66));
        textStatus->setBaseSize(QSize(0, 66));
        textStatus->setLineWrapMode(QPlainTextEdit::NoWrap);

        verticalLayout->addWidget(textStatus);

        widget = new QWidget(Updater);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btnUpdate = new QToolButton(widget);
        btnUpdate->setObjectName(QStringLiteral("btnUpdate"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/actions/reload.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnUpdate->setIcon(icon);
        btnUpdate->setAutoRaise(true);

        horizontalLayout->addWidget(btnUpdate);

        btnAbort = new QToolButton(widget);
        btnAbort->setObjectName(QStringLiteral("btnAbort"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/actions/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnAbort->setIcon(icon1);
        btnAbort->setAutoRaise(true);

        horizontalLayout->addWidget(btnAbort);

        line_2 = new QFrame(widget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_2);

        btnSave = new QToolButton(widget);
        btnSave->setObjectName(QStringLiteral("btnSave"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/actions/filesave.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSave->setIcon(icon2);
        btnSave->setAutoRaise(true);

        horizontalLayout->addWidget(btnSave);

        btnAdd = new QToolButton(widget);
        btnAdd->setObjectName(QStringLiteral("btnAdd"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/actions/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnAdd->setIcon(icon3);
        btnAdd->setAutoRaise(true);

        horizontalLayout->addWidget(btnAdd);

        btnRemove = new QToolButton(widget);
        btnRemove->setObjectName(QStringLiteral("btnRemove"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/actions/remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRemove->setIcon(icon4);
        btnRemove->setAutoRaise(true);

        horizontalLayout->addWidget(btnRemove);

        btnClear = new QToolButton(widget);
        btnClear->setObjectName(QStringLiteral("btnClear"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/actions/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnClear->setIcon(icon5);
        btnClear->setAutoRaise(true);

        horizontalLayout->addWidget(btnClear);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addWidget(widget);

        progressBar = new QProgressBar(Updater);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(0);

        verticalLayout->addWidget(progressBar);

        QWidget::setTabOrder(listView, textStatus);
        QWidget::setTabOrder(textStatus, btnSave);
        QWidget::setTabOrder(btnSave, btnAdd);
        QWidget::setTabOrder(btnAdd, btnRemove);
        QWidget::setTabOrder(btnRemove, btnClear);

        retranslateUi(Updater);

        QMetaObject::connectSlotsByName(Updater);
    } // setupUi

    void retranslateUi(QWidget *Updater)
    {
        Updater->setWindowTitle(QApplication::translate("Updater", "TLE Updater", 0));
#ifndef QT_NO_TOOLTIP
        btnUpdate->setToolTip(QApplication::translate("Updater", "Download", 0));
#endif // QT_NO_TOOLTIP
        btnUpdate->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnAbort->setToolTip(QApplication::translate("Updater", "Abort", 0));
#endif // QT_NO_TOOLTIP
        btnAbort->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnSave->setToolTip(QApplication::translate("Updater", "Save", 0));
#endif // QT_NO_TOOLTIP
        btnSave->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnAdd->setToolTip(QApplication::translate("Updater", "Add", 0));
#endif // QT_NO_TOOLTIP
        btnAdd->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnRemove->setToolTip(QApplication::translate("Updater", "Remove", 0));
#endif // QT_NO_TOOLTIP
        btnRemove->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnClear->setToolTip(QApplication::translate("Updater", "Remove All", 0));
#endif // QT_NO_TOOLTIP
        btnClear->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Updater: public Ui_Updater {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TLEUPD_H
