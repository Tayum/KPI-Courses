#include "heropowers.h"

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

HeroPowers::HeroPowers(Stats *stats, QWidget *parent) : QObject(parent)
{
    this->stats = stats;
    this->parent = parent;

    this->anduinTimer = new QTimer();
    this->sylvanasTimer = new QTimer();
    this->guldanTimer = new QTimer();
    this->artasTimer = new QTimer();

    this->anduinBought = false;
    this->sylvanasBought = false;
    this->guldanBought = false;
    this->artasBought = false;

    this->anduinCD = false;
    this->sylvanasCD = false;
    this->guldanCD = false;
    this->artasCD = false;
}

HeroPowers::~HeroPowers()
{
    delete this->anduinTimer;
    delete this->sylvanasTimer;
    delete this->guldanTimer;
    delete this->artasTimer;
}

void HeroPowers::refreshCD()
{
    this->anduinCD = true;
    this->sylvanasCD = true;
    this->guldanCD = true;
    this->artasCD = true;
}

void HeroPowers::on_tapDmg_btn_clicked()
{
    if(this->stats->CurrentGold >= TAPDMG_UPGRADE_COST) {
        this->stats->CurrentTapDamage += TAPDMG_UPGRADE_VALUE;
        this->stats->CurrentGold -= TAPDMG_UPGRADE_COST;
    }
}

void HeroPowers::on_anduinMagic_btn_clicked()
{
    // Use ability, if cooldown equals to true.
    if(this->anduinCD) {
        this->stats->CurrentTapDamage *= ANDUIN_UPGRADE_VALUE;
        this->anduinCD = false;
        this->anduinTimer->start(ANDUIN_DURATION_MS);
        this->parent->connect(anduinTimer, SIGNAL(timeout()), this->parent, SLOT(returnPrevSettings_anduin()));
    }
    // Check if ability was bought.
    if(this->stats->CurrentGold >= ANDUIN_UPGRADE_COST && !anduinBought) {
        this->anduinCD = true;
        this->anduinBought = true;
        this->stats->CurrentGold -= ANDUIN_UPGRADE_COST;
    }
}
void HeroPowers::returnPrevSettings_anduin()
{
    this->anduinTimer->stop();
    this->parent->disconnect(anduinTimer, SIGNAL(timeout()), this->parent, SLOT(returnPrevSettings_anduin()));
    this->stats->CurrentTapDamage /= ANDUIN_UPGRADE_VALUE;
    this->anduinCD = true;
}

void HeroPowers::on_sylvanasCritical_btn_clicked()
{
    if(this->sylvanasCD) {
        this->stats->CurrentCriticalChance += SYLVANAS_UPGRADE_VALUE;
        this->sylvanasCD = false;
        this->sylvanasTimer->start(SYLVANA_DURATION_MS);
        this->parent->connect(sylvanasTimer, SIGNAL(timeout()), this->parent, SLOT(returnPrevSettings_sylvana()));
    }
    if(this->stats->CurrentGold >= SYLVANAS_UPGRADE_COST && !sylvanasBought) {
        this->sylvanasCD = true;
        this->sylvanasBought = true;
        this->stats->CurrentGold -= SYLVANAS_UPGRADE_COST;
    }
}
void HeroPowers::returnPrevSettings_sylvana()
{
    this->sylvanasTimer->stop();
    this->parent->disconnect(sylvanasTimer, SIGNAL(timeout()), this->parent, SLOT(returnPrevSettings_sylvana()));
    this->stats->CurrentCriticalChance -= SYLVANAS_UPGRADE_VALUE;
    this->sylvanasCD = true;
}

void HeroPowers::on_guldanRampage_btn_clicked()
{
    if(this->guldanCD) {
        this->stats->CurrentArmyDamage += GULDAN_UPGRADE_VALUE;
        this->guldanCD = true;
        this->guldanTimer->start(GULDAN_DURATION_MS);
        this->parent->connect(guldanTimer, SIGNAL(timeout()), this->parent, SLOT(returnPrevSettings_guldan()));
    }
    if(this->stats->CurrentGold >= GULDAN_UPGRADE_COST && !guldanBought) {
        this->guldanCD = true;
        this->guldanBought = true;
        this->stats->CurrentGold -= GULDAN_UPGRADE_COST;
    }
}
void HeroPowers::returnPrevSettings_guldan()
{
    this->guldanTimer->stop();
    this->parent->disconnect(guldanTimer, SIGNAL(timeout()), this->parent, SLOT(returnPrevSettings_guldan()));
    this->stats->CurrentArmyDamage -= GULDAN_UPGRADE_VALUE;
    this->guldanCD = true;
}

void HeroPowers::on_artasUnity_btn_clicked()
{
    if(this->artasCD) {
        this->stats->CurrentTapDamage += ARTAS_UPGRADE_VALUE;
        this->artasCD = false;
        this->artasTimer->start(ARTAS_DURATION_MS);
        this->parent->connect(artasTimer, SIGNAL(timeout()), this->parent, SLOT(returnPrevSettings_artas()));
    }

    if(this->stats->CurrentGold >= ARTAS_UPGRADE_COST && !artasBought) {
        this->artasCD = true;
        this->artasBought = true;
        this->stats->CurrentGold -= ARTAS_UPGRADE_COST;
    }
}
void HeroPowers::returnPrevSettings_artas()
{
    this->artasTimer->stop();
    this->parent->disconnect(artasTimer, SIGNAL(timeout()), this->parent, SLOT(returnPrevSettings_artas()));
    this->stats->CurrentTapDamage -= ARTAS_UPGRADE_VALUE;
    this->artasCD = true;
}
