#pragma once

#include <QMainWindow>

#include "achievements.h"
#include "army.h"
#include "dragonenemy.h"
#include "generalstate.h"

#include "hirearmy.h"

namespace Ui {
class BattleField;
}

class BattleField : public QMainWindow
{
    Q_OBJECT

public:
    explicit BattleField(QWidget *parent = 0);

    Achievements *achievements;
    Army *army;
    DragonEnemy *currentDragonEnemy;
    GeneralState *generalState;

    void updateUILabels();

    HireArmy *hireArmy;

private slots:
    void on_monsterButton_clicked();
    void army_attack();    


    void on_armyhireButton_clicked();

private:
    Ui::BattleField *ui;
};
