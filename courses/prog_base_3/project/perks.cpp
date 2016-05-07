#include <QTimer>

#include "dragonenemy.h"
#include "heropowersmenu.h"
#include "perks.h"
#include "ui_perks.h"

// What perks do.
#define ELDORADO_VALUE 100
#define DIAMRUSH_VALUE 100
#define ENCHSWORD_VALUE 20

// Perks cost.
#define DIAMRUSH_COST 5000
#define ELDORADO_COST 100
#define ENCHSWORD_COST 100
#define WINDFARM_COST 100
#define PASSLVL_COST 100

Perks::Perks(GeneralState *in_generalState, DragonEnemy *in_dragonEnemy, HeroPowersMenu *in_heropowers, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Perks)
{
    // Initialize Perks Dialog UI.
    this->ui->setupUi(this);

    // Disable 'help' button.
    Qt::WindowFlags flags = this->windowFlags();
    flags &= ~Qt::WindowContextHelpButtonHint;
    this->setWindowFlags(flags);

    // Copy general data from other classes.
    this->gnrlState = in_generalState;
    this->drgnEnemy = in_dragonEnemy;
    this->heroPwrs = in_heropowers;
}

Perks::~Perks()
{
    delete ui;
}

void Perks::on_perksBtn_DiamondsRush_clicked()
{
    // check if player has enough gold
    if(this->gnrlState->CurrentGold >= DIAMRUSH_COST) {
        // get perk
        this->gnrlState->CurrentDiamonds += DIAMRUSH_VALUE;
        this->gnrlState->TotalDiamondsCollected += DIAMRUSH_VALUE;
        // pay for the perk
        this->gnrlState->CurrentGold -= DIAMRUSH_COST;
    }
}

void Perks::on_perksBtn_Eldorado_clicked()
{
    // check if player has enough diamonds
    if(this->gnrlState->CurrentDiamonds >= ELDORADO_COST) {
        // get perk
        this->gnrlState->CurrentGold += ELDORADO_VALUE;
        this->gnrlState->TotalGoldCollected += ELDORADO_VALUE;
        // pay for the perk
        this->gnrlState->CurrentDiamonds -= ELDORADO_COST;
    }
}

void Perks::on_perksBtn_EnchSword_clicked()
{
    // check if player has enough diamonds
    if(this->gnrlState->CurrentDiamonds >= ENCHSWORD_COST) {
        // get perk
        this->drgnEnemy->CurrentHP -= ENCHSWORD_VALUE;
        // pay diamonds
        this->gnrlState->CurrentDiamonds -= ENCHSWORD_COST;
    }
    // Check if mosnter is dead.
    if(this->drgnEnemy->CurrentHP <= 0)
    {
        // change general status fields.
        this->gnrlState->CurrentGold += this->drgnEnemy->GoldDropped;
        this->gnrlState->CurrentDiamonds += this->drgnEnemy->DiamondsDropped;
        this->gnrlState->TotalGoldCollected += this->drgnEnemy->GoldDropped;
        this->gnrlState->TotalDiamondsCollected += this->drgnEnemy->DiamondsDropped;
        this->gnrlState->TotalMonsterKills++;
        // new dragon
        this->gnrlState->CurrentLevel++;
        this->drgnEnemy->goToNextDragon(this->drgnEnemy);
    }
}

void Perks::on_perksBtn_WindfArmory_clicked()
{
    // check if player has enough diamonds
    if(this->gnrlState->CurrentDiamonds >= WINDFARM_COST) {
        // get perk
        this->heroPwrs->refreshCD();
        // pay diamonds
        this->gnrlState->CurrentDiamonds -= WINDFARM_COST;
    }
}

void Perks::on_perksBtn_PassLevel_clicked()
{
    // check if player has enough diamonds
    if(this->gnrlState->CurrentDiamonds >= PASSLVL_COST) {
        // get perk
        // new level
        // change general status fields.
        this->gnrlState->CurrentGold += this->drgnEnemy->GoldDropped;
        this->gnrlState->CurrentDiamonds += this->drgnEnemy->DiamondsDropped;
        this->gnrlState->TotalGoldCollected += this->drgnEnemy->GoldDropped;
        this->gnrlState->TotalDiamondsCollected += this->drgnEnemy->DiamondsDropped;
        this->gnrlState->TotalMonsterKills++;
        this->gnrlState->CurrentLevel++;
        // new dragon
        this->drgnEnemy->goToNextDragon(this->drgnEnemy);\
        // pay diamonds
        this->gnrlState->CurrentDiamonds -= PASSLVL_COST;
    }
}
