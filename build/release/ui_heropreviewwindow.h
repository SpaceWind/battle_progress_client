/********************************************************************************
** Form generated from reading UI file 'heropreviewwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HEROPREVIEWWINDOW_H
#define UI_HEROPREVIEWWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_heroPreviewWindow
{
public:
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QLabel *label_faction;
    QLabel *label_name;
    QLabel *label_level;
    QLabel *label_class;
    QLabel *label_owner;
    QGroupBox *inventar_box;
    QVBoxLayout *verticalLayout;
    QListView *listView_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_hp;
    QLabel *label_mag;
    QLabel *label_vel;
    QLabel *label_15;
    QLabel *label_13;
    QLabel *label_8;
    QLabel *label_7;
    QProgressBar *expbar;
    QProgressBar *manabar;
    QProgressBar *hpbar;
    QLabel *label_str;
    QLabel *label_int;
    QProgressBar *moodbar;
    QLabel *label_dex;
    QLabel *label_tra;
    QLabel *label_mana;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_4;
    QListView *listView;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_5;
    QLabel *map_pixels;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_2;
    QListWidget *listWidget;
    QProgressBar *progressBar_6;
    QLabel *status_line;

    void setupUi(QDialog *heroPreviewWindow)
    {
        if (heroPreviewWindow->objectName().isEmpty())
            heroPreviewWindow->setObjectName(QStringLiteral("heroPreviewWindow"));
        heroPreviewWindow->resize(898, 537);
#ifndef QT_NO_TOOLTIP
        heroPreviewWindow->setToolTip(QStringLiteral(""));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        heroPreviewWindow->setWhatsThis(QStringLiteral(""));
#endif // QT_NO_WHATSTHIS
        gridLayout_3 = new QGridLayout(heroPreviewWindow);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        groupBox_2 = new QGroupBox(heroPreviewWindow);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMaximumSize(QSize(300, 16777215));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_faction = new QLabel(groupBox_2);
        label_faction->setObjectName(QStringLiteral("label_faction"));
        label_faction->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_faction, 4, 0, 1, 2);

        label_name = new QLabel(groupBox_2);
        label_name->setObjectName(QStringLiteral("label_name"));
        label_name->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_name, 0, 0, 1, 2);

        label_level = new QLabel(groupBox_2);
        label_level->setObjectName(QStringLiteral("label_level"));
        label_level->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_level, 5, 0, 1, 2);

        label_class = new QLabel(groupBox_2);
        label_class->setObjectName(QStringLiteral("label_class"));
        label_class->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_class, 3, 0, 1, 2);

        label_owner = new QLabel(groupBox_2);
        label_owner->setObjectName(QStringLiteral("label_owner"));
        label_owner->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_owner, 1, 0, 1, 2);


        gridLayout_3->addWidget(groupBox_2, 0, 0, 1, 1);

        inventar_box = new QGroupBox(heroPreviewWindow);
        inventar_box->setObjectName(QStringLiteral("inventar_box"));
        inventar_box->setFlat(false);
        inventar_box->setCheckable(false);
        verticalLayout = new QVBoxLayout(inventar_box);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        listView_2 = new QListView(inventar_box);
        listView_2->setObjectName(QStringLiteral("listView_2"));

        verticalLayout->addWidget(listView_2);


        gridLayout_3->addWidget(inventar_box, 2, 1, 1, 1);

        groupBox = new QGroupBox(heroPreviewWindow);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMaximumSize(QSize(300, 16777215));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(0);
        gridLayout->setContentsMargins(-1, -1, 9, -1);
        label_hp = new QLabel(groupBox);
        label_hp->setObjectName(QStringLiteral("label_hp"));
        label_hp->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_hp, 9, 0, 1, 4);

        label_mag = new QLabel(groupBox);
        label_mag->setObjectName(QStringLiteral("label_mag"));
        label_mag->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_mag, 3, 0, 1, 4);

        label_vel = new QLabel(groupBox);
        label_vel->setObjectName(QStringLiteral("label_vel"));
        label_vel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_vel, 7, 0, 1, 4);

        label_15 = new QLabel(groupBox);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_15, 16, 0, 1, 1);

        label_13 = new QLabel(groupBox);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_13, 14, 0, 1, 1);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_8, 13, 0, 1, 1);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_7, 12, 0, 1, 1);

        expbar = new QProgressBar(groupBox);
        expbar->setObjectName(QStringLiteral("expbar"));
        expbar->setAutoFillBackground(false);
        expbar->setStyleSheet(QLatin1String("QProgressBar::chunk {\n"
"     background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(194, 161, 27, 236), stop:0.318182 rgba(253, 255, 75, 248), stop:0.505682 rgba(241, 192, 90, 255), stop:0.977273 rgba(189, 145, 8, 230));\n"
"     width: 1px;\n"
" }\n"
"\n"
" QProgressBar {\n"
"     border: 2px solid grey;\n"
"     border-radius: 5px;\n"
"     text-align: right;\n"
"	background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(165, 162, 114, 255), stop:0.318409 rgba(255, 255, 230, 221), stop:1 rgba(156, 123, 123, 255));\n"
"		color: #00f;\n"
"	font-weight: bold;\n"
"     text-align: center;\n"
" }\n"
"\n"
""));
        expbar->setValue(70);
        expbar->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        expbar->setTextVisible(true);
        expbar->setOrientation(Qt::Horizontal);
        expbar->setInvertedAppearance(false);
        expbar->setTextDirection(QProgressBar::TopToBottom);

        gridLayout->addWidget(expbar, 14, 1, 1, 3);

        manabar = new QProgressBar(groupBox);
        manabar->setObjectName(QStringLiteral("manabar"));
        manabar->setMaximumSize(QSize(16777215, 25));
        QFont font;
        font.setPointSize(8);
        font.setBold(true);
        font.setWeight(75);
        manabar->setFont(font);
        manabar->setStyleSheet(QLatin1String("QProgressBar::chunk {\n"
"     background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(27, 67, 194, 236), stop:0.318182 rgba(206, 206, 219, 241), stop:0.505682 rgba(180, 164, 255, 255), stop:0.977273 rgba(15, 15, 189, 230));\n"
"     width: 1px;\n"
" }\n"
"\n"
" QProgressBar {\n"
"     border: 2px solid grey;\n"
"     border-radius: 5px;\n"
"	background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(165, 162, 114, 255), stop:0.318409 rgba(230, 230, 255, 221), stop:1 rgba(156, 123, 123, 255));\n"
"		color: #00A;\n"
"	font-weight: bold;\n"
"     text-align: center;\n"
" }\n"
""));
        manabar->setValue(70);
        manabar->setTextVisible(true);

        gridLayout->addWidget(manabar, 13, 1, 1, 3);

        hpbar = new QProgressBar(groupBox);
        hpbar->setObjectName(QStringLiteral("hpbar"));
        hpbar->setAutoFillBackground(false);
        hpbar->setStyleSheet(QLatin1String("QProgressBar::chunk {\n"
"     background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(194, 27, 27, 236), stop:0.318182 rgba(241, 227, 227, 241), stop:0.505682 rgba(255, 164, 164, 255), stop:0.977273 rgba(189, 8, 8, 230));\n"
"     width: 1px;\n"
" }\n"
"\n"
" QProgressBar {\n"
"     border: 2px solid grey;\n"
"     border-radius: 5px;\n"
"     text-align: center;\n"
"	background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(165, 162, 114, 255), stop:0.318409 rgba(255, 230, 230, 221), stop:1 rgba(156, 123, 123, 255));\n"
"	color: #000;\n"
"	font-weight: bold;\n"
"     text-align: center;\n"
"	text-shadow: 2px 2px #fff;\n"
" }\n"
""));
        hpbar->setValue(70);
        hpbar->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        hpbar->setTextVisible(true);
        hpbar->setOrientation(Qt::Horizontal);
        hpbar->setInvertedAppearance(false);
        hpbar->setTextDirection(QProgressBar::TopToBottom);

        gridLayout->addWidget(hpbar, 12, 1, 1, 3);

        label_str = new QLabel(groupBox);
        label_str->setObjectName(QStringLiteral("label_str"));
        label_str->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_str, 1, 0, 1, 4);

        label_int = new QLabel(groupBox);
        label_int->setObjectName(QStringLiteral("label_int"));
        label_int->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_int, 4, 0, 1, 4);

        moodbar = new QProgressBar(groupBox);
        moodbar->setObjectName(QStringLiteral("moodbar"));
        moodbar->setAutoFillBackground(false);
        moodbar->setStyleSheet(QLatin1String("QProgressBar::chunk {\n"
"     background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(2, 140, 198, 236), stop:0.318182 rgba(255, 255, 255, 248), stop:0.505682 rgba(158, 223, 255, 255), stop:0.977273 rgba(0, 81, 151, 221));\n"
"     width: 1px;\n"
" }\n"
"\n"
" QProgressBar {\n"
"     border: 2px solid grey;\n"
"     border-radius: 5px;\n"
"     text-align: center;\n"
"	background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(165, 162, 114, 255), stop:0.318409 rgba(255, 230, 230, 221), stop:1 rgba(156, 123, 123, 255));\n"
"	color: #FF3;\n"
"	font-weight: bold;\n"
"     text-align: center;\n"
" }\n"
"/*\n"
"qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(2, 140, 198, 236), stop:0.318182 rgba(255, 255, 255, 248), stop:0.505682 rgba(158, 223, 255, 255), stop:0.977273 rgba(0, 81, 151, 221))\n"
"*//*qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(198, 60, 2, 236), stop:0.318182 rgba(255, 255, 255, 248), stop:0.505682 rgba(255, 175, 158, 255), st"
                        "op:0.977273 rgba(151, 12, 0, 221))*/"));
        moodbar->setMinimum(0);
        moodbar->setMaximum(1000);
        moodbar->setValue(500);
        moodbar->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        moodbar->setTextVisible(false);
        moodbar->setOrientation(Qt::Horizontal);
        moodbar->setInvertedAppearance(false);
        moodbar->setTextDirection(QProgressBar::TopToBottom);

        gridLayout->addWidget(moodbar, 16, 3, 1, 1);

        label_dex = new QLabel(groupBox);
        label_dex->setObjectName(QStringLiteral("label_dex"));
        label_dex->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_dex, 2, 0, 1, 4);

        label_tra = new QLabel(groupBox);
        label_tra->setObjectName(QStringLiteral("label_tra"));
        label_tra->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_tra, 8, 0, 1, 4);

        label_mana = new QLabel(groupBox);
        label_mana->setObjectName(QStringLiteral("label_mana"));
        label_mana->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_mana, 10, 0, 1, 4);


        gridLayout_3->addWidget(groupBox, 1, 0, 2, 1);

        groupBox_3 = new QGroupBox(heroPreviewWindow);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        gridLayout_4 = new QGridLayout(groupBox_3);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        listView = new QListView(groupBox_3);
        listView->setObjectName(QStringLiteral("listView"));

        gridLayout_4->addWidget(listView, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBox_3, 0, 1, 2, 1);

        groupBox_6 = new QGroupBox(heroPreviewWindow);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_6->sizePolicy().hasHeightForWidth());
        groupBox_6->setSizePolicy(sizePolicy);
        groupBox_6->setMinimumSize(QSize(256, 256));
        gridLayout_5 = new QGridLayout(groupBox_6);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        map_pixels = new QLabel(groupBox_6);
        map_pixels->setObjectName(QStringLiteral("map_pixels"));

        gridLayout_5->addWidget(map_pixels, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBox_6, 2, 2, 1, 1);

        groupBox_5 = new QGroupBox(heroPreviewWindow);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        sizePolicy.setHeightForWidth(groupBox_5->sizePolicy().hasHeightForWidth());
        groupBox_5->setSizePolicy(sizePolicy);
        groupBox_5->setMinimumSize(QSize(256, 0));
        verticalLayout_2 = new QVBoxLayout(groupBox_5);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        listWidget = new QListWidget(groupBox_5);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout_2->addWidget(listWidget);

        progressBar_6 = new QProgressBar(groupBox_5);
        progressBar_6->setObjectName(QStringLiteral("progressBar_6"));
        progressBar_6->setAutoFillBackground(false);
        progressBar_6->setStyleSheet(QLatin1String("QProgressBar::chunk {\n"
"     background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(83, 111, 135, 236), stop:0.318182 rgba(173, 205, 196, 223), stop:0.505682 rgba(173, 148, 180, 255), stop:0.977273 rgba(63, 32, 102, 230));\n"
"     width: 1px;\n"
" }\n"
"\n"
" QProgressBar {\n"
"     border: 2px solid grey;\n"
"     border-radius: 5px;\n"
"     text-align: right;\n"
"	background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(165, 162, 114, 255), stop:0.318409 rgba(255, 255, 252, 221), stop:1 rgba(156, 123, 123, 255));\n"
" }\n"
"qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(165, 162, 114, 255), stop:0.318182 rgba(255, 255, 252, 221), stop:1 rgba(156, 123, 123, 255))"));
        progressBar_6->setValue(70);
        progressBar_6->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        progressBar_6->setTextVisible(false);
        progressBar_6->setOrientation(Qt::Horizontal);
        progressBar_6->setInvertedAppearance(false);
        progressBar_6->setTextDirection(QProgressBar::TopToBottom);

        verticalLayout_2->addWidget(progressBar_6);


        gridLayout_3->addWidget(groupBox_5, 0, 2, 2, 1);

        status_line = new QLabel(heroPreviewWindow);
        status_line->setObjectName(QStringLiteral("status_line"));
        status_line->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(status_line, 3, 0, 1, 3);


        retranslateUi(heroPreviewWindow);

        QMetaObject::connectSlotsByName(heroPreviewWindow);
    } // setupUi

    void retranslateUi(QDialog *heroPreviewWindow)
    {
        heroPreviewWindow->setWindowTitle(QApplication::translate("heroPreviewWindow", "Hero Preview", 0));
        groupBox_2->setTitle(QApplication::translate("heroPreviewWindow", "Info", 0));
        label_faction->setText(QApplication::translate("heroPreviewWindow", "Faction: GOING IKEA", 0));
        label_name->setText(QApplication::translate("heroPreviewWindow", "Name: Welzebubel", 0));
        label_level->setText(QApplication::translate("heroPreviewWindow", "Level: 0", 0));
        label_class->setText(QApplication::translate("heroPreviewWindow", "Class: Aswerok", 0));
        label_owner->setText(QApplication::translate("heroPreviewWindow", "Owner: BIBA", 0));
        inventar_box->setTitle(QApplication::translate("heroPreviewWindow", "Items [0 / 35]", 0));
        groupBox->setTitle(QApplication::translate("heroPreviewWindow", "Stats", 0));
        label_hp->setText(QApplication::translate("heroPreviewWindow", "HP: 100 (85 + 15) [+4]", 0));
        label_mag->setText(QApplication::translate("heroPreviewWindow", "MAG: 14 (14 + 1) [+0.8]", 0));
        label_vel->setText(QApplication::translate("heroPreviewWindow", "VEL: 20 (19 + 1) [+2.5]", 0));
        label_15->setText(QApplication::translate("heroPreviewWindow", "Mood:", 0));
        label_13->setText(QApplication::translate("heroPreviewWindow", "EXP:", 0));
        label_8->setText(QApplication::translate("heroPreviewWindow", "MANA:", 0));
        label_7->setText(QApplication::translate("heroPreviewWindow", "HP:", 0));
        expbar->setFormat(QApplication::translate("heroPreviewWindow", "%v / %m", 0));
        manabar->setFormat(QApplication::translate("heroPreviewWindow", "%v / %m", 0));
        hpbar->setFormat(QApplication::translate("heroPreviewWindow", "%v / %m", 0));
        label_str->setText(QApplication::translate("heroPreviewWindow", "STR: %TOTAL% (%BASIC + %ITEMS) [+%PERLVL]", 0));
        label_int->setText(QApplication::translate("heroPreviewWindow", "INT: 17 (14 + 3) [+0.7]", 0));
        moodbar->setFormat(QApplication::translate("heroPreviewWindow", "%v / %m", 0));
        label_dex->setText(QApplication::translate("heroPreviewWindow", "DEX: 34 (26 + 8) [+3]", 0));
        label_tra->setText(QApplication::translate("heroPreviewWindow", "TRA: 13 (18 - 5)  [+1.75]", 0));
        label_mana->setText(QApplication::translate("heroPreviewWindow", "MANA: 75 [+3]", 0));
        groupBox_3->setTitle(QApplication::translate("heroPreviewWindow", "Equipment", 0));
        groupBox_6->setTitle(QApplication::translate("heroPreviewWindow", "Map", 0));
        map_pixels->setText(QString());
        groupBox_5->setTitle(QApplication::translate("heroPreviewWindow", "Quests", 0));
        progressBar_6->setFormat(QApplication::translate("heroPreviewWindow", "%v / %m", 0));
        status_line->setText(QApplication::translate("heroPreviewWindow", "OK", 0));
    } // retranslateUi

};

namespace Ui {
    class heroPreviewWindow: public Ui_heroPreviewWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HEROPREVIEWWINDOW_H
