#include <QDesktopWidget>
#include <QMessageBox>
#include <QPushButton>
#include <QLabel>

#include "battlefieldui.h"
#include "ui_battlefieldui.h"

BattleFieldUI::BattleFieldUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BattleFieldUI)
{
    // Initialize class objects.
    this->achievements = new Achvments();
    this->army = new Army();
    this->stats = new Stats();
    this->enemy = new Enemy(this->stats->CurrentLevel);
    this->perksUi = new PerksUI(this->stats, this->enemy, this->heropowers, this);
    this->achvmentsUi = new AchvmentsUI(this->achievements, this);
    this->heropowers = new HeroPowers(this->stats, this);
    this->settingsUi = new SettingsUI(this->stats, this);

    // Main UI things.
    // Initialize UI objects.
    ui->setupUi(this);
    // Set exit prompt.
    this->setAttribute(Qt::WA_QuitOnClose);
    // Disable resizing a BattleField window.
    this->setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);
    // Disable 'maximize' and 'hide' button in a BattleField window.
    setWindowFlags(Qt::WindowMaximizeButtonHint | Qt::WindowCloseButtonHint);
    // Move BattleField window to the center of screen.
    this->move((QApplication::desktop()->width() - this->size().width()) / 2,
               (QApplication::desktop()->height() - this->size().height()) / 2 - 50);

    // "Battle field" tab.
    // Set monster button and first tab as default.
    ui->monster_btn->setDefault(true);
    ui->tabWidget->setCurrentIndex(0);
    // Initialize and start timer for army attack.
    this->armyAttackTimer = new QTimer(this);
    connect(armyAttackTimer, SIGNAL(timeout()), this, SLOT(armyAttack()));
    this->armyAttackTimer->start(1000);
    // Initialize and start timer for UI elements update.
    this->statsUIUpdateTimer = new QTimer(this);
    connect(statsUIUpdateTimer, SIGNAL(timeout()), this, SLOT(uiUpdate()));
    this->statsUIUpdateTimer->start(100);

    // "Hire army" tab.
    // Get text in labels and buttons from .txt file.
    for (int i = 1; i < 16; i++)
    {
        // Buttons.
        QString curBtnName = QString("soldier_btn_%1").arg(i);
        QPushButton *curButton = this->ui->tabWidget->findChild<QPushButton *>(curBtnName);
        connect(curButton, SIGNAL(released()), this, SLOT(buySoldier()));
        curButton->setText(this->army->army[i - 1].Name);
        // DPS labels.
        QString curDpsLblName = QString("soldier_dmg_lbl_%1").arg(i);
        QLabel *curDpsLabel = this->ui->tabWidget->findChild<QLabel *>(curDpsLblName);
        curDpsLabel->setText(QString::number(this->army->army[i - 1].DPS));
        // Price labels.
        QString curPriceLblName = QString("soldier_price_lbl_%1").arg(i);
        QLabel *curPriceLabel = this->ui->tabWidget->findChild<QLabel *>(curPriceLblName);
        curPriceLabel->setText(QString::number(this->army->army[i - 1].Price));
    }
}

BattleFieldUI::~BattleFieldUI()
{
    delete this->ui;
    this->perksUi->~PerksUI();
    this->achvmentsUi->~AchvmentsUI();
    this->settingsUi->~SettingsUI();
    delete this->perksUi;
    delete this->achvmentsUi;
    delete this->settingsUi;
    delete this->achievements;
    delete this->army;
    delete this->enemy;
    delete this->stats;
    delete this->heropowers;
    delete this->armyAttackTimer;
    delete this->statsUIUpdateTimer;
}

void BattleFieldUI::armyAttack()
{
    // Do a damage.
    bool isKilled = this->enemy->doDamage(this->army->getArmyDamage());
    // Check if monster was killed.
    if(isKilled)
    {
        this->enemy->goToNextDragon(this->stats);
    }
}

void BattleFieldUI::on_monster_btn_clicked()
{
    // Do a damage. Possible, that it will be a critical damage.
    bool isKilled = this->enemy->doCriticalDamage(this->stats->CriticalHitMultiplier, this->stats->CurrentTapDamage);
    // Check if monster was killed.
    if (isKilled)
    {
        this->enemy->goToNextDragon(this->stats);
    }
}

