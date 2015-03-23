#include <QStyledItemDelegate>
#include <QAbstractItemView>
#include <QFontMetrics>
#include "customdroplistcombobox.h"






CustomDropListComboBox::CustomDropListComboBox(QWidget *parent) : QComboBox(parent)
{
    QStyledItemDelegate* itemDelegate = new QStyledItemDelegate();
    setItemDelegate(itemDelegate);
    QFont font = view()->font();
    font.setPointSize(14);
    view()->setFont(font);
}

void CustomDropListComboBox::showPopup()
{

    QFontMetrics fontParams(view()->font());

    int maxWidth = 0;
    for(int i=0; i<count(); i++)
        if (fontParams.width(itemText(i)) > maxWidth)
            maxWidth = fontParams.width(this->itemText(i));



    view()->setFixedWidth(maxWidth-28);
    QComboBox::showPopup();
}
