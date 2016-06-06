#pragma once

#include <QTimer>
#include <QWidget>

#include "stats.h"

class HeroPowers : public QObject
{
    Q_OBJECT

public:
    HeroPowers(Stats *stats, QWidget *parent);
    ~HeroPowers();
    void refreshCD();

public slots:
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
    Stats *stats;
    QWidget *parent;

    // Timers to track time, when certain heropowers should end their actions.
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
