#include "globalstatsmenu.h"
#include "settingsmenu.h"
#include "ui_settingsmenu.h"

SettingsMenu::SettingsMenu(GeneralState *in_generalState, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsMenu)
{
    // Initialize Settings Dialog UI.
    ui->setupUi(this);

    // Disable 'help' button.
    Qt::WindowFlags flags = this->windowFlags();
    flags &= ~Qt::WindowContextHelpButtonHint;
    this->setWindowFlags(flags);

    // Copy general data from BattleField.
    this->gnrlState = in_generalState;

    // Initialize objects for window, that can be opened from 'settings' menu.
    this->glblStats = new GlobalStatsMenu(this->gnrlState, this);
}

SettingsMenu::~SettingsMenu()
{
    delete this->glblStats;
    delete ui;
}

void SettingsMenu::on_stats_btn_clicked()
{
    // Open a window, if it is not opened yet.
    if(!this->glblStats->isVisible())
        this->glblStats->show();
    // If window is already open - change focus.
    this->glblStats->activateWindow();
}
