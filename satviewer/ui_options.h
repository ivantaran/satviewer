/********************************************************************************
** Form generated from reading UI file 'options.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONS_H
#define UI_OPTIONS_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QHBoxLayout *horizontalLayout_2;
    QWidget *wgtTool;
    QVBoxLayout *verticalLayout_7;
    QToolBox *toolBox;
    QWidget *page_5;
    QVBoxLayout *verticalLayout_6;
    QToolButton *btnToolSat;
    QToolButton *btnToolLoc;
    QSpacerItem *verticalSpacer;
    QWidget *page_6;
    QVBoxLayout *verticalLayout_8;
    QToolButton *btnToolZRV;
    QToolButton *btnToolParams;
    QSpacerItem *verticalSpacer_4;
    QWidget *page_7;
    QVBoxLayout *verticalLayout_9;
    QToolButton *btnToolWidgets;
    QToolButton *btnToolTle;
    QToolButton *btnToolMap;
    QToolButton *btnToolSettings;
    QToolButton *btnInfo;
    QSpacerItem *verticalSpacer_3;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QListView *listViewDBSat;
    QListView *listViewSat;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QToolButton *btnOpenTle;
    QToolButton *btnDeleteDbSat;
    QToolButton *btnClearDbSat;
    QSpacerItem *horizontalSpacer_2;
    QToolButton *btnAddToSatList;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_6;
    QToolButton *btnChangeDbSat;
    QToolButton *btnDeleteSatList;
    QToolButton *btnClearSatList;
    QSpacerItem *horizontalSpacer_3;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_6;
    QLabel *labelSatFind;
    QLineEdit *lineEditSatNameFilter;
    QLabel *labelSatName;
    QLineEdit *lineEditSatName;
    QLineEdit *lineEditSatGroup;
    QLabel *labelSatFilter;
    QLineEdit *lineEditSatFilter;
    QToolButton *btnSatSqlHelp;
    QToolButton *btnSatFilter;
    QLabel *labelSatGroup;
    QWidget *tab_2;
    QGridLayout *gridLayout;
    QLabel *labelI;
    QLabel *labelOmg;
    QLineEdit *lineEditSatI;
    QLineEdit *lineEditSatOmg;
    QLabel *labelW;
    QLabel *labelM0;
    QLineEdit *lineEditSatW;
    QLineEdit *lineEditSatM0;
    QLineEdit *lineEditSatE;
    QLabel *labelE;
    QLineEdit *lineEditSatN;
    QLabel *labelN;
    QLineEdit *lineEditSatBStar;
    QLabel *labelB;
    QLineEdit *lineEditSatTime;
    QLabel *labelSatTime;
    QWidget *page_3;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_3;
    QGridLayout *gridLayout_7;
    QListView *listViewDBLoc;
    QListView *listViewLoc;
    QWidget *widget_8;
    QHBoxLayout *horizontalLayout_4;
    QToolButton *btnChangeDbLoc;
    QToolButton *btnDeleteLocList;
    QToolButton *btnClearLocList;
    QSpacerItem *horizontalSpacer_4;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_3;
    QToolButton *btnAddToLocList;
    QSpacerItem *horizontalSpacer;
    QToolButton *btnClearDbLoc;
    QToolButton *btnDeleteDbLoc;
    QToolButton *btnAddDbLoc;
    QToolButton *btnOpenLoc;
    QTabWidget *tabWidget_2;
    QWidget *tab_4;
    QGridLayout *gridLayout_4;
    QLineEdit *lineEditLocNameFilter;
    QLineEdit *lineEditLocName;
    QLineEdit *lineEditLocFilter;
    QLabel *labelLocFind;
    QLabel *labelLocName;
    QLabel *labelLocFilter;
    QToolButton *btnLocSqlHelp;
    QToolButton *btnLocFilter;
    QWidget *tab_5;
    QGridLayout *gridLayout_5;
    QLineEdit *lineEditLocLat;
    QLineEdit *lineEditLocLon;
    QLineEdit *lineEditLocHeight;
    QLineEdit *lineEditLocAzimuth;
    QLineEdit *lineEditLocWidth;
    QLineEdit *lineEditLocRange;
    QLabel *labelAzimuth;
    QLabel *labelLat;
    QLabel *labelLon;
    QLabel *labelHeight;
    QLabel *labelWidth;
    QLabel *labelRange;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_3;
    QTextEdit *textZRVList;
    QPushButton *btnClearZrvList;
    QWidget *page_4;
    QVBoxLayout *verticalLayout_10;
    QTextEdit *teAbout;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *btnAboutQt;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(500, 400);
        Dialog->setLocale(QLocale(QLocale::C, QLocale::AnyCountry));
        horizontalLayout_2 = new QHBoxLayout(Dialog);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        wgtTool = new QWidget(Dialog);
        wgtTool->setObjectName(QStringLiteral("wgtTool"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(wgtTool->sizePolicy().hasHeightForWidth());
        wgtTool->setSizePolicy(sizePolicy);
        wgtTool->setMinimumSize(QSize(72, 0));
        verticalLayout_7 = new QVBoxLayout(wgtTool);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        toolBox = new QToolBox(wgtTool);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(toolBox->sizePolicy().hasHeightForWidth());
        toolBox->setSizePolicy(sizePolicy1);
        page_5 = new QWidget();
        page_5->setObjectName(QStringLiteral("page_5"));
        page_5->setGeometry(QRect(0, 0, 72, 319));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(page_5->sizePolicy().hasHeightForWidth());
        page_5->setSizePolicy(sizePolicy2);
        verticalLayout_6 = new QVBoxLayout(page_5);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        btnToolSat = new QToolButton(page_5);
        btnToolSat->setObjectName(QStringLiteral("btnToolSat"));
        sizePolicy2.setHeightForWidth(btnToolSat->sizePolicy().hasHeightForWidth());
        btnToolSat->setSizePolicy(sizePolicy2);
        QIcon icon;
        icon.addFile(QStringLiteral(":/options/gnome-applets.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnToolSat->setIcon(icon);
        btnToolSat->setIconSize(QSize(32, 32));
        btnToolSat->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnToolSat->setAutoRaise(true);

        verticalLayout_6->addWidget(btnToolSat);

        btnToolLoc = new QToolButton(page_5);
        btnToolLoc->setObjectName(QStringLiteral("btnToolLoc"));
        sizePolicy2.setHeightForWidth(btnToolLoc->sizePolicy().hasHeightForWidth());
        btnToolLoc->setSizePolicy(sizePolicy2);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/options/stock_channel.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnToolLoc->setIcon(icon1);
        btnToolLoc->setIconSize(QSize(32, 32));
        btnToolLoc->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnToolLoc->setAutoRaise(true);

        verticalLayout_6->addWidget(btnToolLoc);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer);

        toolBox->addItem(page_5, QStringLiteral("Objects"));
        page_6 = new QWidget();
        page_6->setObjectName(QStringLiteral("page_6"));
        page_6->setGeometry(QRect(0, 0, 96, 110));
        sizePolicy2.setHeightForWidth(page_6->sizePolicy().hasHeightForWidth());
        page_6->setSizePolicy(sizePolicy2);
        verticalLayout_8 = new QVBoxLayout(page_6);
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        btnToolZRV = new QToolButton(page_6);
        btnToolZRV->setObjectName(QStringLiteral("btnToolZRV"));
        sizePolicy2.setHeightForWidth(btnToolZRV->sizePolicy().hasHeightForWidth());
        btnToolZRV->setSizePolicy(sizePolicy2);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/options/clock.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnToolZRV->setIcon(icon2);
        btnToolZRV->setIconSize(QSize(32, 32));
        btnToolZRV->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnToolZRV->setAutoRaise(true);

        verticalLayout_8->addWidget(btnToolZRV);

        btnToolParams = new QToolButton(page_6);
        btnToolParams->setObjectName(QStringLiteral("btnToolParams"));
        sizePolicy2.setHeightForWidth(btnToolParams->sizePolicy().hasHeightForWidth());
        btnToolParams->setSizePolicy(sizePolicy2);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/options/calc.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnToolParams->setIcon(icon3);
        btnToolParams->setIconSize(QSize(32, 32));
        btnToolParams->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnToolParams->setAutoRaise(true);

        verticalLayout_8->addWidget(btnToolParams);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer_4);

        toolBox->addItem(page_6, QStringLiteral("Data"));
        page_7 = new QWidget();
        page_7->setObjectName(QStringLiteral("page_7"));
        page_7->setGeometry(QRect(0, 0, 96, 275));
        sizePolicy2.setHeightForWidth(page_7->sizePolicy().hasHeightForWidth());
        page_7->setSizePolicy(sizePolicy2);
        verticalLayout_9 = new QVBoxLayout(page_7);
        verticalLayout_9->setSpacing(0);
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        btnToolWidgets = new QToolButton(page_7);
        btnToolWidgets->setObjectName(QStringLiteral("btnToolWidgets"));
        sizePolicy2.setHeightForWidth(btnToolWidgets->sizePolicy().hasHeightForWidth());
        btnToolWidgets->setSizePolicy(sizePolicy2);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/options/widgets.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnToolWidgets->setIcon(icon4);
        btnToolWidgets->setIconSize(QSize(32, 32));
        btnToolWidgets->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnToolWidgets->setAutoRaise(true);

        verticalLayout_9->addWidget(btnToolWidgets);

        btnToolTle = new QToolButton(page_7);
        btnToolTle->setObjectName(QStringLiteral("btnToolTle"));
        sizePolicy2.setHeightForWidth(btnToolTle->sizePolicy().hasHeightForWidth());
        btnToolTle->setSizePolicy(sizePolicy2);
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/actions/reload.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnToolTle->setIcon(icon5);
        btnToolTle->setIconSize(QSize(32, 32));
        btnToolTle->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnToolTle->setAutoRaise(true);

        verticalLayout_9->addWidget(btnToolTle);

        btnToolMap = new QToolButton(page_7);
        btnToolMap->setObjectName(QStringLiteral("btnToolMap"));
        sizePolicy2.setHeightForWidth(btnToolMap->sizePolicy().hasHeightForWidth());
        btnToolMap->setSizePolicy(sizePolicy2);
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/options/mapsettings.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnToolMap->setIcon(icon6);
        btnToolMap->setIconSize(QSize(32, 32));
        btnToolMap->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnToolMap->setAutoRaise(true);

        verticalLayout_9->addWidget(btnToolMap);

        btnToolSettings = new QToolButton(page_7);
        btnToolSettings->setObjectName(QStringLiteral("btnToolSettings"));
        sizePolicy2.setHeightForWidth(btnToolSettings->sizePolicy().hasHeightForWidth());
        btnToolSettings->setSizePolicy(sizePolicy2);
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/options/configure.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnToolSettings->setIcon(icon7);
        btnToolSettings->setIconSize(QSize(32, 32));
        btnToolSettings->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnToolSettings->setAutoRaise(true);

        verticalLayout_9->addWidget(btnToolSettings);

        btnInfo = new QToolButton(page_7);
        btnInfo->setObjectName(QStringLiteral("btnInfo"));
        sizePolicy2.setHeightForWidth(btnInfo->sizePolicy().hasHeightForWidth());
        btnInfo->setSizePolicy(sizePolicy2);
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/options/info.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnInfo->setIcon(icon8);
        btnInfo->setIconSize(QSize(32, 32));
        btnInfo->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnInfo->setAutoRaise(true);

        verticalLayout_9->addWidget(btnInfo);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_3);

        toolBox->addItem(page_7, QStringLiteral("Settings"));

        verticalLayout_7->addWidget(toolBox);


        horizontalLayout_2->addWidget(wgtTool);

        stackedWidget = new QStackedWidget(Dialog);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        sizePolicy2.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy2);
        stackedWidget->setMinimumSize(QSize(0, 0));
        stackedWidget->setMaximumSize(QSize(16777215, 16777215));
        stackedWidget->setBaseSize(QSize(0, 0));
        stackedWidget->setLayoutDirection(Qt::LeftToRight);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        verticalLayout = new QVBoxLayout(page);
#ifndef Q_OS_MAC
        verticalLayout->setSpacing(6);
#endif
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widget = new QWidget(page);
        widget->setObjectName(QStringLiteral("widget"));
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        listViewDBSat = new QListView(widget);
        listViewDBSat->setObjectName(QStringLiteral("listViewDBSat"));
        sizePolicy1.setHeightForWidth(listViewDBSat->sizePolicy().hasHeightForWidth());
        listViewDBSat->setSizePolicy(sizePolicy1);
        listViewDBSat->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listViewDBSat->setSelectionMode(QAbstractItemView::ExtendedSelection);

        gridLayout_2->addWidget(listViewDBSat, 0, 0, 1, 1);

        listViewSat = new QListView(widget);
        listViewSat->setObjectName(QStringLiteral("listViewSat"));
        sizePolicy1.setHeightForWidth(listViewSat->sizePolicy().hasHeightForWidth());
        listViewSat->setSizePolicy(sizePolicy1);
        listViewSat->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listViewSat->setSelectionMode(QAbstractItemView::ExtendedSelection);

        gridLayout_2->addWidget(listViewSat, 0, 1, 1, 1);

        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        sizePolicy2.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy2);
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btnOpenTle = new QToolButton(widget_2);
        btnOpenTle->setObjectName(QStringLiteral("btnOpenTle"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/actions/fileopen.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnOpenTle->setIcon(icon9);
        btnOpenTle->setAutoRaise(true);

        horizontalLayout->addWidget(btnOpenTle);

        btnDeleteDbSat = new QToolButton(widget_2);
        btnDeleteDbSat->setObjectName(QStringLiteral("btnDeleteDbSat"));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/actions/remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnDeleteDbSat->setIcon(icon10);
        btnDeleteDbSat->setAutoRaise(true);

        horizontalLayout->addWidget(btnDeleteDbSat);

        btnClearDbSat = new QToolButton(widget_2);
        btnClearDbSat->setObjectName(QStringLiteral("btnClearDbSat"));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/actions/14_layer_deletelayer.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnClearDbSat->setIcon(icon11);
        btnClearDbSat->setAutoRaise(true);

        horizontalLayout->addWidget(btnClearDbSat);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        btnAddToSatList = new QToolButton(widget_2);
        btnAddToSatList->setObjectName(QStringLiteral("btnAddToSatList"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(btnAddToSatList->sizePolicy().hasHeightForWidth());
        btnAddToSatList->setSizePolicy(sizePolicy3);
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/list/1rightarrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnAddToSatList->setIcon(icon12);
        btnAddToSatList->setAutoRaise(true);

        horizontalLayout->addWidget(btnAddToSatList);


        gridLayout_2->addWidget(widget_2, 1, 0, 1, 1);

        widget_7 = new QWidget(widget);
        widget_7->setObjectName(QStringLiteral("widget_7"));
        horizontalLayout_6 = new QHBoxLayout(widget_7);
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        btnChangeDbSat = new QToolButton(widget_7);
        btnChangeDbSat->setObjectName(QStringLiteral("btnChangeDbSat"));
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/actions/tooloptions.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnChangeDbSat->setIcon(icon13);
        btnChangeDbSat->setAutoRaise(true);

        horizontalLayout_6->addWidget(btnChangeDbSat);

        btnDeleteSatList = new QToolButton(widget_7);
        btnDeleteSatList->setObjectName(QStringLiteral("btnDeleteSatList"));
        sizePolicy3.setHeightForWidth(btnDeleteSatList->sizePolicy().hasHeightForWidth());
        btnDeleteSatList->setSizePolicy(sizePolicy3);
        btnDeleteSatList->setIcon(icon10);
        btnDeleteSatList->setAutoRaise(true);

        horizontalLayout_6->addWidget(btnDeleteSatList);

        btnClearSatList = new QToolButton(widget_7);
        btnClearSatList->setObjectName(QStringLiteral("btnClearSatList"));
        btnClearSatList->setIcon(icon11);
        btnClearSatList->setAutoRaise(true);

        horizontalLayout_6->addWidget(btnClearSatList);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);


        gridLayout_2->addWidget(widget_7, 1, 1, 1, 1);


        verticalLayout->addWidget(widget);

        tabWidget = new QTabWidget(page);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setEnabled(true);
        sizePolicy2.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy2);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_6 = new QGridLayout(tab);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        labelSatFind = new QLabel(tab);
        labelSatFind->setObjectName(QStringLiteral("labelSatFind"));

        gridLayout_6->addWidget(labelSatFind, 0, 0, 1, 1);

        lineEditSatNameFilter = new QLineEdit(tab);
        lineEditSatNameFilter->setObjectName(QStringLiteral("lineEditSatNameFilter"));

        gridLayout_6->addWidget(lineEditSatNameFilter, 1, 0, 1, 3);

        labelSatName = new QLabel(tab);
        labelSatName->setObjectName(QStringLiteral("labelSatName"));

        gridLayout_6->addWidget(labelSatName, 2, 0, 1, 1);

        lineEditSatName = new QLineEdit(tab);
        lineEditSatName->setObjectName(QStringLiteral("lineEditSatName"));
        lineEditSatName->setReadOnly(true);

        gridLayout_6->addWidget(lineEditSatName, 3, 0, 1, 2);

        lineEditSatGroup = new QLineEdit(tab);
        lineEditSatGroup->setObjectName(QStringLiteral("lineEditSatGroup"));
        lineEditSatGroup->setReadOnly(true);

        gridLayout_6->addWidget(lineEditSatGroup, 3, 2, 1, 3);

        labelSatFilter = new QLabel(tab);
        labelSatFilter->setObjectName(QStringLiteral("labelSatFilter"));

        gridLayout_6->addWidget(labelSatFilter, 4, 0, 1, 1);

        lineEditSatFilter = new QLineEdit(tab);
        lineEditSatFilter->setObjectName(QStringLiteral("lineEditSatFilter"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(lineEditSatFilter->sizePolicy().hasHeightForWidth());
        lineEditSatFilter->setSizePolicy(sizePolicy4);

        gridLayout_6->addWidget(lineEditSatFilter, 5, 0, 1, 3);

        btnSatSqlHelp = new QToolButton(tab);
        btnSatSqlHelp->setObjectName(QStringLiteral("btnSatSqlHelp"));
        btnSatSqlHelp->setAutoRaise(true);

        gridLayout_6->addWidget(btnSatSqlHelp, 5, 4, 1, 1);

        btnSatFilter = new QToolButton(tab);
        btnSatFilter->setObjectName(QStringLiteral("btnSatFilter"));
        btnSatFilter->setCheckable(true);
        btnSatFilter->setAutoRaise(true);

        gridLayout_6->addWidget(btnSatFilter, 5, 3, 1, 1);

        labelSatGroup = new QLabel(tab);
        labelSatGroup->setObjectName(QStringLiteral("labelSatGroup"));

        gridLayout_6->addWidget(labelSatGroup, 2, 2, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout = new QGridLayout(tab_2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        labelI = new QLabel(tab_2);
        labelI->setObjectName(QStringLiteral("labelI"));

        gridLayout->addWidget(labelI, 0, 0, 1, 1);

        labelOmg = new QLabel(tab_2);
        labelOmg->setObjectName(QStringLiteral("labelOmg"));

        gridLayout->addWidget(labelOmg, 0, 1, 1, 1);

        lineEditSatI = new QLineEdit(tab_2);
        lineEditSatI->setObjectName(QStringLiteral("lineEditSatI"));
        lineEditSatI->setReadOnly(true);

        gridLayout->addWidget(lineEditSatI, 1, 0, 1, 1);

        lineEditSatOmg = new QLineEdit(tab_2);
        lineEditSatOmg->setObjectName(QStringLiteral("lineEditSatOmg"));
        lineEditSatOmg->setReadOnly(true);

        gridLayout->addWidget(lineEditSatOmg, 1, 1, 1, 1);

        labelW = new QLabel(tab_2);
        labelW->setObjectName(QStringLiteral("labelW"));

        gridLayout->addWidget(labelW, 2, 0, 1, 1);

        labelM0 = new QLabel(tab_2);
        labelM0->setObjectName(QStringLiteral("labelM0"));

        gridLayout->addWidget(labelM0, 2, 1, 1, 1);

        lineEditSatW = new QLineEdit(tab_2);
        lineEditSatW->setObjectName(QStringLiteral("lineEditSatW"));
        lineEditSatW->setReadOnly(true);

        gridLayout->addWidget(lineEditSatW, 3, 0, 1, 1);

        lineEditSatM0 = new QLineEdit(tab_2);
        lineEditSatM0->setObjectName(QStringLiteral("lineEditSatM0"));
        lineEditSatM0->setReadOnly(true);

        gridLayout->addWidget(lineEditSatM0, 3, 1, 1, 1);

        lineEditSatE = new QLineEdit(tab_2);
        lineEditSatE->setObjectName(QStringLiteral("lineEditSatE"));
        lineEditSatE->setReadOnly(true);

        gridLayout->addWidget(lineEditSatE, 1, 2, 1, 1);

        labelE = new QLabel(tab_2);
        labelE->setObjectName(QStringLiteral("labelE"));

        gridLayout->addWidget(labelE, 0, 2, 1, 1);

        lineEditSatN = new QLineEdit(tab_2);
        lineEditSatN->setObjectName(QStringLiteral("lineEditSatN"));
        lineEditSatN->setReadOnly(true);

        gridLayout->addWidget(lineEditSatN, 3, 2, 1, 1);

        labelN = new QLabel(tab_2);
        labelN->setObjectName(QStringLiteral("labelN"));

        gridLayout->addWidget(labelN, 2, 2, 1, 1);

        lineEditSatBStar = new QLineEdit(tab_2);
        lineEditSatBStar->setObjectName(QStringLiteral("lineEditSatBStar"));
        lineEditSatBStar->setReadOnly(true);

        gridLayout->addWidget(lineEditSatBStar, 5, 0, 1, 1);

        labelB = new QLabel(tab_2);
        labelB->setObjectName(QStringLiteral("labelB"));

        gridLayout->addWidget(labelB, 4, 0, 1, 1);

        lineEditSatTime = new QLineEdit(tab_2);
        lineEditSatTime->setObjectName(QStringLiteral("lineEditSatTime"));
        lineEditSatTime->setReadOnly(true);

        gridLayout->addWidget(lineEditSatTime, 5, 1, 1, 2);

        labelSatTime = new QLabel(tab_2);
        labelSatTime->setObjectName(QStringLiteral("labelSatTime"));

        gridLayout->addWidget(labelSatTime, 4, 1, 1, 1);

        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);

        stackedWidget->addWidget(page);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        verticalLayout_2 = new QVBoxLayout(page_3);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        widget_3 = new QWidget(page_3);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        sizePolicy1.setHeightForWidth(widget_3->sizePolicy().hasHeightForWidth());
        widget_3->setSizePolicy(sizePolicy1);
        gridLayout_7 = new QGridLayout(widget_3);
        gridLayout_7->setSpacing(0);
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        listViewDBLoc = new QListView(widget_3);
        listViewDBLoc->setObjectName(QStringLiteral("listViewDBLoc"));
        sizePolicy1.setHeightForWidth(listViewDBLoc->sizePolicy().hasHeightForWidth());
        listViewDBLoc->setSizePolicy(sizePolicy1);
        listViewDBLoc->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listViewDBLoc->setSelectionMode(QAbstractItemView::ExtendedSelection);

        gridLayout_7->addWidget(listViewDBLoc, 0, 0, 1, 1);

        listViewLoc = new QListView(widget_3);
        listViewLoc->setObjectName(QStringLiteral("listViewLoc"));
        sizePolicy1.setHeightForWidth(listViewLoc->sizePolicy().hasHeightForWidth());
        listViewLoc->setSizePolicy(sizePolicy1);
        listViewLoc->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listViewLoc->setSelectionMode(QAbstractItemView::ExtendedSelection);

        gridLayout_7->addWidget(listViewLoc, 0, 1, 1, 1);

        widget_8 = new QWidget(widget_3);
        widget_8->setObjectName(QStringLiteral("widget_8"));
        sizePolicy2.setHeightForWidth(widget_8->sizePolicy().hasHeightForWidth());
        widget_8->setSizePolicy(sizePolicy2);
        horizontalLayout_4 = new QHBoxLayout(widget_8);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        btnChangeDbLoc = new QToolButton(widget_8);
        btnChangeDbLoc->setObjectName(QStringLiteral("btnChangeDbLoc"));
        btnChangeDbLoc->setIcon(icon13);
        btnChangeDbLoc->setAutoRaise(true);

        horizontalLayout_4->addWidget(btnChangeDbLoc);

        btnDeleteLocList = new QToolButton(widget_8);
        btnDeleteLocList->setObjectName(QStringLiteral("btnDeleteLocList"));
        sizePolicy3.setHeightForWidth(btnDeleteLocList->sizePolicy().hasHeightForWidth());
        btnDeleteLocList->setSizePolicy(sizePolicy3);
        btnDeleteLocList->setIcon(icon10);
        btnDeleteLocList->setAutoRaise(true);

        horizontalLayout_4->addWidget(btnDeleteLocList);

        btnClearLocList = new QToolButton(widget_8);
        btnClearLocList->setObjectName(QStringLiteral("btnClearLocList"));
        btnClearLocList->setIcon(icon11);
        btnClearLocList->setAutoRaise(true);

        horizontalLayout_4->addWidget(btnClearLocList);

        horizontalSpacer_4 = new QSpacerItem(157, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);


        gridLayout_7->addWidget(widget_8, 1, 1, 1, 1);

        widget_4 = new QWidget(widget_3);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setLayoutDirection(Qt::RightToLeft);
        horizontalLayout_3 = new QHBoxLayout(widget_4);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        btnAddToLocList = new QToolButton(widget_4);
        btnAddToLocList->setObjectName(QStringLiteral("btnAddToLocList"));
        sizePolicy3.setHeightForWidth(btnAddToLocList->sizePolicy().hasHeightForWidth());
        btnAddToLocList->setSizePolicy(sizePolicy3);
        btnAddToLocList->setIcon(icon12);
        btnAddToLocList->setAutoRaise(true);

        horizontalLayout_3->addWidget(btnAddToLocList);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        btnClearDbLoc = new QToolButton(widget_4);
        btnClearDbLoc->setObjectName(QStringLiteral("btnClearDbLoc"));
        btnClearDbLoc->setIcon(icon11);
        btnClearDbLoc->setAutoRaise(true);

        horizontalLayout_3->addWidget(btnClearDbLoc);

        btnDeleteDbLoc = new QToolButton(widget_4);
        btnDeleteDbLoc->setObjectName(QStringLiteral("btnDeleteDbLoc"));
        btnDeleteDbLoc->setIcon(icon10);
        btnDeleteDbLoc->setAutoRaise(true);

        horizontalLayout_3->addWidget(btnDeleteDbLoc);

        btnAddDbLoc = new QToolButton(widget_4);
        btnAddDbLoc->setObjectName(QStringLiteral("btnAddDbLoc"));
        QIcon icon14;
        icon14.addFile(QStringLiteral(":/actions/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnAddDbLoc->setIcon(icon14);
        btnAddDbLoc->setAutoRaise(true);

        horizontalLayout_3->addWidget(btnAddDbLoc);

        btnOpenLoc = new QToolButton(widget_4);
        btnOpenLoc->setObjectName(QStringLiteral("btnOpenLoc"));
        btnOpenLoc->setIcon(icon9);
        btnOpenLoc->setAutoRaise(true);

        horizontalLayout_3->addWidget(btnOpenLoc);


        gridLayout_7->addWidget(widget_4, 1, 0, 1, 1);


        verticalLayout_2->addWidget(widget_3);

        tabWidget_2 = new QTabWidget(page_3);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        sizePolicy2.setHeightForWidth(tabWidget_2->sizePolicy().hasHeightForWidth());
        tabWidget_2->setSizePolicy(sizePolicy2);
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        gridLayout_4 = new QGridLayout(tab_4);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        lineEditLocNameFilter = new QLineEdit(tab_4);
        lineEditLocNameFilter->setObjectName(QStringLiteral("lineEditLocNameFilter"));

        gridLayout_4->addWidget(lineEditLocNameFilter, 1, 0, 1, 1);

        lineEditLocName = new QLineEdit(tab_4);
        lineEditLocName->setObjectName(QStringLiteral("lineEditLocName"));

        gridLayout_4->addWidget(lineEditLocName, 1, 1, 1, 3);

        lineEditLocFilter = new QLineEdit(tab_4);
        lineEditLocFilter->setObjectName(QStringLiteral("lineEditLocFilter"));

        gridLayout_4->addWidget(lineEditLocFilter, 3, 0, 1, 2);

        labelLocFind = new QLabel(tab_4);
        labelLocFind->setObjectName(QStringLiteral("labelLocFind"));

        gridLayout_4->addWidget(labelLocFind, 0, 0, 1, 1);

        labelLocName = new QLabel(tab_4);
        labelLocName->setObjectName(QStringLiteral("labelLocName"));

        gridLayout_4->addWidget(labelLocName, 0, 1, 1, 1);

        labelLocFilter = new QLabel(tab_4);
        labelLocFilter->setObjectName(QStringLiteral("labelLocFilter"));

        gridLayout_4->addWidget(labelLocFilter, 2, 0, 1, 1);

        btnLocSqlHelp = new QToolButton(tab_4);
        btnLocSqlHelp->setObjectName(QStringLiteral("btnLocSqlHelp"));
        btnLocSqlHelp->setCheckable(false);
        btnLocSqlHelp->setAutoRaise(true);

        gridLayout_4->addWidget(btnLocSqlHelp, 3, 3, 1, 1);

        btnLocFilter = new QToolButton(tab_4);
        btnLocFilter->setObjectName(QStringLiteral("btnLocFilter"));
        btnLocFilter->setCheckable(true);
        btnLocFilter->setAutoRaise(true);

        gridLayout_4->addWidget(btnLocFilter, 3, 2, 1, 1);

        tabWidget_2->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        gridLayout_5 = new QGridLayout(tab_5);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        lineEditLocLat = new QLineEdit(tab_5);
        lineEditLocLat->setObjectName(QStringLiteral("lineEditLocLat"));

        gridLayout_5->addWidget(lineEditLocLat, 4, 0, 1, 1);

        lineEditLocLon = new QLineEdit(tab_5);
        lineEditLocLon->setObjectName(QStringLiteral("lineEditLocLon"));

        gridLayout_5->addWidget(lineEditLocLon, 4, 1, 1, 1);

        lineEditLocHeight = new QLineEdit(tab_5);
        lineEditLocHeight->setObjectName(QStringLiteral("lineEditLocHeight"));

        gridLayout_5->addWidget(lineEditLocHeight, 4, 2, 1, 1);

        lineEditLocAzimuth = new QLineEdit(tab_5);
        lineEditLocAzimuth->setObjectName(QStringLiteral("lineEditLocAzimuth"));

        gridLayout_5->addWidget(lineEditLocAzimuth, 6, 0, 1, 1);

        lineEditLocWidth = new QLineEdit(tab_5);
        lineEditLocWidth->setObjectName(QStringLiteral("lineEditLocWidth"));

        gridLayout_5->addWidget(lineEditLocWidth, 6, 1, 1, 1);

        lineEditLocRange = new QLineEdit(tab_5);
        lineEditLocRange->setObjectName(QStringLiteral("lineEditLocRange"));

        gridLayout_5->addWidget(lineEditLocRange, 6, 2, 1, 1);

        labelAzimuth = new QLabel(tab_5);
        labelAzimuth->setObjectName(QStringLiteral("labelAzimuth"));

        gridLayout_5->addWidget(labelAzimuth, 5, 0, 1, 1);

        labelLat = new QLabel(tab_5);
        labelLat->setObjectName(QStringLiteral("labelLat"));

        gridLayout_5->addWidget(labelLat, 3, 1, 1, 1);

        labelLon = new QLabel(tab_5);
        labelLon->setObjectName(QStringLiteral("labelLon"));

        gridLayout_5->addWidget(labelLon, 3, 0, 1, 1);

        labelHeight = new QLabel(tab_5);
        labelHeight->setObjectName(QStringLiteral("labelHeight"));

        gridLayout_5->addWidget(labelHeight, 3, 2, 1, 1);

        labelWidth = new QLabel(tab_5);
        labelWidth->setObjectName(QStringLiteral("labelWidth"));

        gridLayout_5->addWidget(labelWidth, 5, 1, 1, 1);

        labelRange = new QLabel(tab_5);
        labelRange->setObjectName(QStringLiteral("labelRange"));

        gridLayout_5->addWidget(labelRange, 5, 2, 1, 1);

        tabWidget_2->addTab(tab_5, QString());

        verticalLayout_2->addWidget(tabWidget_2);

        stackedWidget->addWidget(page_3);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        verticalLayout_3 = new QVBoxLayout(page_2);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        textZRVList = new QTextEdit(page_2);
        textZRVList->setObjectName(QStringLiteral("textZRVList"));
        textZRVList->setReadOnly(true);

        verticalLayout_3->addWidget(textZRVList);

        btnClearZrvList = new QPushButton(page_2);
        btnClearZrvList->setObjectName(QStringLiteral("btnClearZrvList"));

        verticalLayout_3->addWidget(btnClearZrvList);

        stackedWidget->addWidget(page_2);
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        verticalLayout_10 = new QVBoxLayout(page_4);
        verticalLayout_10->setSpacing(0);
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        teAbout = new QTextEdit(page_4);
        teAbout->setObjectName(QStringLiteral("teAbout"));
        teAbout->setReadOnly(true);
        teAbout->setHtml(QLatin1String("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><img src=\":/options/satviewer.png\" /><span style=\" font-size:8pt;\"> </span><span style=\" font-size:36pt; font-weight:600;\">SatViewer</span><span style=\" font-size:8pt;\"> </span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:18pt;\">satellite tracking tool</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><"
                        "span style=\" font-size:18pt;\">version 201</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:18pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Website:	</span><a href=\"http://satviewer.net\"><span style=\" font-size:8pt; text-decoration: underline; color:#0000ff;\">http://satviewer.net</span></a></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Forum:	</span><a href=\"http://groups.google.com/group/satviewer\"><span style=\" font-size:8pt; text-decoration: underline; color:#0000ff;\">http://groups.google.com/group/satviewer</span></a></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px"
                        ";\"><span style=\" font-size:8pt;\">Mail:	</span><a href=\"mailto:coduemat@gmail.com\"><span style=\" font-size:8pt; text-decoration: underline; color:#0000ff;\">coduemat@gmail.com</span></a></p></body></html>"));
        teAbout->setAcceptRichText(false);
        teAbout->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse|Qt::TextBrowserInteraction|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        verticalLayout_10->addWidget(teAbout);

        widget_5 = new QWidget(page_4);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        horizontalLayout_5 = new QHBoxLayout(widget_5);
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        btnAboutQt = new QPushButton(widget_5);
        btnAboutQt->setObjectName(QStringLiteral("btnAboutQt"));

        horizontalLayout_5->addWidget(btnAboutQt);


        verticalLayout_10->addWidget(widget_5);

        stackedWidget->addWidget(page_4);

        horizontalLayout_2->addWidget(stackedWidget);

#ifndef QT_NO_SHORTCUT
        labelSatFind->setBuddy(lineEditSatNameFilter);
        labelSatName->setBuddy(lineEditSatName);
        labelSatFilter->setBuddy(lineEditSatFilter);
        labelSatGroup->setBuddy(lineEditSatGroup);
        labelI->setBuddy(lineEditSatI);
        labelOmg->setBuddy(lineEditSatOmg);
        labelW->setBuddy(lineEditSatW);
        labelM0->setBuddy(lineEditSatM0);
        labelE->setBuddy(lineEditSatE);
        labelN->setBuddy(lineEditSatN);
        labelB->setBuddy(lineEditSatBStar);
        labelSatTime->setBuddy(lineEditSatTime);
        labelLocFind->setBuddy(lineEditLocNameFilter);
        labelLocName->setBuddy(lineEditLocName);
        labelLocFilter->setBuddy(lineEditLocFilter);
        labelAzimuth->setBuddy(lineEditLocAzimuth);
        labelLat->setBuddy(lineEditLocLon);
        labelLon->setBuddy(lineEditLocLat);
        labelHeight->setBuddy(lineEditLocHeight);
        labelWidth->setBuddy(lineEditLocWidth);
        labelRange->setBuddy(lineEditLocRange);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(listViewDBSat, listViewSat);
        QWidget::setTabOrder(listViewSat, tabWidget);
        QWidget::setTabOrder(tabWidget, lineEditSatNameFilter);
        QWidget::setTabOrder(lineEditSatNameFilter, lineEditSatName);
        QWidget::setTabOrder(lineEditSatName, lineEditSatGroup);
        QWidget::setTabOrder(lineEditSatGroup, lineEditSatFilter);
        QWidget::setTabOrder(lineEditSatFilter, btnSatSqlHelp);
        QWidget::setTabOrder(btnSatSqlHelp, btnSatFilter);
        QWidget::setTabOrder(btnSatFilter, lineEditSatI);
        QWidget::setTabOrder(lineEditSatI, lineEditSatOmg);
        QWidget::setTabOrder(lineEditSatOmg, lineEditSatE);
        QWidget::setTabOrder(lineEditSatE, lineEditSatW);
        QWidget::setTabOrder(lineEditSatW, lineEditSatM0);
        QWidget::setTabOrder(lineEditSatM0, lineEditSatN);
        QWidget::setTabOrder(lineEditSatN, lineEditSatBStar);
        QWidget::setTabOrder(lineEditSatBStar, lineEditSatTime);
        QWidget::setTabOrder(lineEditSatTime, listViewDBLoc);
        QWidget::setTabOrder(listViewDBLoc, listViewLoc);
        QWidget::setTabOrder(listViewLoc, tabWidget_2);
        QWidget::setTabOrder(tabWidget_2, lineEditLocNameFilter);
        QWidget::setTabOrder(lineEditLocNameFilter, lineEditLocName);
        QWidget::setTabOrder(lineEditLocName, lineEditLocFilter);
        QWidget::setTabOrder(lineEditLocFilter, btnLocFilter);
        QWidget::setTabOrder(btnLocFilter, btnLocSqlHelp);
        QWidget::setTabOrder(btnLocSqlHelp, lineEditLocWidth);
        QWidget::setTabOrder(lineEditLocWidth, lineEditLocRange);
        QWidget::setTabOrder(lineEditLocRange, lineEditLocAzimuth);
        QWidget::setTabOrder(lineEditLocAzimuth, lineEditLocLat);
        QWidget::setTabOrder(lineEditLocLat, lineEditLocLon);
        QWidget::setTabOrder(lineEditLocLon, lineEditLocHeight);
        QWidget::setTabOrder(lineEditLocHeight, textZRVList);
        QWidget::setTabOrder(textZRVList, btnToolMap);
        QWidget::setTabOrder(btnToolMap, btnToolSettings);
        QWidget::setTabOrder(btnToolSettings, btnInfo);
        QWidget::setTabOrder(btnInfo, btnOpenTle);
        QWidget::setTabOrder(btnOpenTle, btnDeleteDbSat);
        QWidget::setTabOrder(btnDeleteDbSat, btnClearDbSat);
        QWidget::setTabOrder(btnClearDbSat, btnOpenLoc);
        QWidget::setTabOrder(btnOpenLoc, btnAddDbLoc);
        QWidget::setTabOrder(btnAddDbLoc, btnDeleteDbLoc);
        QWidget::setTabOrder(btnDeleteDbLoc, btnClearDbLoc);
        QWidget::setTabOrder(btnClearDbLoc, btnClearZrvList);
        QWidget::setTabOrder(btnClearZrvList, btnToolLoc);
        QWidget::setTabOrder(btnToolLoc, btnToolZRV);
        QWidget::setTabOrder(btnToolZRV, btnToolParams);
        QWidget::setTabOrder(btnToolParams, btnToolWidgets);
        QWidget::setTabOrder(btnToolWidgets, btnToolTle);
        QWidget::setTabOrder(btnToolTle, btnToolSat);
        QWidget::setTabOrder(btnToolSat, btnAddToSatList);
        QWidget::setTabOrder(btnAddToSatList, btnChangeDbSat);
        QWidget::setTabOrder(btnChangeDbSat, btnDeleteSatList);
        QWidget::setTabOrder(btnDeleteSatList, btnClearSatList);
        QWidget::setTabOrder(btnClearSatList, btnChangeDbLoc);
        QWidget::setTabOrder(btnChangeDbLoc, btnDeleteLocList);
        QWidget::setTabOrder(btnDeleteLocList, btnClearLocList);
        QWidget::setTabOrder(btnClearLocList, btnAddToLocList);
        QWidget::setTabOrder(btnAddToLocList, teAbout);
        QWidget::setTabOrder(teAbout, btnAboutQt);

        retranslateUi(Dialog);
        QObject::connect(btnClearZrvList, SIGNAL(clicked()), textZRVList, SLOT(clear()));

        toolBox->setCurrentIndex(0);
        stackedWidget->setCurrentIndex(0);
        tabWidget->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Options", 0));
        btnToolSat->setText(QApplication::translate("Dialog", "Satellites", 0));
        btnToolLoc->setText(QApplication::translate("Dialog", "Locations", 0));
        toolBox->setItemText(toolBox->indexOf(page_5), QApplication::translate("Dialog", "Objects", 0));
        btnToolZRV->setText(QApplication::translate("Dialog", "Footprint", 0));
        btnToolParams->setText(QApplication::translate("Dialog", "Parameters", 0));
        toolBox->setItemText(toolBox->indexOf(page_6), QApplication::translate("Dialog", "Data", 0));
        btnToolWidgets->setText(QApplication::translate("Dialog", "Widgets", 0));
        btnToolTle->setText(QApplication::translate("Dialog", "TLE", 0));
        btnToolMap->setText(QApplication::translate("Dialog", "Map", 0));
        btnToolSettings->setText(QApplication::translate("Dialog", "Settings", 0));
        btnInfo->setText(QApplication::translate("Dialog", "?", 0));
        toolBox->setItemText(toolBox->indexOf(page_7), QApplication::translate("Dialog", "Settings", 0));
#ifndef QT_NO_TOOLTIP
        btnOpenTle->setToolTip(QApplication::translate("Dialog", "Open TLE File", 0));
#endif // QT_NO_TOOLTIP
        btnOpenTle->setShortcut(QString());
#ifndef QT_NO_TOOLTIP
        btnDeleteDbSat->setToolTip(QApplication::translate("Dialog", "Remove", 0));
#endif // QT_NO_TOOLTIP
        btnDeleteDbSat->setShortcut(QString());
#ifndef QT_NO_TOOLTIP
        btnClearDbSat->setToolTip(QApplication::translate("Dialog", "Remove All", 0));
#endif // QT_NO_TOOLTIP
        btnClearDbSat->setShortcut(QString());
#ifndef QT_NO_TOOLTIP
        btnAddToSatList->setToolTip(QApplication::translate("Dialog", "View", 0));
#endif // QT_NO_TOOLTIP
        btnAddToSatList->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnChangeDbSat->setToolTip(QApplication::translate("Dialog", "Edit", 0));
#endif // QT_NO_TOOLTIP
        btnChangeDbSat->setText(QString());
        btnChangeDbSat->setShortcut(QString());
#ifndef QT_NO_TOOLTIP
        btnDeleteSatList->setToolTip(QApplication::translate("Dialog", "Remove", 0));
#endif // QT_NO_TOOLTIP
        btnDeleteSatList->setText(QString());
        btnDeleteSatList->setShortcut(QString());
#ifndef QT_NO_TOOLTIP
        btnClearSatList->setToolTip(QApplication::translate("Dialog", "Remove All", 0));
#endif // QT_NO_TOOLTIP
        btnClearSatList->setText(QString());
        btnClearSatList->setShortcut(QString());
        labelSatFind->setText(QApplication::translate("Dialog", "Name Search", 0));
        labelSatName->setText(QApplication::translate("Dialog", "Name", 0));
        labelSatFilter->setText(QApplication::translate("Dialog", "SQL filter", 0));
        btnSatSqlHelp->setText(QApplication::translate("Dialog", "?", 0));
        btnSatFilter->setText(QApplication::translate("Dialog", "on", 0));
        labelSatGroup->setText(QApplication::translate("Dialog", "Group", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Dialog", "Selection", 0));
        labelI->setText(QApplication::translate("Dialog", "Inclination", 0));
        labelOmg->setText(QApplication::translate("Dialog", "Ascending node", 0));
        labelW->setText(QApplication::translate("Dialog", "Arg. perigee lat.", 0));
        labelM0->setText(QApplication::translate("Dialog", "Mean anomaly", 0));
        labelE->setText(QApplication::translate("Dialog", "Eccentricity", 0));
        labelN->setText(QApplication::translate("Dialog", "Mean motion", 0));
        labelB->setText(QApplication::translate("Dialog", "Ballistic coeff.", 0));
        labelSatTime->setText(QApplication::translate("Dialog", "Timestamp", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Dialog", "Orbital", 0));
#ifndef QT_NO_TOOLTIP
        btnChangeDbLoc->setToolTip(QApplication::translate("Dialog", "Edit", 0));
#endif // QT_NO_TOOLTIP
        btnChangeDbLoc->setText(QString());
        btnChangeDbLoc->setShortcut(QString());
#ifndef QT_NO_TOOLTIP
        btnDeleteLocList->setToolTip(QApplication::translate("Dialog", "Remove", 0));
#endif // QT_NO_TOOLTIP
        btnDeleteLocList->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnClearLocList->setToolTip(QApplication::translate("Dialog", "Remove All", 0));
#endif // QT_NO_TOOLTIP
        btnClearLocList->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnAddToLocList->setToolTip(QApplication::translate("Dialog", "View", 0));
#endif // QT_NO_TOOLTIP
        btnAddToLocList->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnClearDbLoc->setToolTip(QApplication::translate("Dialog", "Remove All", 0));
#endif // QT_NO_TOOLTIP
        btnClearDbLoc->setText(QString());
        btnClearDbLoc->setShortcut(QString());
#ifndef QT_NO_TOOLTIP
        btnDeleteDbLoc->setToolTip(QApplication::translate("Dialog", "Remove", 0));
#endif // QT_NO_TOOLTIP
        btnDeleteDbLoc->setText(QString());
        btnDeleteDbLoc->setShortcut(QString());
#ifndef QT_NO_TOOLTIP
        btnAddDbLoc->setToolTip(QApplication::translate("Dialog", "Add", 0));
#endif // QT_NO_TOOLTIP
        btnAddDbLoc->setText(QString());
        btnAddDbLoc->setShortcut(QString());
#ifndef QT_NO_TOOLTIP
        btnOpenLoc->setToolTip(QApplication::translate("Dialog", "Open Locations", 0));
#endif // QT_NO_TOOLTIP
        btnOpenLoc->setText(QString());
        btnOpenLoc->setShortcut(QString());
        labelLocFind->setText(QApplication::translate("Dialog", "Name Search", 0));
        labelLocName->setText(QApplication::translate("Dialog", "Name", 0));
        labelLocFilter->setText(QApplication::translate("Dialog", "SQL filter", 0));
        btnLocSqlHelp->setText(QApplication::translate("Dialog", "?", 0));
        btnLocFilter->setText(QApplication::translate("Dialog", "on", 0));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QApplication::translate("Dialog", "Selection", 0));
        labelAzimuth->setText(QApplication::translate("Dialog", "Azimuth", 0));
        labelLat->setText(QApplication::translate("Dialog", "Longitude", 0));
        labelLon->setText(QApplication::translate("Dialog", "Latitude", 0));
        labelHeight->setText(QApplication::translate("Dialog", "Altitude", 0));
        labelWidth->setText(QApplication::translate("Dialog", "Sector", 0));
        labelRange->setText(QApplication::translate("Dialog", "Range", 0));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_5), QApplication::translate("Dialog", "Coordinates", 0));
        btnClearZrvList->setText(QApplication::translate("Dialog", "Clear", 0));
        btnAboutQt->setText(QApplication::translate("Dialog", "About Qt", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONS_H
