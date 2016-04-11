#include <QDesktopWidget>

#include "battlefield.h"
#include "ui_battlefield.h"

BattleField::BattleField(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BattleField),
    currentState(new CurrentState),
    generalState(new GeneralState),
    currentDragonEnemy(new DragonEnemy(this->currentState->Level))
{
    ui->setupUi(this);
    this->initUiLabels();

    // Disable resizing a BattleField window.
    setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);
    // Move BattleField window to the center of screen.
    QDesktopWidget *desktop = QApplication::desktop();
    int x, y;
    x = (desktop->width() - this->size().width()) / 2;
    y = (desktop->height() - this->size().height()) / 2;
    y -= 50;
    this->move(x,y);
}

void BattleField::initUiLabels()
{
    ui->armydamageLabel->setText(QString("Army damage: %1").arg(this->currentState->ArmyDamage));
    ui->criticalchanceLabel->setText(QString("Critical chance: %1%").arg(this->currentState->CriticalChance * 100));
    ui->diamondsstateLabel->setText(QString("Diamonds: %1").arg(this->currentState->Diamonds));
    ui->goldstateLabel->setText(QString("Gold: %1").arg(this->currentState->Gold));
    ui->tapdamageLabel->setText(QString("Tap damage: %1").arg(this->currentState->TapDamage));
    ui->currentlevelLabel->setText(QString("Level: %1/300").arg(this->currentState->Level));
    ui->monsterHPLabel->setText(QString("Monster HP: %1/%2").arg(QString::number(this->currentDragonEnemy->HP),
                                                                 QString::number(this->currentDragonEnemy->CurrentHP)));
}

void BattleField::on_monsterButton_clicked()
{
    this->currentDragonEnemy->CurrentHP -= currentState->TapDamage;
    this->generalState->TapsMade++;
    ui->monsterHPLabel->setText(QString("Monster HP: %1/%2").arg(QString::number(this->currentDragonEnemy->HP),
                                                                 QString::number(this->currentDragonEnemy->CurrentHP)));
}
