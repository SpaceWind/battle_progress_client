/********************************************************************************
** Form generated from reading UI file 'classspecsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLASSSPECSDIALOG_H
#define UI_CLASSSPECSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_classSpecsDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label_4;
    QLabel *label_8;
    QLabel *label_3;
    QLabel *label_6;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_7;
    QLabel *label_5;
    QSpinBox *spinBox;
    QSpinBox *spinBox_2;
    QSpinBox *spinBox_3;
    QSpinBox *spinBox_4;
    QSpinBox *spinBox_5;
    QSpinBox *spinBox_6;
    QSpinBox *spinBox_7;
    QSpinBox *spinBox_8;
    QLabel *label_9;
    QLineEdit *lineEdit;
    QLabel *label_10;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *classSpecsDialog)
    {
        if (classSpecsDialog->objectName().isEmpty())
            classSpecsDialog->setObjectName(QStringLiteral("classSpecsDialog"));
        classSpecsDialog->resize(320, 366);
        gridLayout = new QGridLayout(classSpecsDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_4 = new QLabel(classSpecsDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label_8 = new QLabel(classSpecsDialog);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(label_8, 7, 0, 1, 1);

        label_3 = new QLabel(classSpecsDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_6 = new QLabel(classSpecsDialog);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        label = new QLabel(classSpecsDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(classSpecsDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_7 = new QLabel(classSpecsDialog);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(label_7, 6, 0, 1, 1);

        label_5 = new QLabel(classSpecsDialog);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        spinBox = new QSpinBox(classSpecsDialog);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setMinimum(-5);
        spinBox->setMaximum(5);

        gridLayout->addWidget(spinBox, 0, 1, 1, 1);

        spinBox_2 = new QSpinBox(classSpecsDialog);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setMinimum(-5);
        spinBox_2->setMaximum(5);

        gridLayout->addWidget(spinBox_2, 1, 1, 1, 1);

        spinBox_3 = new QSpinBox(classSpecsDialog);
        spinBox_3->setObjectName(QStringLiteral("spinBox_3"));
        spinBox_3->setMinimum(-5);
        spinBox_3->setMaximum(5);

        gridLayout->addWidget(spinBox_3, 2, 1, 1, 1);

        spinBox_4 = new QSpinBox(classSpecsDialog);
        spinBox_4->setObjectName(QStringLiteral("spinBox_4"));
        spinBox_4->setMinimum(-5);
        spinBox_4->setMaximum(5);

        gridLayout->addWidget(spinBox_4, 3, 1, 1, 1);

        spinBox_5 = new QSpinBox(classSpecsDialog);
        spinBox_5->setObjectName(QStringLiteral("spinBox_5"));
        spinBox_5->setMinimum(-5);
        spinBox_5->setMaximum(5);

        gridLayout->addWidget(spinBox_5, 4, 1, 1, 1);

        spinBox_6 = new QSpinBox(classSpecsDialog);
        spinBox_6->setObjectName(QStringLiteral("spinBox_6"));
        spinBox_6->setMinimum(-5);
        spinBox_6->setMaximum(5);

        gridLayout->addWidget(spinBox_6, 5, 1, 1, 1);

        spinBox_7 = new QSpinBox(classSpecsDialog);
        spinBox_7->setObjectName(QStringLiteral("spinBox_7"));
        spinBox_7->setMinimum(-25);
        spinBox_7->setMaximum(25);
        spinBox_7->setSingleStep(5);

        gridLayout->addWidget(spinBox_7, 6, 1, 1, 1);

        spinBox_8 = new QSpinBox(classSpecsDialog);
        spinBox_8->setObjectName(QStringLiteral("spinBox_8"));
        spinBox_8->setMinimum(-25);
        spinBox_8->setMaximum(25);
        spinBox_8->setSingleStep(5);

        gridLayout->addWidget(spinBox_8, 7, 1, 1, 1);

        label_9 = new QLabel(classSpecsDialog);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout->addWidget(label_9, 8, 0, 1, 1);

        lineEdit = new QLineEdit(classSpecsDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setReadOnly(true);

        gridLayout->addWidget(lineEdit, 8, 1, 1, 1);

        label_10 = new QLabel(classSpecsDialog);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout->addWidget(label_10, 9, 0, 1, 1);

        lineEdit_2 = new QLineEdit(classSpecsDialog);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setReadOnly(true);

        gridLayout->addWidget(lineEdit_2, 9, 1, 1, 1);

        pushButton = new QPushButton(classSpecsDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setMaximumSize(QSize(16777215, 75));
        pushButton->setAutoDefault(true);
        pushButton->setDefault(true);
        pushButton->setFlat(false);

        gridLayout->addWidget(pushButton, 10, 0, 1, 1);

        pushButton_2 = new QPushButton(classSpecsDialog);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        pushButton_2->setMaximumSize(QSize(16777215, 75));

        gridLayout->addWidget(pushButton_2, 10, 1, 1, 1);


        retranslateUi(classSpecsDialog);

        QMetaObject::connectSlotsByName(classSpecsDialog);
    } // setupUi

    void retranslateUi(QDialog *classSpecsDialog)
    {
        classSpecsDialog->setWindowTitle(QApplication::translate("classSpecsDialog", "Dialog", 0));
        label_4->setText(QApplication::translate("classSpecsDialog", "\320\230\320\275\321\202\320\265\320\273\320\273\320\265\320\272\321\202 (INT):", 0));
        label_8->setText(QApplication::translate("classSpecsDialog", "\320\234\320\260\320\275\320\260 (MANA): ", 0));
        label_3->setText(QApplication::translate("classSpecsDialog", "\320\241\320\270\320\273\320\260 \320\274\320\260\320\263\320\270\320\270 (MAG):", 0));
        label_6->setText(QApplication::translate("classSpecsDialog", "\320\222\321\213\320\275\320\276\321\201\320\273\320\270\320\262\320\276\321\201\321\202\321\214 (VEL):", 0));
        label->setText(QApplication::translate("classSpecsDialog", "\320\241\320\270\320\273\320\260 (STR): ", 0));
        label_2->setText(QApplication::translate("classSpecsDialog", "\320\233\320\276\320\262\320\272\320\276\321\201\321\202\321\214 (DEX):", 0));
        label_7->setText(QApplication::translate("classSpecsDialog", "\320\227\320\264\320\276\321\200\320\276\320\262\321\214\320\265 (HP):", 0));
        label_5->setText(QApplication::translate("classSpecsDialog", "\320\242\320\276\321\200\320\263\320\276\320\262\320\273\321\217 (TRA): ", 0));
        label_9->setText(QApplication::translate("classSpecsDialog", "\320\224\320\270\320\267\320\261\320\260\320\273\320\260\320\275\321\201\320\275\320\276\321\201\321\202\321\214:", 0));
        label_10->setText(QApplication::translate("classSpecsDialog", "\320\222\320\265\321\200\320\264\320\270\320\272\321\202:", 0));
        pushButton->setText(QApplication::translate("classSpecsDialog", "Save", 0));
        pushButton_2->setText(QApplication::translate("classSpecsDialog", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class classSpecsDialog: public Ui_classSpecsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLASSSPECSDIALOG_H
