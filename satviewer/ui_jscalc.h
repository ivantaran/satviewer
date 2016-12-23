/********************************************************************************
** Form generated from reading UI file 'jscalc.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JSCALC_H
#define UI_JSCALC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

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
            JsWidget->setObjectName(QStringLiteral("JsWidget"));
        JsWidget->resize(320, 360);
        verticalLayout = new QVBoxLayout(JsWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        textEdit = new QTextEdit(JsWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setReadOnly(true);

        verticalLayout->addWidget(textEdit);

        btnRefresh = new QPushButton(JsWidget);
        btnRefresh->setObjectName(QStringLiteral("btnRefresh"));

        verticalLayout->addWidget(btnRefresh);


        retranslateUi(JsWidget);

        QMetaObject::connectSlotsByName(JsWidget);
    } // setupUi

    void retranslateUi(QWidget *JsWidget)
    {
        JsWidget->setWindowTitle(QApplication::translate("JsWidget", "Form", 0));
        btnRefresh->setText(QApplication::translate("JsWidget", "Refresh", 0));
    } // retranslateUi

};

namespace Ui {
    class JsWidget: public Ui_JsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JSCALC_H
