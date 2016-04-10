#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H

#include <QMainWindow>

namespace Ui {
class BattleField;
}

class BattleField : public QMainWindow
{
    Q_OBJECT

public:
    explicit BattleField(QWidget *parent = 0);

private:
    Ui::BattleField *ui;
};

#endif // BATTLEFIELD_H
