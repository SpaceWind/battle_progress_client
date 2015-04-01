/********************************************************************************
** Form generated from reading UI file 'spellrequirementsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPELLREQUIREMENTSDIALOG_H
#define UI_SPELLREQUIREMENTSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_SpellRequirementsDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *label_4;
    QSpinBox *spinBox_4;
    QLabel *label_8;
    QSpinBox *spinBox_5;
    QLabel *label_2;
    QSpinBox *spinBox_3;
    QLabel *label_6;
    QSpinBox *spinBox_2;
    QLabel *label_7;
    QLabel *label_5;
    QSpinBox *spinBox;
    QSpinBox *spinBox_7;
    QSpinBox *spinBox_6;
    QSpinBox *spinBox_8;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *SpellRequirementsDialog)
    {
        if (SpellRequirementsDialog->objectName().isEmpty())
            SpellRequirementsDialog->setObjectName(QStringLiteral("SpellRequirementsDialog"));
        SpellRequirementsDialog->resize(321, 271);
        gridLayout = new QGridLayout(SpellRequirementsDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_3 = new QLabel(SpellRequirementsDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMaximumSize(QSize(60, 16777215));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_4 = new QLabel(SpellRequirementsDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMaximumSize(QSize(60, 16777215));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        spinBox_4 = new QSpinBox(SpellRequirementsDialog);
        spinBox_4->setObjectName(QStringLiteral("spinBox_4"));

        gridLayout->addWidget(spinBox_4, 3, 1, 1, 1);

        label_8 = new QLabel(SpellRequirementsDialog);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setMaximumSize(QSize(60, 16777215));
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_8, 7, 0, 1, 1);

        spinBox_5 = new QSpinBox(SpellRequirementsDialog);
        spinBox_5->setObjectName(QStringLiteral("spinBox_5"));

        gridLayout->addWidget(spinBox_5, 4, 1, 1, 1);

        label_2 = new QLabel(SpellRequirementsDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(60, 16777215));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        spinBox_3 = new QSpinBox(SpellRequirementsDialog);
        spinBox_3->setObjectName(QStringLiteral("spinBox_3"));

        gridLayout->addWidget(spinBox_3, 2, 1, 1, 1);

        label_6 = new QLabel(SpellRequirementsDialog);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMaximumSize(QSize(60, 16777215));
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        spinBox_2 = new QSpinBox(SpellRequirementsDialog);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));

        gridLayout->addWidget(spinBox_2, 1, 1, 1, 1);

        label_7 = new QLabel(SpellRequirementsDialog);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMaximumSize(QSize(60, 16777215));
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_7, 6, 0, 1, 1);

        label_5 = new QLabel(SpellRequirementsDialog);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMaximumSize(QSize(60, 16777215));
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        spinBox = new QSpinBox(SpellRequirementsDialog);
        spinBox->setObjectName(QStringLiteral("spinBox"));

        gridLayout->addWidget(spinBox, 0, 1, 1, 1);

        spinBox_7 = new QSpinBox(SpellRequirementsDialog);
        spinBox_7->setObjectName(QStringLiteral("spinBox_7"));

        gridLayout->addWidget(spinBox_7, 6, 1, 1, 1);

        spinBox_6 = new QSpinBox(SpellRequirementsDialog);
        spinBox_6->setObjectName(QStringLiteral("spinBox_6"));

        gridLayout->addWidget(spinBox_6, 5, 1, 1, 1);

        spinBox_8 = new QSpinBox(SpellRequirementsDialog);
        spinBox_8->setObjectName(QStringLiteral("spinBox_8"));

        gridLayout->addWidget(spinBox_8, 7, 1, 1, 1);

        label = new QLabel(SpellRequirementsDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(60, 16777215));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        pushButton = new QPushButton(SpellRequirementsDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setAutoDefault(true);
        pushButton->setDefault(true);

        gridLayout->addWidget(pushButton, 8, 0, 1, 1);

        pushButton_2 = new QPushButton(SpellRequirementsDialog);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_2, 8, 1, 1, 1);


        retranslateUi(SpellRequirementsDialog);

        QMetaObject::connectSlotsByName(SpellRequirementsDialog);
    } // setupUi

    void retranslateUi(QDialog *SpellRequirementsDialog)
    {
        SpellRequirementsDialog->setWindowTitle(QApplication::translate("SpellRequirementsDialog", "Dialog", 0));
        label_3->setText(QApplication::translate("SpellRequirementsDialog", "MAG:", 0));
        label_4->setText(QApplication::translate("SpellRequirementsDialog", "INT:", 0));
        label_8->setText(QApplication::translate("SpellRequirementsDialog", "MANA:", 0));
        label_2->setText(QApplication::translate("SpellRequirementsDialog", "DEX:", 0));
        label_6->setText(QApplication::translate("SpellRequirementsDialog", "VEL:", 0));
        label_7->setText(QApplication::translate("SpellRequirementsDialog", "HP:", 0));
        label_5->setText(QApplication::translate("SpellRequirementsDialog", "TRA:", 0));
        label->setText(QApplication::translate("SpellRequirementsDialog", "STR:", 0));
        pushButton->setText(QApplication::translate("SpellRequirementsDialog", "OK", 0));
        pushButton_2->setText(QApplication::translate("SpellRequirementsDialog", "CANCEL", 0));
    } // retranslateUi

};

namespace Ui {
    class SpellRequirementsDialog: public Ui_SpellRequirementsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPELLREQUIREMENTSDIALOG_H
