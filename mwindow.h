#ifndef MWINDOW_H
#define MWINDOW_H

#include <QDialog>
#include "score.h"

namespace Ui {
class MWindow;
}

class MWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MWindow(QWidget *parent = 0);
    ~MWindow();

private slots:


    void on_commandLinkButton_3_clicked();

    void on_commandLinkButton_2_clicked();

    void on_commandLinkButton_clicked();

private:
    Ui::MWindow *ui;
    SCore *SC = new SCore;

};

#endif // MWINDOW_H
