#include "heropreviewwindow.h"
#include "ui_heropreviewwindow.h"

heroPreviewWindow::heroPreviewWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::heroPreviewWindow)
{
    ui->setupUi(this);
}

heroPreviewWindow::~heroPreviewWindow()
{
    delete ui;
}
