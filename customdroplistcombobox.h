#ifndef CUSTOMDROPLISTCOMBOBOX_H
#define CUSTOMDROPLISTCOMBOBOX_H

#include <QObject>
#include <QWidget>
#include <QComboBox>

class CustomDropListComboBox : public QComboBox
{
public:
    CustomDropListComboBox(QWidget *parent = 0);

    ~CustomDropListComboBox(){;}
    virtual void showPopup();

};

#endif // CUSTOMDROPLISTCOMBOBOX_H
