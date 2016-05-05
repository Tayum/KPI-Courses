#include "perks.h"
#include "ui_perks.h"

#include "dragonenemy.h"

#include <QDebug>
#include <QTimer>

Perks::Perks(GeneralState *in_generalState, DragonEnemy *in_dragonEnemy, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Perks)
{
    // Get main data from main generalState and dragonEnemy classes.
    this->perks_generalState = in_generalState;
    this->perks_dragonEnemy = in_dragonEnemy;

    // Initialize Perks Dialog UI.
    this->ui->setupUi(this);

    // Initialize timer. TEST TEST TEST
    this->windfTimer = new QTimer(this);
    this->prevDmg = 0;
}

Perks::~Perks()
{
    delete ui;
}

void Perks::on_perksBtn_DiamondsRush_clicked()
{
    this->perks_generalState->CurrentDiamonds += RUSH_DIAMONDS;
    this->perks_generalState->TotalDiamondsCollected += RUSH_DIAMONDS;
}

void Perks::on_perksBtn_Eldorado_clicked()
{
    this->perks_generalState->CurrentGold += ELDORADO_MONEY;
    this->perks_generalState->TotalGoldCollected += ELDORADO_MONEY;
}

void Perks::on_perksBtn_EnchSword_clicked()
{
    this->perks_dragonEnemy->CurrentHP -= SWORD_DMG;
    if(this->perks_dragonEnemy->CurrentHP <= 0)
    {
        this->perks_generalState->CurrentGold += this->perks_dragonEnemy->GoldDropped;
        this->perks_generalState->CurrentDiamonds += this->perks_dragonEnemy->DiamondsDropped;
        this->perks_generalState->TotalGoldCollected += this->perks_dragonEnemy->GoldDropped;
        this->perks_generalState->TotalDiamondsCollected += this->perks_dragonEnemy->DiamondsDropped;
        this->perks_generalState->TotalMonsterKills++;
        // new dragon:
        this->perks_generalState->CurrentLevel++;
        this->perks_dragonEnemy->goToNextDragon(this->perks_dragonEnemy);
    }
}

void Perks::on_perksBtn_WindfArmory_clicked()
{

}

void Perks::on_perksBtn_PassLevel_clicked()
{
    this->perks_generalState->CurrentGold += this->perks_dragonEnemy->GoldDropped;
    this->perks_generalState->CurrentDiamonds += this->perks_dragonEnemy->DiamondsDropped;
    this->perks_generalState->TotalGoldCollected += this->perks_dragonEnemy->GoldDropped;
    this->perks_generalState->TotalDiamondsCollected += this->perks_dragonEnemy->DiamondsDropped;
    this->perks_generalState->TotalMonsterKills++;
    // new dragon:
    this->perks_generalState->CurrentLevel++;
    this->perks_dragonEnemy->goToNextDragon(this->perks_dragonEnemy);
}
