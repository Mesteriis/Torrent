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

private:
    Ui::MWindow *ui;
    SCore *SC = new SCore;

};

#endif // MWINDOW_H
