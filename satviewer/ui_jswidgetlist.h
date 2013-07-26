/********************************************************************************
** Form generated from reading UI file 'jswidgetlist.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JSWIDGETLIST_H
#define UI_JSWIDGETLIST_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListView>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_JsWidgetList
{
public:
    QVBoxLayout *verticalLayout;
    QListView *listView;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QToolButton *btnSave;
    QToolButton *btnEdit;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *JsWidgetList)
    {
        if (JsWidgetList->objectName().isEmpty())
            JsWidgetList->setObjectName(QStringLiteral("JsWidgetList"));
        JsWidgetList->resize(320, 240);
        JsWidgetList->setLocale(QLocale(QLocale::C, QLocale::AnyCountry));
        verticalLayout = new QVBoxLayout(JsWidgetList);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        listView = new QListView(JsWidgetList);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout->addWidget(listView);

        widget = new QWidget(JsWidgetList);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btnSave = new QToolButton(widget);
        btnSave->setObjectName(QStringLiteral("btnSave"));
        btnSave->setEnabled(true);
        QIcon icon;
        icon.addFile(QStringLiteral(":/actions/filesave.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSave->setIcon(icon);
        btnSave->setAutoRaise(true);

        horizontalLayout->addWidget(btnSave);

        btnEdit = new QToolButton(widget);
        btnEdit->setObjectName(QStringLiteral("btnEdit"));
        btnEdit->setEnabled(false);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/actions/edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnEdit->setIcon(icon1);
        btnEdit->setAutoRaise(true);

        horizontalLayout->addWidget(btnEdit);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addWidget(widget);


        retranslateUi(JsWidgetList);

        QMetaObject::connectSlotsByName(JsWidgetList);
    } // setupUi

    void retranslateUi(QWidget *JsWidgetList)
    {
        JsWidgetList->setWindowTitle(QApplication::translate("JsWidgetList", "Widgets", 0));
#ifndef QT_NO_TOOLTIP
        btnSave->setToolTip(QApplication::translate("JsWidgetList", "Save", 0));
#endif // QT_NO_TOOLTIP
        btnSave->setText(QString());
        btnSave->setShortcut(QString());
#ifndef QT_NO_TOOLTIP
        btnEdit->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        btnEdit->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class JsWidgetList: public Ui_JsWidgetList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JSWIDGETLIST_H
