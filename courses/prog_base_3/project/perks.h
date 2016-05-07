#pragma once

#include <QDialog>
#include <QTimer>

#include "generalstate.h"
#include "dragonenemy.h"
#include "heropowersmenu.h"

namespace Ui {
class Perks;
}

class Perks : public QDialog
{
    Q_OBJECT

public:
    explicit Perks(GeneralState *in_generalState, DragonEnemy *in_dragonEnemy, HeroPowersMenu *in_heropowers, QWidget *parent = 0);
    ~Perks();

private slots:
    void on_perksBtn_DiamondsRush_clicked();
    void on_perksBtn_Eldorado_clicked();
    void on_perksBtn_EnchSword_clicked();
    void on_perksBtn_WindfArmory_clicked();
    void on_perksBtn_PassLevel_clicked();

private:
    Ui::Perks *ui;

    //
    GeneralState *perks_generalState;

    //
    DragonEnemy *perks_dragonEnemy;

    //
    HeroPowersMenu *perks_heroPowers;
};
