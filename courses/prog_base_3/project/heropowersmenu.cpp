#include <QTimer>

#include "heropowersmenu.h"
#include "ui_heropowersmenu.h"

#define ANDUIN_DURATION_MS 5000
#define SYLVANA_DURATION_MS 10000
#define GULDAN_DURATION_MS 5000
#define ARTAS_DURATION_MS 5000

HeroPowersMenu::HeroPowersMenu(GeneralState *in_generalState, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::heroPowersMenu)
{
    this->ui->setupUi(this);

    // Initialize GeneralState class object with data about global status.
    this->genState = in_generalState;

    // Timers assign.
    this->anduinTimer = new QTimer(this);
    this->sylvanasTimer = new QTimer(this);
    this->guldanTimer = new QTimer(this);
    this->artasTimer = new QTimer(this);
}

HeroPowersMenu::~HeroPowersMenu()
{
    delete ui;
}

void HeroPowersMenu::on_anduinMagic_btn_clicked()
{
    this->genState->CurrentTapDamage *= 3;
    this->anduinTimer->start(ANDUIN_DURATION_MS);
    connect(anduinTimer, SIGNAL(timeout()), this, SLOT(returnPrevSettings_anduin()));
}
void HeroPowersMenu::returnPrevSettings_anduin()
{
    this->genState->CurrentTapDamage /= 3;
    this->anduinTimer->stop();
    disconnect(anduinTimer, SIGNAL(timeout()), this, SLOT(returnPrevSettings_anduin()));
}

void HeroPowersMenu::on_sylvanasCritical_btn_clicked()
{
    this->genState->CurrentCriticalChance += 0.25;
    this->sylvanasTimer->start(SYLVANA_DURATION_MS);
    connect(sylvanasTimer, SIGNAL(timeout()), this, SLOT(returnPrevSettings_sylvana()));
}
void HeroPowersMenu::returnPrevSettings_sylvana()
{
    this->genState->CurrentCriticalChance -= 0.25;
    this->sylvanasTimer->stop();
    disconnect(sylvanasTimer, SIGNAL(timeout()), this, SLOT(returnPrevSettings_sylvana()));
}

void HeroPowersMenu::on_guldanRampage_btn_clicked()
{
    this->genState->CurrentArmyDamage += 500;
    this->guldanTimer->start(GULDAN_DURATION_MS);
    connect(guldanTimer, SIGNAL(timeout()), this, SLOT(returnPrevSettings_guldan()));
}
void HeroPowersMenu::returnPrevSettings_guldan()
{
    this->genState->CurrentArmyDamage -= 500;
    this->guldanTimer->stop();
    disconnect(guldanTimer, SIGNAL(timeout()), this, SLOT(returnPrevSettings_guldan()));
}

void HeroPowersMenu::on_artasUnity_btn_clicked()
{
    this->genState->CurrentTapDamage += 50;
    this->artasTimer->start(ARTAS_DURATION_MS);
    connect(artasTimer, SIGNAL(timeout()), this, SLOT(returnPrevSettings_artas()));
}
void HeroPowersMenu::returnPrevSettings_artas()
{
    this->genState->CurrentTapDamage -= 50;
    this->artasTimer->stop();
    disconnect(artasTimer, SIGNAL(timeout()), this, SLOT(returnPrevSettings_artas()));
}
