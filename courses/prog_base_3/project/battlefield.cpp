#include <QDesktopWidget>

#include <QTimer>

#include "battlefield.h"
#include "ui_battlefield.h"
#include "hirearmy.h"

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

    // Initialize UI.
    this->ui->setupUi(this);
    this->updateUILabels();

    // Disable resizing a BattleField window.
    setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);
    // Move BattleField window to the center of screen.
    this->move((QApplication::desktop()->width() - this->size().width()) / 2,
               (QApplication::desktop()->height() - this->size().height()) / 2 - 50);

    // Initialize timer for army attack.
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(army_attack()));
    timer->start(1000);
}

void BattleField::updateUILabels()
{
    // Updates info in labels, according to GeneralState class.
    this->ui->armydamageLabel->setText(QString("Army damage: %1").arg(this->generalState->CurrentArmyDamage));
    this->ui->criticalchanceLabel->setText(QString("Critical chance: %1%").arg(this->generalState->CurrentCriticalChance * 100));
    this->ui->diamondsstateLabel->setText(QString("Diamonds: %1").arg(this->generalState->CurrentDiamonds));
    this->ui->goldstateLabel->setText(QString("Gold: %1").arg(this->generalState->CurrentGold));
    this->ui->tapdamageLabel->setText(QString("Tap damage: %1").arg(this->generalState->CurrentTapDamage));
    this->ui->currentlevelLabel->setText(QString("Level: %1/%2").arg(this->generalState->CurrentLevel).arg(MAX_LEVELS));
    this->ui->monsterHPLabel->setText(QString("Monster HP: %1/%2").arg(this->currentDragonEnemy->CurrentHP).arg(this->currentDragonEnemy->HP));
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
        this->currentDragonEnemy = new DragonEnemy(this->generalState->CurrentLevel);
    }
    // Add changes to global state.
    this->generalState->TotalTapsMade++;
    // At the end, update labels.
    this->updateUILabels();
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
        this->currentDragonEnemy = new DragonEnemy(this->generalState->CurrentLevel);
    }
    this->updateUILabels();
}


void BattleField::on_armyhireButton_clicked()
{
    if(!this->hireArmy->isVisible()) {
        this->hireArmy = new HireArmy(this->army, this->generalState, this);
        this->hireArmy->show();
    }
    this->hireArmy->activateWindow();
}
