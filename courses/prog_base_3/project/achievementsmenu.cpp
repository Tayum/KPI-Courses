#include <QTimer>

#include "achievementsmenu.h"
#include "ui_achievementsmenu.h"

#define UPDATE_TIME_MS 100

AchievementsMenu::AchievementsMenu(Achievements *in_achievements, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AchievementsMenu)
{
    ui->setupUi(this);

    // Initialize achievement object class with global data.
    this->achObj = in_achievements;

    // Each 100ms check if some achievement was reached.
    this->updateTimer = new QTimer(this);
    connect(updateTimer, SIGNAL(timeout()), this, SLOT(updateUI()));
    updateTimer->start(UPDATE_TIME_MS);
}

AchievementsMenu::~AchievementsMenu()
{
    delete ui;
}

void AchievementsMenu::updateUI()
{
    // Go through all achievements and check if some of them was reached.
    // If the condition is met, change certain status label so it will show
    // player, that he unlocked an achievement.
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
