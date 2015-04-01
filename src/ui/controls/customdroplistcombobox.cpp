#include <QStyledItemDelegate>
#include <QAbstractItemView>
#include <QFontMetrics>
#include <QLineEdit>
#include "customdroplistcombobox.h"






CustomDropListComboBox::CustomDropListComboBox(QWidget *parent) : QComboBox(parent)
{
    QStyledItemDelegate* itemDelegate = new QStyledItemDelegate();
    setItemDelegate(itemDelegate);
    QFont font = view()->font();
    font.setPointSize(14);
    view()->setFont(font);
    this->setStyleSheet(QString("QComboBox QAbstractItemView {\n	border-radius: 6px;\n    border: 2px solid darkgray;\n") +
                        QString("selection-background-color: orange; background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #FFDDDD, stop: 1 #FFFFFF);\n}\n\n") +
                        QString("QComboBox QAbstractItemView::item {\nmin-height: 28px;\nmargin-top: 3px;\n}\n"));
}

void CustomDropListComboBox::showPopup()
{

    QFontMetrics fontParams(view()->font());

    int maxWidth = 0;
    for(int i=0; i<count(); i++)
        if (fontParams.width(itemText(i)) > maxWidth)
            maxWidth = fontParams.width(this->itemText(i));



    view()->setFixedWidth(std::max(maxWidth-28, width()));
    QComboBox::showPopup();
}
