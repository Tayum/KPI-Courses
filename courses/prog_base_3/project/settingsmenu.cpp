#include "globalstatsmenu.h"
#include "settingsmenu.h"
#include "ui_settingsmenu.h"

SettingsMenu::SettingsMenu(GeneralState *in_generalState, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsMenu)
{
    ui->setupUi(this);

    this->gnrlState = in_generalState;
    this->glblStats = new GlobalStatsMenu(this->gnrlState, this);
}

SettingsMenu::~SettingsMenu()
{
    delete this->glblStats;

    delete ui;
}

void SettingsMenu::on_stats_btn_clicked()
{
    if(!this->glblStats->isVisible())
    {
        this->glblStats->show();
    }
    this->glblStats->activateWindow();
}
