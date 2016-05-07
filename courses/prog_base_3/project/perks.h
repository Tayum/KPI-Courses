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
    // Buttons behavior handlers.
    void on_perksBtn_DiamondsRush_clicked();
    void on_perksBtn_Eldorado_clicked();
    void on_perksBtn_EnchSword_clicked();
    void on_perksBtn_PassLevel_clicked();
    void on_perksBtn_WindfArmory_clicked();

private:
    // UI object.
    Ui::Perks *ui;

    // General status object.
    // Also object for perks, that change general status object.
    GeneralState *gnrlState;

    // Object for perks, that change dragon HP: .
    DragonEnemy *drgnEnemy;

    // Object for perk, that changes heroPowers fields: WindFuryArmory
    HeroPowersMenu *heroPwrs;
};
