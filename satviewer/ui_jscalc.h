/********************************************************************************
** Form generated from reading UI file 'jscalc.ui'
**
** Created: Fri 15. Jun 11:32:01 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JSCALC_H
#define UI_JSCALC_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_JsWidget
{
public:
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QPushButton *btnRefresh;

    void setupUi(QWidget *JsWidget)
    {
        if (JsWidget->objectName().isEmpty())
            JsWidget->setObjectName(QString::fromUtf8("JsWidget"));
        JsWidget->resize(320, 360);
        verticalLayout = new QVBoxLayout(JsWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        textEdit = new QTextEdit(JsWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setReadOnly(true);

        verticalLayout->addWidget(textEdit);

        btnRefresh = new QPushButton(JsWidget);
        btnRefresh->setObjectName(QString::fromUtf8("btnRefresh"));

        verticalLayout->addWidget(btnRefresh);


        retranslateUi(JsWidget);

        QMetaObject::connectSlotsByName(JsWidget);
    } // setupUi

    void retranslateUi(QWidget *JsWidget)
    {
        JsWidget->setWindowTitle(QApplication::translate("JsWidget", "Form", 0, QApplication::UnicodeUTF8));
        btnRefresh->setText(QApplication::translate("JsWidget", "Refresh", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class JsWidget: public Ui_JsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JSCALC_H
