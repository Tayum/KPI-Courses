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

    //
    void refreshCD();

private slots:
    // Slots for buttons behavior.
    void on_anduinMagic_btn_clicked();
    void on_sylvanasCritical_btn_clicked();
    void on_guldanRampage_btn_clicked();
    void on_artasUnity_btn_clicked();
    void on_tapDmg_btn_clicked();

    // Slots for timers.
    void returnPrevSettings_anduin();
    void returnPrevSettings_sylvana();
    void returnPrevSettings_guldan();
    void returnPrevSettings_artas();

private:
    // GeneralState class object to reach the global state.
    GeneralState *genState;

    // Timers to track time, when certain heropowers should
    // end their actions.
    QTimer *anduinTimer;
    QTimer *sylvanasTimer;
    QTimer *guldanTimer;
    QTimer *artasTimer;

    //
    bool anduinBought;
    bool sylvanasBought;
    bool guldanBought;
    bool artasBought;

    //
    bool anduinCD;
    bool sylvanasCD;
    bool guldanCD;
    bool artasCD;

    Ui::heroPowersMenu *ui;
};
