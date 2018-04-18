#include "mwindow.h"
#include "ui_mwindow.h"

MWindow::MWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MWindow)
{
    ui->setupUi(this);
    ui->listWidget->setSelectionRectVisible(true);
    ui->listWidget->setDisabled(true);
    SC->setVar();
    SC->writeVectorDir(SC->getVar());

    for (int i = 0; i < SC->ArrFI.size();  ++i)
    {
        ui->listWidget->addItem(SC->ArrFI[i].Name);
    }
}

MWindow::~MWindow()
{
    delete ui;
}

void MWindow::on_commandLinkButton_3_clicked()
{
    QApplication::quit();
}

void MWindow::on_commandLinkButton_2_clicked()
{
    // локально
    int counter = 0;
    for (int i = 0; SC->ArrFI.size()>i; ++i)
    {
        if (SC->moveTorFile(SC->ArrFI[i].Name,'l'))
        {
            ui->listWidget->removeItemWidget(ui->listWidget->takeItem(i));
            counter++;
        }
    }
    if (counter==SC->ArrFI.size()) QApplication::quit();
}

void MWindow::on_commandLinkButton_clicked()
{
    // удаленно
    int counter = 0;
    for (int i = 0; SC->ArrFI.size()>i; ++i)
    {
        if(SC->moveTorFile(SC->ArrFI[i].Name,'e'))
        {
            ui->listWidget->removeItemWidget(ui->listWidget->takeItem(i));
            counter++;
        }
    }
    if (counter==SC->ArrFI.size()) QApplication::quit();
}
