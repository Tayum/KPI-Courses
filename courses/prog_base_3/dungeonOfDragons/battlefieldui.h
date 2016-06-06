#pragma once

#include <QMainWindow>
#include <QTimer>
#include <QCloseEvent>

#include "stats.h"
#include "achvments.h"
#include "army.h"
#include "enemy.h"

#include "perksui.h"
#include "achvmentsui.h"
#include "heropowers.h"
#include "settingsui.h"

namespace Ui {
class BattleFieldUI;
}

class BattleFieldUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit BattleFieldUI(QWidget *parent = 0);
    ~BattleFieldUI();

private:
    Ui::BattleFieldUI *ui;
    PerksUI *perksUi;
    AchvmentsUI *achvmentsUi;
    SettingsUI *settingsUi;

    Achvments *achievements;
    Army *army;
    Enemy *enemy;
    Stats *stats;
    HeroPowers *heropowers;

    QTimer *armyAttackTimer;
    QTimer *statsUIUpdateTimer;

    void closeEvent(QCloseEvent *e);

private slots:
    void armyAttack();
    void uiUpdate();
    void buySoldier();
    void on_monster_btn_clicked();
    void on_perks_btn_clicked();
    void on_achvments_btn_clicked();
    void on_tapDmg_btn_clicked();
    // Heropowers buttons.
    void on_anduinMagic_btn_clicked();
    void on_sylvanasCritical_btn_clicked();
    void on_guldanRampage_btn_clicked();
    void on_artasUnity_btn_clicked();
    void on_settings_btn_clicked();
    void returnPrevSettings_anduin();
    void returnPrevSettings_sylvana();
    void returnPrevSettings_guldan();
    void returnPrevSettings_artas();
};
