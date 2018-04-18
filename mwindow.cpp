#include "mwindow.h"
#include "ui_mwindow.h"

MWindow::MWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MWindow)
{
    ui->setupUi(this);



}

MWindow::~MWindow()
{
    delete ui;
}
