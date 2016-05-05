#include "hirearmy.h"
#include "ui_hirearmy.h"

HireArmy::HireArmy(Army *army, GeneralState *generalState, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HireArmy)
{
    // Get main data from main generalState and army classes.
    this->army_hireArmy = army;
    this->generalState_hireArmy = generalState;

    // Initialize hireArmy Dialog UI.
    ui->setupUi(this);
}

HireArmy::~HireArmy()
{
    delete this->ui;
}

void HireArmy::soldierButtonAction(int index)
{
    if(this->generalState_hireArmy->CurrentGold >= this->army_hireArmy->army[index - 1].price) {
        // Manipulation with soldiers amount.
        this->army_hireArmy->soldiersAmount[index - 1]++;
        this->generalState_hireArmy->ArmyAmount++;
        this->generalState_hireArmy->CurrentArmyDamage += this->army_hireArmy->army[index - 1].DPS;
        // Manipulation with gold.
        this->generalState_hireArmy->CurrentGold -= this->army_hireArmy->army[index - 1].price;
    }
}

void HireArmy::on_soldier_btn_1_clicked()
{
    this->soldierButtonAction(1);
}

void HireArmy::on_soldier_btn_2_clicked()
{
    this->soldierButtonAction(2);
}

void HireArmy::on_soldier_btn_3_clicked()
{
    this->soldierButtonAction(3);
}

void HireArmy::on_soldier_btn_4_clicked()
{
    this->soldierButtonAction(4);
}

void HireArmy::on_soldier_btn_5_clicked()
{
    this->soldierButtonAction(5);
}

void HireArmy::on_soldier_btn_6_clicked()
{
    this->soldierButtonAction(6);
}

void HireArmy::on_soldier_btn_7_clicked()
{
    this->soldierButtonAction(7);
}

void HireArmy::on_soldier_btn_8_clicked()
{
    this->soldierButtonAction(8);
}

void HireArmy::on_soldier_btn_9_clicked()
{
    this->soldierButtonAction(9);
}

void HireArmy::on_soldier_btn_10_clicked()
{
    this->soldierButtonAction(10);
}

void HireArmy::on_soldier_btn_11_clicked()
{
    this->soldierButtonAction(11);
}

void HireArmy::on_soldier_btn_12_clicked()
{
    this->soldierButtonAction(12);
}

void HireArmy::on_soldier_btn_13_clicked()
{
    this->soldierButtonAction(13);
}

void HireArmy::on_soldier_btn_14_clicked()
{
    this->soldierButtonAction(14);
}

void HireArmy::on_soldier_btn_15_clicked()
{
    this->soldierButtonAction(15);
}

void HireArmy::on_soldier_2_btn_1_clicked()
{
    this->soldierButtonAction(16);
}

void HireArmy::on_soldier_2_btn_2_clicked()
{
    this->soldierButtonAction(17);
}

void HireArmy::on_soldier_2_btn_3_clicked()
{
    this->soldierButtonAction(18);
}

void HireArmy::on_soldier_2_btn_4_clicked()
{
    this->soldierButtonAction(19);
}

void HireArmy::on_soldier_2_btn_5_clicked()
{
    this->soldierButtonAction(20);
}

void HireArmy::on_soldier_2_btn_6_clicked()
{
    this->soldierButtonAction(21);
}

void HireArmy::on_soldier_2_btn_7_clicked()
{
    this->soldierButtonAction(22);
}

void HireArmy::on_soldier_2_btn_8_clicked()
{
    this->soldierButtonAction(23);
}

void HireArmy::on_soldier_2_btn_9_clicked()
{
    this->soldierButtonAction(24);
}

void HireArmy::on_soldier_2_btn_10_clicked()
{
    this->soldierButtonAction(25);
}

void HireArmy::on_soldier_2_btn_11_clicked()
{
    this->soldierButtonAction(26);
}

void HireArmy::on_soldier_2_btn_12_clicked()
{
    this->soldierButtonAction(27);
}

void HireArmy::on_soldier_2_btn_13_clicked()
{
    this->soldierButtonAction(28);
}

void HireArmy::on_soldier_2_btn_14_clicked()
{
    this->soldierButtonAction(29);
}

void HireArmy::on_soldier_2_btn_15_clicked()
{
    this->soldierButtonAction(30);
}
