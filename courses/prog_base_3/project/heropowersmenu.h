#pragma once

#include <QDialog>
#include <QTimer>

#include "generalstate.h"

namespace Ui {
class heroPowersMenu;
}

class HeroPowersMenu : public QDialog
{
    Q_OBJECT

public:
    explicit HeroPowersMenu(GeneralState *in_generalState, QWidget *parent = 0);
    ~HeroPowersMenu();

    // Function to refresh all cooldowns.
    // Used in Perks class.
    void refreshCD();

private slots:
    // Buttons behavior handlers.
    void on_anduinMagic_btn_clicked();
    void on_sylvanasCritical_btn_clicked();
    void on_guldanRampage_btn_clicked();
    void on_artasUnity_btn_clicked();
    void on_tapDmg_btn_clicked();

    // Timers behavior handlers.
    void returnPrevSettings_anduin();
    void returnPrevSettings_sylvana();
    void returnPrevSettings_guldan();
    void returnPrevSettings_artas();

private:
    // UI object.
    Ui::heroPowersMenu *ui;

    // GeneralState class object to reach the global status.
    GeneralState *genState;

    // Timers to track time, when certain heropowers should
    // end their actions.
    QTimer *anduinTimer;
    QTimer *sylvanasTimer;
    QTimer *guldanTimer;
    QTimer *artasTimer;

    // Fields to check if some heropower was bought.
    bool anduinBought;
    bool sylvanasBought;
    bool guldanBought;
    bool artasBought;

    // Fields to handle with heropowers cooldowns.
    bool anduinCD;
    bool sylvanasCD;
    bool guldanCD;
    bool artasCD;
};
