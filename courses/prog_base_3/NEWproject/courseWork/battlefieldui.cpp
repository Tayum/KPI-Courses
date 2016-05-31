#include "battlefieldui.h"
#include "ui_battlefieldui.h"

BattleFieldUI::BattleFieldUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BattleFieldUI)
{
    ui->setupUi(this);
}

BattleFieldUI::~BattleFieldUI()
{
    delete ui;
}
