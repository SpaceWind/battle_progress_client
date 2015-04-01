/********************************************************************************
** Form generated from reading UI file 'newherodialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWHERODIALOG_H
#define UI_NEWHERODIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_newHeroDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *gender_combobox;
    QComboBox *class_combobox;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *hero_desc;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *saveButton;
    QComboBox *faction_combobox;
    QLabel *label_3;
    QLabel *label_2;
    QPushButton *pushButton_2;
    QLineEdit *hero_name;
    QLabel *status_label;

    void setupUi(QDialog *newHeroDialog)
    {
        if (newHeroDialog->objectName().isEmpty())
            newHeroDialog->setObjectName(QStringLiteral("newHeroDialog"));
        newHeroDialog->resize(827, 527);
        newHeroDialog->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(newHeroDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(newHeroDialog);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 2, 0, 1, 1);

        gender_combobox = new QComboBox(newHeroDialog);
        gender_combobox->setObjectName(QStringLiteral("gender_combobox"));

        gridLayout->addWidget(gender_combobox, 2, 1, 1, 1);

        class_combobox = new QComboBox(newHeroDialog);
        class_combobox->setObjectName(QStringLiteral("class_combobox"));

        gridLayout->addWidget(class_combobox, 1, 1, 1, 1);

        groupBox = new QGroupBox(newHeroDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        hero_desc = new QTextEdit(groupBox);
        hero_desc->setObjectName(QStringLiteral("hero_desc"));
        QFont font;
        font.setPointSize(12);
        font.setStyleStrategy(QFont::PreferAntialias);
        hero_desc->setFont(font);
        hero_desc->setStyleSheet(QLatin1String("background-color: #EEEEEE;\n"
"background: qlineargradient(spread:reflect, x1:0.43, y1:0.67, x2:0.204, y2:0.841, stop:0 rgba(101, 122, 224, 50), stop:1 rgba(255, 255, 255, 255));\n"
"\n"
""));
        hero_desc->setFrameShadow(QFrame::Sunken);
        hero_desc->setReadOnly(true);

        verticalLayout_2->addWidget(hero_desc);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(0, 64));
        QIcon icon;
        icon.addFile(QStringLiteral(":/assets/roll.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(48, 48));

        horizontalLayout->addWidget(pushButton);

        saveButton = new QPushButton(groupBox);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(saveButton->sizePolicy().hasHeightForWidth());
        saveButton->setSizePolicy(sizePolicy);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/assets/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveButton->setIcon(icon1);
        saveButton->setIconSize(QSize(44, 48));

        horizontalLayout->addWidget(saveButton);


        verticalLayout_2->addLayout(horizontalLayout);


        gridLayout->addWidget(groupBox, 4, 0, 1, 2);

        faction_combobox = new QComboBox(newHeroDialog);
        faction_combobox->setObjectName(QStringLiteral("faction_combobox"));

        gridLayout->addWidget(faction_combobox, 0, 1, 1, 1);

        label_3 = new QLabel(newHeroDialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        label_2 = new QLabel(newHeroDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(150, 16777215));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(newHeroDialog);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(0, 40));

        gridLayout->addWidget(pushButton_2, 3, 0, 1, 1);

        hero_name = new QLineEdit(newHeroDialog);
        hero_name->setObjectName(QStringLiteral("hero_name"));
        hero_name->setMinimumSize(QSize(0, 40));
        QFont font1;
        font1.setPointSize(16);
        hero_name->setFont(font1);
        hero_name->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(hero_name, 3, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        status_label = new QLabel(newHeroDialog);
        status_label->setObjectName(QStringLiteral("status_label"));
        status_label->setMaximumSize(QSize(16777215, 20));
        status_label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(status_label);


        retranslateUi(newHeroDialog);

        QMetaObject::connectSlotsByName(newHeroDialog);
    } // setupUi

    void retranslateUi(QDialog *newHeroDialog)
    {
        newHeroDialog->setWindowTitle(QApplication::translate("newHeroDialog", "Dialog", 0));
        label->setText(QApplication::translate("newHeroDialog", "Gender:", 0));
        gender_combobox->clear();
        gender_combobox->insertItems(0, QStringList()
         << QApplication::translate("newHeroDialog", "Male", 0)
         << QApplication::translate("newHeroDialog", "Female", 0)
        );
        groupBox->setTitle(QApplication::translate("newHeroDialog", "\320\221\320\270\320\276\320\263\321\200\320\260\321\204\320\270\321\217 \320\263\320\265\321\200\320\276\321\217:", 0));
        pushButton->setText(QApplication::translate("newHeroDialog", "ROLL", 0));
        saveButton->setText(QApplication::translate("newHeroDialog", "Im Fine with Him! Lets play!", 0));
        label_3->setText(QApplication::translate("newHeroDialog", "Class:", 0));
        label_2->setText(QApplication::translate("newHeroDialog", "Faction:", 0));
        pushButton_2->setText(QApplication::translate("newHeroDialog", "Hero Name:", 0));
        hero_name->setText(QString());
        status_label->setText(QApplication::translate("newHeroDialog", "OK", 0));
    } // retranslateUi

};

namespace Ui {
    class newHeroDialog: public Ui_newHeroDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWHERODIALOG_H
