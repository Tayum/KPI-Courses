#include <QDesktopWidget>

#include <QTimer>
#include <Qt>
#include <QMessageBox>
#include <QCloseEvent>
#include <QDebug>

// ORGANIZE THIS SHIT PLS
#include "battlefield.h"
#include "ui_battlefield.h"
#include "hirearmy.h"
#include "generalstate.h"
#include "perks.h"
#include "achievementsmenu.h"
#include "heropowersmenu.h"
#include "settingsmenu.h"
// ORGANIZE THIS SHIT PLS

#define MAX_LEVELS 300

BattleField::BattleField(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BattleField),
    achievements(new Achievements),
    generalState(new GeneralState),
    army(new Army)
{
    // Initialize current dragon class entity.
    this->currentDragonEnemy = new DragonEnemy(this->generalState->CurrentLevel);
    this->hireArmy = new HireArmy(this->army, this->generalState, this);
    this->heropwrsWindow = new HeroPowersMenu(this->generalState, this);
    this->achivmntsWindow = new AchievementsMenu(this->achievements, this);
    this->settingsWindow = new SettingsMenu(this->generalState, this);
    this->perksWindow = new Perks(this->generalState, this->currentDragonEnemy, this->heropwrsWindow, this);

    // Initialize UI.
    this->ui->setupUi(this);

    //
    this->ui->monsterButton->setDefault(true);

    // Disable resizing a BattleField window.
    this->setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);
    // Disable 'maximize' and 'hide' button in a BattleField window.
    setWindowFlags(Qt::WindowMaximizeButtonHint | Qt::WindowCloseButtonHint);

    // Move BattleField window to the center of screen.
    this->move((QApplication::desktop()->width() - this->size().width()) / 2,
               (QApplication::desktop()->height() - this->size().height()) / 2 - 50);

    // Initialize timer for army attack.
    // 1 second == 1 attack.
    timerArmyAttack = new QTimer(this);
    connect(timerArmyAttack, SIGNAL(timeout()), this, SLOT(army_attack()));
    timerArmyAttack->start(1000);
    // Initialize timer for such updates:
    // 1. GUI.
    // 2. Achievements status.
    // 3. Update total played time.
    // Updates each 100 ms.
    timerUpdate = new QTimer(this);
    connect(timerUpdate, SIGNAL(timeout()), this, SLOT(update()));
    timerUpdate->start(100);

    //
    this->setAttribute(Qt::WA_QuitOnClose);
}

void BattleField::on_monsterButton_clicked()
{
    // Do a damage.
    int randomNumForCritical = qrand() % 100;
    if(randomNumForCritical <= this->generalState->CurrentCriticalChance * 100)
        this->currentDragonEnemy->CurrentHP -= this->generalState->CurrentTapDamage * 4;
    this->currentDragonEnemy->CurrentHP -= this->generalState->CurrentTapDamage;
    // Check if monster was killed.
    if(this->currentDragonEnemy->CurrentHP <= 0)
    {
        // Update current and global state fields.
        this->generalState->CurrentGold += this->currentDragonEnemy->GoldDropped;
        this->generalState->CurrentDiamonds += this->currentDragonEnemy->DiamondsDropped;
        this->generalState->TotalGoldCollected += this->currentDragonEnemy->GoldDropped;
        this->generalState->TotalDiamondsCollected += this->currentDragonEnemy->DiamondsDropped;
        this->generalState->TotalMonsterKills++;
        // Summon a new dragon.
        this->generalState->CurrentLevel++;
        this->currentDragonEnemy->goToNextDragon(this->currentDragonEnemy);
    }
    // Add changes to global state.
    this->generalState->TotalTapsMade++;
}

void BattleField::on_armyhireButton_clicked()
{
    // Open a window, if it is not opened yet.
    if(!this->hireArmy->isVisible()) {
        this->hireArmy->show();
    }
    // If window is already open - change focus.
    this->hireArmy->activateWindow();
}

