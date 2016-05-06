#include "achievementsmenu.h"
#include "ui_achievementsmenu.h"

#include <QTimer>
#include <QDebug>

AchievementsMenu::AchievementsMenu(Achievements *in_achievements, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AchievementsMenu)
{
    this->achObj = in_achievements;
    ui->setupUi(this);

    // Each 100ms check if some achievement was reached.
    this->updateTimer = new QTimer(this);
    connect(updateTimer, SIGNAL(timeout()), this, SLOT(updateUI()));
    updateTimer->start(100);
}

AchievementsMenu::~AchievementsMenu()
{
    delete ui;
}

void AchievementsMenu::updateUI()
{
    if(this->achObj->Ach_EarnNGold)
        ui->ach1_status_lbl->setText("true");
    if(this->achObj->Ach_EarnNDiamonds)
        ui->ach2_status_lbl->setText("true");
    if(this->achObj->Ach_KillNMonsters)
        ui->ach3_status_lbl->setText("true");
    if(this->achObj->Ach_ReachNStage)
        ui->ach4_status_lbl->setText("true");
    if(this->achObj->Ach_OwnNArtifacts)
        ui->ach5_status_lbl->setText("true");
    if(this->achObj->Ach_HireNSoldiers)
        ui->ach6_status_lbl->setText("true");
    if(this->achObj->Ach_TapNTimes)
        ui->ach7_status_lbl->setText("true");
    if(this->achObj->Ach_HeropowNTimes)
        ui->ach8_status_lbl->setText("true");
    if(this->achObj->Ach_DoNCritical)
        ui->ach9_status_lbl->setText("true");
    if(this->achObj->Ach_Hidden_MLG)
        ui->ach10_status_lbl->setText("true");
    if(this->achObj->Ach_Hidden_TenEach)
        ui->ach11_status_lbl->setText("true");
}
