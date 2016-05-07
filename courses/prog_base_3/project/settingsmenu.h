#ifndef SETTINGSMENU_H
#define SETTINGSMENU_H

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
    void on_stats_btn_clicked();

private:
    GeneralState *gnrlState;
    GlobalStatsMenu *glblStats;
    Ui::SettingsMenu *ui;
};

#endif // SETTINGSMENU_H
