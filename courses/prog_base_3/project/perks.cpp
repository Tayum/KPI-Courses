#include <QDebug>
#include <QTimer>
#include <QDebug>

#include "perks.h"
#include "ui_perks.h"
#include "heropowersmenu.h"

#include "dragonenemy.h"

//
#define ELDORADO_MONEY 100
#define RUSH_DIAMONDS 100
#define SWORD_DMG 20

//
#define ENCHSWORD_COST 100
#define WINDFARM_COST 100
#define PASSLVL_COST 100

Perks::Perks(GeneralState *in_generalState, DragonEnemy *in_dragonEnemy, HeroPowersMenu *in_heropowers, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Perks)
{
    // Get main data from main generalState and dragonEnemy classes.
    this->perks_generalState = in_generalState;
    this->perks_dragonEnemy = in_dragonEnemy;
    this->perks_heroPowers = in_heropowers;

    // Initialize Perks Dialog UI.
    this->ui->setupUi(this);

    // Disable 'help' button.
    Qt::WindowFlags flags = this->windowFlags();
    flags &= ~Qt::WindowContextHelpButtonHint;
    this->setWindowFlags(flags);
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
    qDebug() << this->perks_generalState->CurrentDiamonds;

    if(this->perks_generalState->CurrentDiamonds >= ENCHSWORD_COST) {
        this->perks_dragonEnemy->CurrentHP -= SWORD_DMG;
        // pay diamonds
        this->perks_generalState->CurrentDiamonds -= ENCHSWORD_COST;
    }
    // Check if mosnter is dead.
    if(this->perks_dragonEnemy->CurrentHP <= 0)
    {
        // change general status fields.
        this->perks_generalState->CurrentGold += this->perks_dragonEnemy->GoldDropped;
        this->perks_generalState->CurrentDiamonds += this->perks_dragonEnemy->DiamondsDropped;
        this->perks_generalState->TotalGoldCollected += this->perks_dragonEnemy->GoldDropped;
        this->perks_generalState->TotalDiamondsCollected += this->perks_dragonEnemy->DiamondsDropped;
        this->perks_generalState->TotalMonsterKills++;
        // new dragon
        this->perks_generalState->CurrentLevel++;
        this->perks_dragonEnemy->goToNextDragon(this->perks_dragonEnemy);
    }
}

void Perks::on_perksBtn_WindfArmory_clicked()
{
    if(this->perks_generalState->CurrentDiamonds >= WINDFARM_COST) {
        this->perks_heroPowers->refreshCD();
        // pay diamonds
        this->perks_generalState->CurrentDiamonds -= WINDFARM_COST;
    }
}

void Perks::on_perksBtn_PassLevel_clicked()
{
    if(this->perks_generalState->CurrentDiamonds >= PASSLVL_COST) {
        // new level
        this->perks_generalState->CurrentGold += this->perks_dragonEnemy->GoldDropped;
        this->perks_generalState->CurrentDiamonds += this->perks_dragonEnemy->DiamondsDropped;
        this->perks_generalState->TotalGoldCollected += this->perks_dragonEnemy->GoldDropped;
        this->perks_generalState->TotalDiamondsCollected += this->perks_dragonEnemy->DiamondsDropped;
        this->perks_generalState->TotalMonsterKills++;
        // new dragon
        this->perks_generalState->CurrentLevel++;
        this->perks_dragonEnemy->goToNextDragon(this->perks_dragonEnemy);\
        // pay diamonds
        this->perks_generalState->CurrentDiamonds -= PASSLVL_COST;
    }
}
