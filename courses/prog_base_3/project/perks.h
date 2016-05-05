#pragma once

#include <QDialog>
#include <QTimer>

#include "generalstate.h"
#include "dragonenemy.h"

#define ELDORADO_MONEY 100
#define RUSH_DIAMONDS 10
#define SWORD_DMG 20

namespace Ui {
class Perks;
}

class Perks : public QDialog
{
    Q_OBJECT

public:
    explicit Perks(GeneralState *in_generalState, DragonEnemy *in_dragonEnemy, QWidget *parent = 0);
    ~Perks();

    GeneralState *perks_generalState;
    DragonEnemy *perks_dragonEnemy;

private slots:
    void on_perksBtn_DiamondsRush_clicked();
    void on_perksBtn_Eldorado_clicked();
    void on_perksBtn_EnchSword_clicked();
    void on_perksBtn_WindfArmory_clicked();
    void on_perksBtn_PassLevel_clicked();

private:
    Ui::Perks *ui;
};