void BattleField::on_heropowersButton_clicked()
{
    if(!this->heropwrsWindow->isVisible()) {
        this->heropwrsWindow->show();
    }
    this->heropwrsWindow->activateWindow();
}

void BattleField::on_perksButton_clicked()
{
    // Open a window, if it is not opened yet.
    if(!this->perksWindow->isVisible()) {
        this->perksWindow->show();
    }
    // If window is already open - change focus.
    this->perksWindow->activateWindow();
}

void BattleField::on_achvmntsButton_clicked()
{
    if(!this->achivmntsWindow->isVisible()) {
        this->achivmntsWindow->show();
    }
    this->achivmntsWindow->activateWindow();
}

void BattleField::on_settingsButton_clicked()
{
    if(!this->settingsWindow->isVisible()) {
        this->settingsWindow->show();
    }
    this->settingsWindow->activateWindow();
}

void BattleField::army_attack()
{
    // Do a damage.
    this->currentDragonEnemy->CurrentHP -= this->army->getArmyDamage();
    // Check if monster was killed.
    if(this->currentDragonEnemy->CurrentHP <= 0)
    {
        // Update current and global state fields.
        this->generalState->CurrentGold += this->currentDragonEnemy->GoldDropped;
        this->generalState->CurrentDiamonds += this->currentDragonEnemy->DiamondsDropped;
        this->generalState->TotalGoldCollected += this->currentDragonEnemy->GoldDropped;
        this->generalState->TotalDiamondsCollected += this->currentDragonEnemy->DiamondsDropped;
        this->generalState->TotalMonsterKills++;
        // Summon a new dragon.
        this->generalState->CurrentLevel++;
        this->currentDragonEnemy->goToNextDragon(this->currentDragonEnemy);
    }
}

void BattleField::update()
{
    // Update GUI elements.
    // Updates info in labels, according to GeneralState class.
    this->ui->monsterHPLabel->setText(QString("Monster HP: %1/%2").arg(this->currentDragonEnemy->HP).arg(this->currentDragonEnemy->CurrentHP));
    this->ui->armydamageLabel->setText(QString("Army damage: %1").arg(this->generalState->CurrentArmyDamage));
    this->ui->criticalchanceLabel->setText(QString("Critical chance: %1%").arg(this->generalState->CurrentCriticalChance * 100));
    this->ui->diamondsstateLabel->setText(QString("Diamonds: %1").arg(this->generalState->CurrentDiamonds));
    this->ui->goldstateLabel->setText(QString("Gold: %1").arg(this->generalState->CurrentGold));
    this->ui->tapdamageLabel->setText(QString("Tap damage: %1").arg(this->generalState->CurrentTapDamage));
    this->ui->currentlevelLabel->setText(QString("Level: %1/%2").arg(this->generalState->CurrentLevel).arg(MAX_LEVELS));
    // Update Achievements class fields - check if achievements were unlocked.
    this->achievements->checkAchievements(this->generalState);
    // Update total time played in GlobalState class.
    this->generalState->TotalPlayTime = this->generalState->TotalPlayTime.addMSecs(100);
    qDebug() << this->generalState->TotalPlayTime.toString("HH:mm:ss") << " " << this->i;
    if(this->generalState->TotalPlayTime.hour() == 0
            && this->generalState->TotalPlayTime.minute() == 0
            && this->generalState->TotalPlayTime.second() == 0
            && this->generalState->TotalPlayTime.msec() == 0) {
        this->generalState->TotalDaysPlayed++;
    }
}

void BattleField::closeEvent(QCloseEvent *e)
{
    QMessageBox::StandardButton resBtn = QMessageBox::question( this, "Quit program?", tr("Do you want to save your progreses?\n"), QMessageBox::Cancel | QMessageBox::Yes, QMessageBox::Yes);
    if(resBtn != QMessageBox::Yes) {
        e->ignore();
    }
    else {
        e->accept();
    }
}


