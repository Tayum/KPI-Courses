#include <QTimer>
#include <QTime>

#include "generalstate.h"
#include "globalstatsmenu.h"
#include "ui_globalstatsmenu.h"

#define UPDATE_TIME_MS 100

GlobalStatsMenu::GlobalStatsMenu(GeneralState *in_generalState, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GlobalStatsMenu)
{
    // Initialize HireArmy Dialog UI.
    ui->setupUi(this);

    // Disable 'help' button.
    Qt::WindowFlags flags = this->windowFlags();
    flags &= ~Qt::WindowContextHelpButtonHint;
    this->setWindowFlags(flags);

    // Initialize GeneralState class object with data about global status.
    this->gnrlState = in_generalState;

    // Initialize timer to update every 100ms global status menu.
    this->updateTimer = new QTimer(this);
    connect(updateTimer, SIGNAL(timeout()), this, SLOT(updateUI()));
    updateTimer->start(UPDATE_TIME_MS);
}

GlobalStatsMenu::~GlobalStatsMenu()
{
    delete this->updateTimer;
    delete ui;
}

void GlobalStatsMenu::updateUI()
{
    this->ui->label_1->setText(QString::number(this->gnrlState->CurrentLevel));
    this->ui->label_2->setText(QString::number(this->gnrlState->MissionsCompleted));
    this->ui->label_3->setText(QString::number(this->gnrlState->ArmyAmount));
    this->ui->label_4->setText(QString::number(this->gnrlState->ArtifactsUnlocked));
    this->ui->label_5->setText(QString::number(this->gnrlState->HeropowersUnlocked));
    this->ui->label_6->setText(QString::number(this->gnrlState->AwardsCollected));
    this->ui->label_7->setText(QString::number(this->gnrlState->CurrentTapDamage));
    this->ui->label_8->setText(QString::number(this->gnrlState->CurrentCriticalChance));
    this->ui->label_9->setText(QString::number(this->gnrlState->CurrentArmyDamage));
    this->ui->label_10->setText(QString::number(this->gnrlState->DPSMultiplier));
    this->ui->label_11->setText(QString::number(this->gnrlState->CriticalHitMultiplier));
    this->ui->label_12->setText(QString::number(this->gnrlState->GoldMultiplier));
    this->ui->label_13->setText(QString::number(this->gnrlState->TotalGoldCollected));
    this->ui->label_14->setText("Total clicks made");
    this->ui->label_15->setText("Total critical clicks made");
    this->ui->label_16->setText(QString::number(this->gnrlState->TotalMonsterKills));
    this->ui->label_17->setText(this->gnrlState->TotalPlayTime.toString("HH:mm:ss"));
    this->ui->label_18->setText("Position in total rank");
}
