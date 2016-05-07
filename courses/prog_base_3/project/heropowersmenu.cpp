#include <QTimer>

#include "heropowersmenu.h"
#include "ui_heropowersmenu.h"

//
#define TAPDMG_UPGRADE_COST 50
#define ANDUIN_UPGRADE_COST 10
#define SYLVANAS_UPGRADE_COST 10
#define GULDAN_UPGRADE_COST 100
#define ARTAS_UPGRADE_COST 10

//
#define TAPDMG_UPGRADE_VALUE 1
#define ANDUIN_UPGRADE_VALUE 3
#define SYLVANAS_UPGRADE_VALUE 0.25
#define GULDAN_UPGRADE_VALUE 500
#define ARTAS_UPGRADE_VALUE 50

//
#define ANDUIN_DURATION_MS 5000
#define SYLVANA_DURATION_MS 10000
#define GULDAN_DURATION_MS 5000
#define ARTAS_DURATION_MS 5000

HeroPowersMenu::HeroPowersMenu(GeneralState *in_generalState, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::heroPowersMenu)
{
    // Initialize HireArmy Dialog UI.
    this->ui->setupUi(this);

    // Disable 'help' button.
    Qt::WindowFlags flags = this->windowFlags();
    flags &= ~Qt::WindowContextHelpButtonHint;
    this->setWindowFlags(flags);

    // Initialize GeneralState class object with data about global status.
    this->genState = in_generalState;

    // Timers assign.
    this->anduinTimer = new QTimer(this);
    this->sylvanasTimer = new QTimer(this);
    this->guldanTimer = new QTimer(this);
    this->artasTimer = new QTimer(this);

    //
    this->anduinBought = false;
    this->sylvanasBought = false;
    this->guldanBought = false;
    this->artasBought = false;

    //
    this->anduinCD = false;
    this->sylvanasCD = false;
    this->guldanCD = false;
    this->artasCD = false;
}

HeroPowersMenu::~HeroPowersMenu()
{
    delete this->anduinTimer;
    delete this->sylvanasTimer;
    delete this->guldanTimer;
    delete this->artasTimer;

    delete ui;
}

void HeroPowersMenu::refreshCD()
{
    this->anduinCD = true;
    this->sylvanasCD = true;
    this->guldanCD = true;
    this->artasCD = true;
}

void HeroPowersMenu::on_tapDmg_btn_clicked()
{
    if(this->genState->CurrentGold >= TAPDMG_UPGRADE_COST) {
        this->genState->CurrentTapDamage += TAPDMG_UPGRADE_VALUE;
        this->genState->CurrentGold -= TAPDMG_UPGRADE_COST;
    }
}

void HeroPowersMenu::on_anduinMagic_btn_clicked()
{
    // Use ability, if cooldown equals to true.
    if(this->anduinCD) {
        this->genState->CurrentTapDamage *= ANDUIN_UPGRADE_VALUE;
        this->anduinCD = false;
        this->anduinTimer->start(ANDUIN_DURATION_MS);
        connect(anduinTimer, SIGNAL(timeout()), this, SLOT(returnPrevSettings_anduin()));
    }
    // Check if ability was bought.
    if(this->genState->CurrentGold >= ANDUIN_UPGRADE_COST && !anduinBought) {
        this->anduinCD = true;
        this->anduinBought = true;
        this->genState->CurrentGold -= ANDUIN_UPGRADE_COST;
    }
}
void HeroPowersMenu::returnPrevSettings_anduin()
{
    this->anduinTimer->stop();
    disconnect(anduinTimer, SIGNAL(timeout()), this, SLOT(returnPrevSettings_anduin()));
    this->genState->CurrentTapDamage /= ANDUIN_UPGRADE_VALUE;
    this->anduinCD = true;
}

void HeroPowersMenu::on_sylvanasCritical_btn_clicked()
{
    if(this->sylvanasCD) {
        this->genState->CurrentCriticalChance += SYLVANAS_UPGRADE_VALUE;
        this->sylvanasCD = false;
        this->sylvanasTimer->start(SYLVANA_DURATION_MS);
        connect(sylvanasTimer, SIGNAL(timeout()), this, SLOT(returnPrevSettings_sylvana()));
    }
    if(this->genState->CurrentGold >= SYLVANAS_UPGRADE_COST && !sylvanasBought) {
        this->sylvanasCD = true;
        this->sylvanasBought = true;
        this->genState->CurrentGold -= SYLVANAS_UPGRADE_COST;
    }
}
void HeroPowersMenu::returnPrevSettings_sylvana()
{
    this->sylvanasTimer->stop();
    disconnect(sylvanasTimer, SIGNAL(timeout()), this, SLOT(returnPrevSettings_sylvana()));
    this->genState->CurrentCriticalChance -= SYLVANAS_UPGRADE_VALUE;
    this->sylvanasCD = true;
}

void HeroPowersMenu::on_guldanRampage_btn_clicked()
{
    if(this->guldanCD) {
        this->genState->CurrentArmyDamage += GULDAN_UPGRADE_VALUE;
        this->guldanCD = true;
        this->guldanTimer->start(GULDAN_DURATION_MS);
        connect(guldanTimer, SIGNAL(timeout()), this, SLOT(returnPrevSettings_guldan()));
    }
    if(this->genState->CurrentGold >= GULDAN_UPGRADE_COST && !guldanBought) {
        this->guldanCD = true;
        this->guldanBought = true;
        this->genState->CurrentGold -= GULDAN_UPGRADE_COST;
    }
}
void HeroPowersMenu::returnPrevSettings_guldan()
{
    this->guldanTimer->stop();
    disconnect(guldanTimer, SIGNAL(timeout()), this, SLOT(returnPrevSettings_guldan()));
    this->genState->CurrentArmyDamage -= GULDAN_UPGRADE_VALUE;
    this->guldanCD = true;
}

void HeroPowersMenu::on_artasUnity_btn_clicked()
{
    if(this->artasCD) {
        this->genState->CurrentTapDamage += ARTAS_UPGRADE_VALUE;
        this->artasCD = false;
        this->artasTimer->start(ARTAS_DURATION_MS);
        connect(artasTimer, SIGNAL(timeout()), this, SLOT(returnPrevSettings_artas()));
    }

    if(this->genState->CurrentGold >= ARTAS_UPGRADE_COST && !artasBought) {
        this->artasCD = true;
        this->artasBought = true;
        this->genState->CurrentGold -= ARTAS_UPGRADE_COST;
    }
}
void HeroPowersMenu::returnPrevSettings_artas()
{
    this->artasTimer->stop();
    disconnect(artasTimer, SIGNAL(timeout()), this, SLOT(returnPrevSettings_artas()));
    this->genState->CurrentTapDamage -= ARTAS_UPGRADE_VALUE;
    this->artasCD = true;
}