void BattleFieldUI::uiUpdate()
{
    // Update info in labels, according to general stats.
    this->ui->monsterHP_lbl->setText(QString("Monster HP: %1/%2").arg(this->enemy->CurrentHP).arg(this->enemy->TotalHP));
    this->ui->armyDmg_lbl->setText(QString("Army damage: %1").arg(this->stats->CurrentArmyDamage));
    this->ui->criticalChance_lbl->setText(QString("Critical chance: %1%").arg(this->stats->CurrentCriticalChance * 100));
    this->ui->dmndState_lbl->setText(QString("Diamonds: %1").arg(this->stats->CurrentDiamonds));
    this->ui->goldState_lbl->setText(QString("Gold: %1").arg(this->stats->CurrentGold));
    this->ui->tapDmg_lbl->setText(QString("Tap damage: %1").arg(this->stats->CurrentTapDamage));
    this->ui->currentLevel_lbl->setText(QString("Level: %1/%2").arg(this->stats->CurrentLevel).arg(300));

    // Update Achievements class fields - check if achievements were unlocked.
    this->achievements->checkAchievements(this->stats);
    // Update total time played in GlobalState class.
    this->stats->TotalPlayTime = this->stats->TotalPlayTime.addMSecs(100);
    this->stats->checkDayPassed();
}

void BattleFieldUI::buySoldier()
{
    QPushButton *senderObj = (QPushButton *)QObject::sender();
    int index = 0;
    // Find certain index.
    for (int i = 0; i < SOLDIERS_AMOUNT; i++)
    {
        if (!QString::compare(senderObj->text(), this->army->army[i].Name))
        {
            index = i;
            break;
        }
    }
    // Check if player has enough gold to hire specific soldier.
    if (this->stats->CurrentGold >= this->army->army[index].Price)
    {
        // Manipulation with soldiers amount.
        this->army->soldiersAmount[index]++;
        this->stats->ArmyAmount++;
        this->stats->CurrentArmyDamage += this->army->army[index].DPS;
        // Payment for the hire.
        this->stats->CurrentGold -= this->army->army[index].Price;
    }
}

void BattleFieldUI::closeEvent(QCloseEvent *e)
{
    QMessageBox::StandardButton resBtn = QMessageBox::question(this, "Quit program?", tr("Do you want to save your progreses?\n"),
                                                               QMessageBox::Cancel | QMessageBox::Yes, QMessageBox::Yes);
    if(resBtn != QMessageBox::Yes)
    {
        e->ignore();
    }
    else
    {
        e->accept();
    }
}

void BattleFieldUI::on_settings_btn_clicked()
{
    // Open a window, if it is not opened yet.
    if (!this->settingsUi->isVisible())
    {
        this->settingsUi->show();
    }
    // If window is already open - change focus.
    this->settingsUi->activateWindow();
}

void BattleFieldUI::on_perks_btn_clicked()
{
    // Open a window, if it is not opened yet.
    if (!this->perksUi->isVisible())
    {
        this->perksUi->show();
    }
    // If window is already open - change focus.
    this->perksUi->activateWindow();
}

void BattleFieldUI::on_achvments_btn_clicked()
{
    // Open a window, if it is not opened yet.
    if (!this->achvmentsUi->isVisible())
    {
        this->achvmentsUi->show();
    }
    // If window is already open - change focus.
    this->achvmentsUi->activateWindow();
}

void BattleFieldUI::on_tapDmg_btn_clicked()
{
    emit this->heropowers->on_tapDmg_btn_clicked();
}

void BattleFieldUI::on_anduinMagic_btn_clicked()
{
    emit this->heropowers->on_anduinMagic_btn_clicked();
}

void BattleFieldUI::on_sylvanasCritical_btn_clicked()
{
    emit this->heropowers->on_sylvanasCritical_btn_clicked();
}

void BattleFieldUI::on_guldanRampage_btn_clicked()
{
    emit this->heropowers->on_guldanRampage_btn_clicked();
}

void BattleFieldUI::on_artasUnity_btn_clicked()
{
    emit this->heropowers->on_artasUnity_btn_clicked();
}
