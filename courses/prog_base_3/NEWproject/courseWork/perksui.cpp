#include "perksui.h"
#include "ui_perksui.h"

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

PerksUI::PerksUI(Stats *stats, Enemy *enemy, HeroPowers *heropowers, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PerksUI)
{
    // Initialize Perks Dialog UI.
    ui->setupUi(this);

    // Disable 'help' button.
    Qt::WindowFlags flags = this->windowFlags();
    flags &= ~Qt::WindowContextHelpButtonHint;
    this->setWindowFlags(flags);
    // Disable resizing window.
    this->setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);

    // Copy general data from other classes.
    this->enemy = enemy;
    this->stats = stats;
    this->heropowers = heropowers;
}

PerksUI::~PerksUI()
{
    delete this->ui;
}

void PerksUI::on_perksPassLvl_btn_clicked()
{
    // check if player has enough diamonds
    if (this->stats->CurrentDiamonds >= PASSLVL_COST)
    {
        this->enemy->goToNextDragon(this->stats);
        this->stats->CurrentDiamonds -= PASSLVL_COST;
    }
}

void PerksUI::on_perksDmndRush_btn_clicked()
{
    if (this->stats->CurrentGold >= DIAMRUSH_COST)
    {
        this->stats->CurrentDiamonds += DIAMRUSH_VALUE;
        this->stats->TotalDiamondsCollected += DIAMRUSH_VALUE;
        this->stats->CurrentGold -= DIAMRUSH_COST;
    }
}

void PerksUI::on_perksEnchantedSwrd_btn_clicked()
{
    bool isKilled = false;
    if (this->stats->CurrentDiamonds >= ENCHSWORD_COST) {
        isKilled = this->enemy->doDamage(ENCHSWORD_VALUE);
        this->stats->CurrentDiamonds -= ENCHSWORD_COST;
    }
    if (isKilled)
    {
        this->enemy->goToNextDragon(this->stats);
    }
}

void PerksUI::on_perksEldoradoBtn_clicked()
{
    if (this->stats->CurrentDiamonds >= ELDORADO_COST)
    {
        this->stats->CurrentGold += ELDORADO_VALUE;
        this->stats->TotalGoldCollected += ELDORADO_VALUE;
        this->stats->CurrentDiamonds -= ELDORADO_COST;
    }
}

void PerksUI::on_perksWindfury_btn_clicked()
{
    if (this->stats->CurrentDiamonds >= WINDFARM_COST) {
        this->heropowers->refreshCD();
        this->stats->CurrentDiamonds -= WINDFARM_COST;
    }
}
