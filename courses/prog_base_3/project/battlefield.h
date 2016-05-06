#pragma once

#include <QMainWindow>
#include <QDebug>

// Logic classes.
#include "achievements.h"
#include "army.h"
#include "dragonenemy.h"
#include "generalstate.h"

// Other windows form classes.
#include "hirearmy.h"
#include "perks.h"
#include "achievementsmenu.h"
#include "heropowersmenu.h"

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

    // Other windows.
    HireArmy *hireArmy;
    Perks *perksWindow;
    AchievementsMenu *achivmntsWindow;
    HeroPowersMenu *heropwrsWindow;

private slots:
    void on_monsterButton_clicked();
    void on_armyhireButton_clicked();
    void on_heropowersButton_clicked();
    void on_perksButton_clicked();
    void on_achvmntsButton_clicked();
    void army_attack();
    void update();

private:
    QTimer *timerArmyAttack;
    QTimer *timerUpdate;
    Ui::BattleField *ui;
};
