#ifndef HEROPREVIEWWINDOW_H
#define HEROPREVIEWWINDOW_H

#include <QDialog>

namespace Ui {
class heroPreviewWindow;
}

class heroPreviewWindow : public QDialog
{
    Q_OBJECT

public:
    explicit heroPreviewWindow(QWidget *parent = 0);
    ~heroPreviewWindow();

private:
    Ui::heroPreviewWindow *ui;
};

#endif // HEROPREVIEWWINDOW_H
