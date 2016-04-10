#include <QDesktopWidget>

#include "battlefield.h"
#include "ui_battlefield.h"

BattleField::BattleField(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BattleField)
{
    ui->setupUi(this);

    // Disable resizing a BattleField window.
    setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);
    // Move BattleField window to the center of screen.
    QDesktopWidget *desktop = QApplication::desktop();
    int x, y;
    x = (desktop->width() - this->size().width()) / 2;
    y = (desktop->height() - this->size().height()) / 2;
    y -= 50;
    this->move(x,y);
}
