/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created: Sun 7. Oct 19:10:50 2012
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QFormLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingsWidget
{
public:
    QFormLayout *formLayout;
    QLabel *labelLanguage;
    QComboBox *comboLanguage;
    QLabel *labelGlWidget;
    QComboBox *comboGlWidget;
    QLabel *labelStyle;
    QComboBox *comboStyle;
    QCheckBox *checkPalette;
    QCheckBox *checkUpdates;
    QCheckBox *checkSave;
    QPushButton *btnPrintScr;
    QSpacerItem *verticalSpacer_2;
    QPushButton *btnReset;

    void setupUi(QWidget *SettingsWidget)
    {
        if (SettingsWidget->objectName().isEmpty())
            SettingsWidget->setObjectName(QString::fromUtf8("SettingsWidget"));
        SettingsWidget->resize(400, 300);
        SettingsWidget->setLocale(QLocale(QLocale::C, QLocale::AnyCountry));
        formLayout = new QFormLayout(SettingsWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        labelLanguage = new QLabel(SettingsWidget);
        labelLanguage->setObjectName(QString::fromUtf8("labelLanguage"));
        labelLanguage->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(0, QFormLayout::LabelRole, labelLanguage);

        comboLanguage = new QComboBox(SettingsWidget);
        comboLanguage->setObjectName(QString::fromUtf8("comboLanguage"));

        formLayout->setWidget(0, QFormLayout::FieldRole, comboLanguage);

        labelGlWidget = new QLabel(SettingsWidget);
        labelGlWidget->setObjectName(QString::fromUtf8("labelGlWidget"));

        formLayout->setWidget(1, QFormLayout::LabelRole, labelGlWidget);

        comboGlWidget = new QComboBox(SettingsWidget);
        comboGlWidget->setObjectName(QString::fromUtf8("comboGlWidget"));

        formLayout->setWidget(1, QFormLayout::FieldRole, comboGlWidget);

        labelStyle = new QLabel(SettingsWidget);
        labelStyle->setObjectName(QString::fromUtf8("labelStyle"));
        labelStyle->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(2, QFormLayout::LabelRole, labelStyle);

        comboStyle = new QComboBox(SettingsWidget);
        comboStyle->setObjectName(QString::fromUtf8("comboStyle"));

        formLayout->setWidget(2, QFormLayout::FieldRole, comboStyle);

        checkPalette = new QCheckBox(SettingsWidget);
        checkPalette->setObjectName(QString::fromUtf8("checkPalette"));

        formLayout->setWidget(3, QFormLayout::LabelRole, checkPalette);

        checkUpdates = new QCheckBox(SettingsWidget);
        checkUpdates->setObjectName(QString::fromUtf8("checkUpdates"));
        checkUpdates->setEnabled(true);

        formLayout->setWidget(4, QFormLayout::LabelRole, checkUpdates);

        checkSave = new QCheckBox(SettingsWidget);
        checkSave->setObjectName(QString::fromUtf8("checkSave"));
        checkSave->setChecked(true);

        formLayout->setWidget(5, QFormLayout::LabelRole, checkSave);

        btnPrintScr = new QPushButton(SettingsWidget);
        btnPrintScr->setObjectName(QString::fromUtf8("btnPrintScr"));

        formLayout->setWidget(7, QFormLayout::SpanningRole, btnPrintScr);

        verticalSpacer_2 = new QSpacerItem(379, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(8, QFormLayout::SpanningRole, verticalSpacer_2);

        btnReset = new QPushButton(SettingsWidget);
        btnReset->setObjectName(QString::fromUtf8("btnReset"));
        btnReset->setEnabled(true);

        formLayout->setWidget(6, QFormLayout::SpanningRole, btnReset);

#ifndef QT_NO_SHORTCUT
        labelLanguage->setBuddy(comboLanguage);
        labelGlWidget->setBuddy(comboGlWidget);
        labelStyle->setBuddy(comboStyle);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(comboLanguage, comboGlWidget);
        QWidget::setTabOrder(comboGlWidget, comboStyle);
        QWidget::setTabOrder(comboStyle, checkPalette);
        QWidget::setTabOrder(checkPalette, checkUpdates);
        QWidget::setTabOrder(checkUpdates, checkSave);
        QWidget::setTabOrder(checkSave, btnReset);
        QWidget::setTabOrder(btnReset, btnPrintScr);

        retranslateUi(SettingsWidget);

        QMetaObject::connectSlotsByName(SettingsWidget);
    } // setupUi

    void retranslateUi(QWidget *SettingsWidget)
    {
        SettingsWidget->setWindowTitle(QApplication::translate("SettingsWidget", "Settings", 0, QApplication::UnicodeUTF8));
        labelLanguage->setText(QApplication::translate("SettingsWidget", "Language", 0, QApplication::UnicodeUTF8));
        labelGlWidget->setText(QApplication::translate("SettingsWidget", "Type of map", 0, QApplication::UnicodeUTF8));
        comboGlWidget->clear();
        comboGlWidget->insertItems(0, QStringList()
         << QApplication::translate("SettingsWidget", "2d - Cylindrical projection", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SettingsWidget", "3d - Earth", 0, QApplication::UnicodeUTF8)
        );
        labelStyle->setText(QApplication::translate("SettingsWidget", "Style", 0, QApplication::UnicodeUTF8));
        checkPalette->setText(QApplication::translate("SettingsWidget", "Use standart palette", 0, QApplication::UnicodeUTF8));
        checkUpdates->setText(QApplication::translate("SettingsWidget", "Check for updates", 0, QApplication::UnicodeUTF8));
        checkSave->setText(QApplication::translate("SettingsWidget", "Save settings", 0, QApplication::UnicodeUTF8));
        btnPrintScr->setText(QApplication::translate("SettingsWidget", "Snapshot", 0, QApplication::UnicodeUTF8));
        btnReset->setText(QApplication::translate("SettingsWidget", "Reset to default", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SettingsWidget: public Ui_SettingsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
