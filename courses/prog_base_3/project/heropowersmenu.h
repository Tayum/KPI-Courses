#pragma once

#include <QDialog>
#include <QTimer>

#include "generalstate.h"

#define ANDUIN_DURATION 5000
#define SYLVANA_DURATION 10000
#define GULDAN_DURATION 5000
#define ARTAS_DURATION 5000

namespace Ui {
class heroPowersMenu;
}

class HeroPowersMenu : public QDialog
{
    Q_OBJECT

public:
    explicit HeroPowersMenu(GeneralState *in_generalState, QWidget *parent = 0);
    ~HeroPowersMenu();

    GeneralState *genState;

private slots:
    // Button slots:
    void on_anduinMagic_btn_clicked();
    void on_sylvanasCritical_btn_clicked();
    void on_guldanRampage_btn_clicked();
    void on_artasUnity_btn_clicked();
    // Timer slots:
    void returnPrevSettings_anduin();
    void returnPrevSettings_sylvana();
    void returnPrevSettings_guldan();
    void returnPrevSettings_artas();

private:
    QTimer *anduinTimer;
    QTimer *sylvanasTimer;
    QTimer *guldanTimer;
    QTimer *artasTimer;
    Ui::heroPowersMenu *ui;
};
