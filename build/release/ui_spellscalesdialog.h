/********************************************************************************
** Form generated from reading UI file 'spellscalesdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPELLSCALESDIALOG_H
#define UI_SPELLSCALESDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SpellScalesDialog
{
public:
    QGridLayout *gridLayout;
    QComboBox *effect_combobox;
    QPushButton *pushButton_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QComboBox *dependance_combobox;
    QLabel *label;
    QDoubleSpinBox *scale_value;
    QListWidget *scale_list;
    QPushButton *pushButton_3;

    void setupUi(QDialog *SpellScalesDialog)
    {
        if (SpellScalesDialog->objectName().isEmpty())
            SpellScalesDialog->setObjectName(QStringLiteral("SpellScalesDialog"));
        SpellScalesDialog->resize(444, 443);
        SpellScalesDialog->setModal(true);
        gridLayout = new QGridLayout(SpellScalesDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        effect_combobox = new QComboBox(SpellScalesDialog);
        effect_combobox->setObjectName(QStringLiteral("effect_combobox"));

        gridLayout->addWidget(effect_combobox, 0, 0, 1, 5);

        pushButton_4 = new QPushButton(SpellScalesDialog);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(0, 35));

        gridLayout->addWidget(pushButton_4, 3, 4, 1, 1);

        groupBox = new QGroupBox(SpellScalesDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout_2->addWidget(pushButton, 3, 3, 1, 1);

        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout_2->addWidget(pushButton_2, 3, 4, 1, 1);

        dependance_combobox = new QComboBox(groupBox);
        dependance_combobox->setObjectName(QStringLiteral("dependance_combobox"));

        gridLayout_2->addWidget(dependance_combobox, 3, 2, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 3, 0, 1, 1);

        scale_value = new QDoubleSpinBox(groupBox);
        scale_value->setObjectName(QStringLiteral("scale_value"));
        scale_value->setMaximum(2);
        scale_value->setSingleStep(0.05);

        gridLayout_2->addWidget(scale_value, 3, 1, 1, 1);

        scale_list = new QListWidget(groupBox);
        scale_list->setObjectName(QStringLiteral("scale_list"));

        gridLayout_2->addWidget(scale_list, 0, 0, 1, 5);


        gridLayout->addWidget(groupBox, 1, 0, 1, 5);

        pushButton_3 = new QPushButton(SpellScalesDialog);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(0, 35));
        pushButton_3->setDefault(true);

        gridLayout->addWidget(pushButton_3, 3, 2, 1, 2);


        retranslateUi(SpellScalesDialog);

        QMetaObject::connectSlotsByName(SpellScalesDialog);
    } // setupUi

    void retranslateUi(QDialog *SpellScalesDialog)
    {
        SpellScalesDialog->setWindowTitle(QApplication::translate("SpellScalesDialog", "Dialog", 0));
        pushButton_4->setText(QApplication::translate("SpellScalesDialog", "CANCEL", 0));
        groupBox->setTitle(QApplication::translate("SpellScalesDialog", "Scales", 0));
        pushButton->setText(QApplication::translate("SpellScalesDialog", "ADD", 0));
        pushButton_2->setText(QApplication::translate("SpellScalesDialog", "Remove", 0));
        label->setText(QApplication::translate("SpellScalesDialog", "Scale Coef:", 0));
        pushButton_3->setText(QApplication::translate("SpellScalesDialog", "OK", 0));
    } // retranslateUi

};

namespace Ui {
    class SpellScalesDialog: public Ui_SpellScalesDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPELLSCALESDIALOG_H
