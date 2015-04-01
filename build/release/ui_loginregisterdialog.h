/********************************************************************************
** Form generated from reading UI file 'loginregisterdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINREGISTERDIALOG_H
#define UI_LOGINREGISTERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginRegisterDialog
{
public:
    QVBoxLayout *verticalLayout_3;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *login_nickname;
    QLabel *label_2;
    QLineEdit *login_password;
    QLabel *label_7;
    QLineEdit *login_server;
    QPushButton *pushButton_2;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_5;
    QGridLayout *gridLayout_2;
    QLineEdit *register_server;
    QLabel *label_4;
    QLineEdit *register_nickname;
    QLabel *label_5;
    QLineEdit *register_password;
    QLabel *label_8;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QGridLayout *gridLayout_3;
    QPushButton *new_hero;
    QPushButton *connect_button;
    QComboBox *heroes;
    QPushButton *view_button;
    QLabel *status_line;

    void setupUi(QDialog *LoginRegisterDialog)
    {
        if (LoginRegisterDialog->objectName().isEmpty())
            LoginRegisterDialog->setObjectName(QStringLiteral("LoginRegisterDialog"));
        LoginRegisterDialog->resize(374, 241);
        LoginRegisterDialog->setStyleSheet(QLatin1String(" QTabWidget::pane { /* The tab widget frame */\n"
"     border-top: 2px solid #C2C7CB;\n"
" }\n"
"\n"
" QTabWidget::tab-bar {\n"
"     left: 5px; /* move to the right by 5px */\n"
" }\n"
"\n"
" /* Style the tab using the tab sub-control. Note that\n"
"     it reads QTabBar _not_ QTabWidget */\n"
" QTabBar::tab {\n"
"     background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                 stop: 0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"                                 stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
"     border: 2px solid #C4C4C3;\n"
"     border-bottom-color: #C2C7CB; /* same as the pane color */\n"
"     border-top-left-radius: 4px;\n"
"     border-top-right-radius: 4px;\n"
"     min-width: 28ex;\n"
"     padding-left: 6px;\n"
"     padding-right: 6px;\n"
"     padding-top: 3px;\n"
"     padding-bottom: 3px;\n"
" }\n"
"\n"
" QTabBar::tab:selected {\n"
"     background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                 stop: 0 #faffca, stop: 0.4 #ffffd"
                        "4,\n"
"                                 stop: 0.6 #e7f7e7, stop: 1.0 #fafffa);\n"
" }\n"
"\n"
"QTabBar::tab:hover {\n"
"     background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                 stop: 0 #aaffaa, stop: 0.4 #ffffa4,\n"
"                                 stop: 0.6 #ccffcc, stop: 1.0 #ddffdd);\n"
" }\n"
"\n"
" QTabBar::tab:selected {\n"
"     border-color: #9B9B9B;\n"
"     border-bottom-color: #C2C7CB; /* same as pane color */\n"
" }\n"
"\n"
" QTabBar::tab:!selected {\n"
"     margin-top: 3px; /* make non-selected tabs look smaller */\n"
" }\n"
"\n"
" /* make use of negative margins for overlapping tabs */\n"
" QTabBar::tab:selected {\n"
"     /* expand/overlap to the left and right by 4px */\n"
"     margin-left: -4px;\n"
"     margin-right: -4px;\n"
" }\n"
"\n"
" QTabBar::tab:first:selected {\n"
"     margin-left: 0; /* the first selected tab has nothing to overlap with on the left */\n"
" }\n"
"\n"
" QTabBar::tab:last:selected {\n"
"     margin-right: 0; /* the last selec"
                        "ted tab has nothing to overlap with on the right */\n"
" }\n"
"\n"
" QTabBar::tab:only-one {\n"
"     margin: 0; /* if there is only one tab, we don't want overlapping margins */\n"
" }"));
        verticalLayout_3 = new QVBoxLayout(LoginRegisterDialog);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        tabWidget = new QTabWidget(LoginRegisterDialog);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setContextMenuPolicy(Qt::DefaultContextMenu);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        login_nickname = new QLineEdit(tab);
        login_nickname->setObjectName(QStringLiteral("login_nickname"));

        gridLayout->addWidget(login_nickname, 0, 1, 1, 1);

        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        login_password = new QLineEdit(tab);
        login_password->setObjectName(QStringLiteral("login_password"));

        gridLayout->addWidget(login_password, 1, 1, 1, 1);

        label_7 = new QLabel(tab);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_7, 2, 0, 1, 1);

        login_server = new QLineEdit(tab);
        login_server->setObjectName(QStringLiteral("login_server"));

        gridLayout->addWidget(login_server, 2, 1, 1, 1);

        pushButton_2 = new QPushButton(tab);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(0, 30));
        QFont font;
        font.setPointSize(10);
        pushButton_2->setFont(font);

        gridLayout->addWidget(pushButton_2, 3, 0, 1, 2);


        verticalLayout_2->addLayout(gridLayout);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout_5 = new QVBoxLayout(tab_2);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        register_server = new QLineEdit(tab_2);
        register_server->setObjectName(QStringLiteral("register_server"));

        gridLayout_2->addWidget(register_server, 2, 1, 1, 1);

        label_4 = new QLabel(tab_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_4, 0, 0, 1, 1);

        register_nickname = new QLineEdit(tab_2);
        register_nickname->setObjectName(QStringLiteral("register_nickname"));
        register_nickname->setStyleSheet(QStringLiteral(""));

        gridLayout_2->addWidget(register_nickname, 0, 1, 1, 1);

        label_5 = new QLabel(tab_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_5, 1, 0, 1, 1);

        register_password = new QLineEdit(tab_2);
        register_password->setObjectName(QStringLiteral("register_password"));

        gridLayout_2->addWidget(register_password, 1, 1, 1, 1);

        label_8 = new QLabel(tab_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_8, 2, 0, 1, 1);

        pushButton_3 = new QPushButton(tab_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);
        pushButton_3->setMaximumSize(QSize(50, 16777215));

        gridLayout_2->addWidget(pushButton_3, 0, 2, 3, 1);

        pushButton = new QPushButton(tab_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(0, 30));
        pushButton->setFont(font);

        gridLayout_2->addWidget(pushButton, 3, 0, 1, 3);


        verticalLayout_5->addLayout(gridLayout_2);

        tabWidget->addTab(tab_2, QString());

        verticalLayout_3->addWidget(tabWidget);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setSizeConstraint(QLayout::SetMinAndMaxSize);
        new_hero = new QPushButton(LoginRegisterDialog);
        new_hero->setObjectName(QStringLiteral("new_hero"));
        new_hero->setEnabled(false);
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(new_hero->sizePolicy().hasHeightForWidth());
        new_hero->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(new_hero, 0, 2, 1, 1);

        connect_button = new QPushButton(LoginRegisterDialog);
        connect_button->setObjectName(QStringLiteral("connect_button"));
        connect_button->setEnabled(false);
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(connect_button->sizePolicy().hasHeightForWidth());
        connect_button->setSizePolicy(sizePolicy2);
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        connect_button->setFont(font1);

        gridLayout_3->addWidget(connect_button, 0, 3, 1, 1);

        heroes = new QComboBox(LoginRegisterDialog);
        heroes->setObjectName(QStringLiteral("heroes"));
        heroes->setEnabled(false);
        sizePolicy2.setHeightForWidth(heroes->sizePolicy().hasHeightForWidth());
        heroes->setSizePolicy(sizePolicy2);
        heroes->setMinimumSize(QSize(0, 30));

        gridLayout_3->addWidget(heroes, 0, 0, 1, 1);

        view_button = new QPushButton(LoginRegisterDialog);
        view_button->setObjectName(QStringLiteral("view_button"));
        view_button->setEnabled(false);
        sizePolicy.setHeightForWidth(view_button->sizePolicy().hasHeightForWidth());
        view_button->setSizePolicy(sizePolicy);
        view_button->setMaximumSize(QSize(40, 16777215));

        gridLayout_3->addWidget(view_button, 0, 1, 1, 1);


        verticalLayout_3->addLayout(gridLayout_3);

        status_line = new QLabel(LoginRegisterDialog);
        status_line->setObjectName(QStringLiteral("status_line"));
        QFont font2;
        font2.setPointSize(12);
        status_line->setFont(font2);
        status_line->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(status_line);


        retranslateUi(LoginRegisterDialog);
        QObject::connect(register_password, SIGNAL(returnPressed()), pushButton, SLOT(click()));
        QObject::connect(register_nickname, SIGNAL(returnPressed()), pushButton, SLOT(click()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(LoginRegisterDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginRegisterDialog)
    {
        LoginRegisterDialog->setWindowTitle(QApplication::translate("LoginRegisterDialog", "Dialog", 0));
        label->setText(QApplication::translate("LoginRegisterDialog", "Nickname:", 0));
        label_2->setText(QApplication::translate("LoginRegisterDialog", "Password:", 0));
        login_password->setInputMask(QString());
        label_7->setText(QApplication::translate("LoginRegisterDialog", "Server:", 0));
        login_server->setText(QApplication::translate("LoginRegisterDialog", "https://battle-progress.herokuapp.com/", 0));
        pushButton_2->setText(QApplication::translate("LoginRegisterDialog", "Login", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("LoginRegisterDialog", "Login", 0));
        register_server->setText(QApplication::translate("LoginRegisterDialog", "https://battle-progress.herokuapp.com/", 0));
        label_4->setText(QApplication::translate("LoginRegisterDialog", "Nickname:", 0));
        label_5->setText(QApplication::translate("LoginRegisterDialog", "Password:", 0));
        label_8->setText(QApplication::translate("LoginRegisterDialog", "Server:", 0));
        pushButton_3->setText(QApplication::translate("LoginRegisterDialog", "Check", 0));
        pushButton->setText(QApplication::translate("LoginRegisterDialog", "Register", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("LoginRegisterDialog", "Register", 0));
        new_hero->setText(QApplication::translate("LoginRegisterDialog", "NEW", 0));
        connect_button->setText(QApplication::translate("LoginRegisterDialog", "Connect", 0));
        view_button->setText(QApplication::translate("LoginRegisterDialog", "?", 0));
        status_line->setText(QApplication::translate("LoginRegisterDialog", "IDLE", 0));
    } // retranslateUi

};

namespace Ui {
    class LoginRegisterDialog: public Ui_LoginRegisterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINREGISTERDIALOG_H
