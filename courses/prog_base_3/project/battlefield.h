#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H

#include <QMainWindow>
#include "currentstate.h"
#include "generalstate.h"
#include "dragonenemy.h"

namespace Ui {
class BattleField;
}

class BattleField : public QMainWindow
{
    Q_OBJECT

public:
    explicit BattleField(QWidget *parent = 0);
    void initUiLabels();

    CurrentState *currentState;
    GeneralState *generalState;
    DragonEnemy *currentDragonEnemy;

private slots:
    void on_monsterButton_clicked();

private:
    Ui::BattleField *ui;
};

#endif // BATTLEFIELD_H
