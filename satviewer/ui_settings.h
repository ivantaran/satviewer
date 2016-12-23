/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

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
            SettingsWidget->setObjectName(QStringLiteral("SettingsWidget"));
        SettingsWidget->resize(400, 300);
        SettingsWidget->setLocale(QLocale(QLocale::C, QLocale::AnyCountry));
        formLayout = new QFormLayout(SettingsWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        labelLanguage = new QLabel(SettingsWidget);
        labelLanguage->setObjectName(QStringLiteral("labelLanguage"));
        labelLanguage->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(0, QFormLayout::LabelRole, labelLanguage);

        comboLanguage = new QComboBox(SettingsWidget);
        comboLanguage->setObjectName(QStringLiteral("comboLanguage"));

        formLayout->setWidget(0, QFormLayout::FieldRole, comboLanguage);

        labelGlWidget = new QLabel(SettingsWidget);
        labelGlWidget->setObjectName(QStringLiteral("labelGlWidget"));

        formLayout->setWidget(1, QFormLayout::LabelRole, labelGlWidget);

        comboGlWidget = new QComboBox(SettingsWidget);
        comboGlWidget->setObjectName(QStringLiteral("comboGlWidget"));

        formLayout->setWidget(1, QFormLayout::FieldRole, comboGlWidget);

        labelStyle = new QLabel(SettingsWidget);
        labelStyle->setObjectName(QStringLiteral("labelStyle"));
        labelStyle->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(2, QFormLayout::LabelRole, labelStyle);

        comboStyle = new QComboBox(SettingsWidget);
        comboStyle->setObjectName(QStringLiteral("comboStyle"));

        formLayout->setWidget(2, QFormLayout::FieldRole, comboStyle);

        checkPalette = new QCheckBox(SettingsWidget);
        checkPalette->setObjectName(QStringLiteral("checkPalette"));

        formLayout->setWidget(3, QFormLayout::LabelRole, checkPalette);

        checkUpdates = new QCheckBox(SettingsWidget);
        checkUpdates->setObjectName(QStringLiteral("checkUpdates"));
        checkUpdates->setEnabled(true);

        formLayout->setWidget(4, QFormLayout::LabelRole, checkUpdates);

        checkSave = new QCheckBox(SettingsWidget);
        checkSave->setObjectName(QStringLiteral("checkSave"));
        checkSave->setChecked(true);

        formLayout->setWidget(5, QFormLayout::LabelRole, checkSave);

        btnPrintScr = new QPushButton(SettingsWidget);
        btnPrintScr->setObjectName(QStringLiteral("btnPrintScr"));

        formLayout->setWidget(7, QFormLayout::SpanningRole, btnPrintScr);

        verticalSpacer_2 = new QSpacerItem(379, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(8, QFormLayout::SpanningRole, verticalSpacer_2);

        btnReset = new QPushButton(SettingsWidget);
        btnReset->setObjectName(QStringLiteral("btnReset"));
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
        SettingsWidget->setWindowTitle(QApplication::translate("SettingsWidget", "Settings", 0));
        labelLanguage->setText(QApplication::translate("SettingsWidget", "Language", 0));
        labelGlWidget->setText(QApplication::translate("SettingsWidget", "Type of map", 0));
        comboGlWidget->clear();
        comboGlWidget->insertItems(0, QStringList()
         << QApplication::translate("SettingsWidget", "2d - Cylindrical projection", 0)
         << QApplication::translate("SettingsWidget", "3d - Earth", 0)
        );
        labelStyle->setText(QApplication::translate("SettingsWidget", "Style", 0));
        checkPalette->setText(QApplication::translate("SettingsWidget", "Use standart palette", 0));
        checkUpdates->setText(QApplication::translate("SettingsWidget", "Check for updates", 0));
        checkSave->setText(QApplication::translate("SettingsWidget", "Save settings", 0));
        btnPrintScr->setText(QApplication::translate("SettingsWidget", "Snapshot", 0));
        btnReset->setText(QApplication::translate("SettingsWidget", "Reset to default", 0));
    } // retranslateUi

};

namespace Ui {
    class SettingsWidget: public Ui_SettingsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
