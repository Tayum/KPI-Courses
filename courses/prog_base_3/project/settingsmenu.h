#pragma once

#include <QDialog>

#include "generalstate.h"
#include "globalstatsmenu.h"

namespace Ui {
class SettingsMenu;
}

class SettingsMenu : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsMenu(GeneralState *in_generalState, QWidget *parent = 0);
    ~SettingsMenu();

private slots:
    // Opening other windows.
    void on_stats_btn_clicked();

private:
    // UI object.
    Ui::SettingsMenu *ui;

    // General game status.
    GeneralState *gnrlState;

    // Windows, that are located in 'Settings' menu.
    GlobalStatsMenu *glblStats;
};
