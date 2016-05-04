#include "hirearmy.h"
#include "ui_hirearmy.h"

HireArmy::HireArmy(Army *army, GeneralState *generalState, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HireArmy)
{
    ui->setupUi(this);
    this->army_hireArmy = army;
    this->generalState_hireArmy = generalState;
}

HireArmy::~HireArmy()
{
    delete ui;
}

//TODO CLEAR THIS SHITTY COPYPASTA WITH 1 FUNCTION
void HireArmy::on_soldier_btn_1_clicked()
{
    if(this->generalState_hireArmy->CurrentGold >= this->army_hireArmy->army[0].price) {
        this->army_hireArmy->soldiersAmount[0]++;
        this->generalState_hireArmy->ArmyAmount++;
        this->generalState_hireArmy->CurrentArmyDamage += this->army_hireArmy->army[0].DPS;
    }
    // TODO: else - execute messagebox, or something else.
}

void HireArmy::on_soldier_btn_2_clicked()
{
    if(this->generalState_hireArmy->CurrentGold >= this->army_hireArmy->army[1].price) {
        this->army_hireArmy->soldiersAmount[1]++;
        this->generalState_hireArmy->ArmyAmount++;
        this->generalState_hireArmy->CurrentArmyDamage += this->army_hireArmy->army[1].DPS;
    }
}

void HireArmy::on_soldier_btn_3_clicked()
{
    if(this->generalState_hireArmy->CurrentGold >= this->army_hireArmy->army[2].price) {
        this->army_hireArmy->soldiersAmount[2]++;
        this->generalState_hireArmy->ArmyAmount++;
        this->generalState_hireArmy->CurrentArmyDamage += this->army_hireArmy->army[2].DPS;
    }
}

void HireArmy::on_soldier_btn_4_clicked()
{
    if(this->generalState_hireArmy->CurrentGold >= this->army_hireArmy->army[3].price) {
        this->army_hireArmy->soldiersAmount[3]++;
        this->generalState_hireArmy->ArmyAmount++;
        this->generalState_hireArmy->CurrentArmyDamage += this->army_hireArmy->army[3].DPS;
    }
}

void HireArmy::on_soldier_btn_5_clicked()
{
    if(this->generalState_hireArmy->CurrentGold >= this->army_hireArmy->army[4].price) {
        this->army_hireArmy->soldiersAmount[4]++;
        this->generalState_hireArmy->ArmyAmount++;
        this->generalState_hireArmy->CurrentArmyDamage += this->army_hireArmy->army[4].DPS;
    }
}

void HireArmy::on_soldier_btn_6_clicked()
{
    if(this->generalState_hireArmy->CurrentGold >= this->army_hireArmy->army[5].price) {
        this->army_hireArmy->soldiersAmount[5]++;
        this->generalState_hireArmy->ArmyAmount++;
        this->generalState_hireArmy->CurrentArmyDamage += this->army_hireArmy->army[5].DPS;
    }
}

void HireArmy::on_soldier_btn_7_clicked()
{
    if(this->generalState_hireArmy->CurrentGold >= this->army_hireArmy->army[6].price) {
        this->army_hireArmy->soldiersAmount[6]++;
        this->generalState_hireArmy->ArmyAmount++;
        this->generalState_hireArmy->CurrentArmyDamage += this->army_hireArmy->army[6].DPS;
    }
}

void HireArmy::on_soldier_btn_8_clicked()
{
    if(this->generalState_hireArmy->CurrentGold >= this->army_hireArmy->army[7].price) {
        this->army_hireArmy->soldiersAmount[7]++;
        this->generalState_hireArmy->ArmyAmount++;
        this->generalState_hireArmy->CurrentArmyDamage += this->army_hireArmy->army[7].DPS;
    }
}

void HireArmy::on_soldier_btn_9_clicked()
{
    if(this->generalState_hireArmy->CurrentGold >= this->army_hireArmy->army[8].price) {
        this->army_hireArmy->soldiersAmount[8]++;
        this->generalState_hireArmy->ArmyAmount++;
        this->generalState_hireArmy->CurrentArmyDamage += this->army_hireArmy->army[8].DPS;
    }
}

void HireArmy::on_soldier_btn_10_clicked()
{
    if(this->generalState_hireArmy->CurrentGold >= this->army_hireArmy->army[9].price) {
        this->army_hireArmy->soldiersAmount[9]++;
        this->generalState_hireArmy->ArmyAmount++;
        this->generalState_hireArmy->CurrentArmyDamage += this->army_hireArmy->army[9].DPS;
    }
}

void HireArmy::on_soldier_btn_11_clicked()
{
    if(this->generalState_hireArmy->CurrentGold >= this->army_hireArmy->army[10].price) {
        this->army_hireArmy->soldiersAmount[10]++;
        this->generalState_hireArmy->ArmyAmount++;
        this->generalState_hireArmy->CurrentArmyDamage += this->army_hireArmy->army[10].DPS;
    }
}

void HireArmy::on_soldier_btn_12_clicked()
{
    if(this->generalState_hireArmy->CurrentGold >= this->army_hireArmy->army[11].price) {
        this->army_hireArmy->soldiersAmount[11]++;
        this->generalState_hireArmy->ArmyAmount++;
        this->generalState_hireArmy->CurrentArmyDamage += this->army_hireArmy->army[11].DPS;
    }
}

void HireArmy::on_soldier_btn_13_clicked()
{
    if(this->generalState_hireArmy->CurrentGold >= this->army_hireArmy->army[12].price) {
        this->army_hireArmy->soldiersAmount[12]++;
        this->generalState_hireArmy->ArmyAmount++;
        this->generalState_hireArmy->CurrentArmyDamage += this->army_hireArmy->army[12].DPS;
    }

}

void HireArmy::on_soldier_btn_14_clicked()
{
    if(this->generalState_hireArmy->CurrentGold >= this->army_hireArmy->army[13].price) {
        this->army_hireArmy->soldiersAmount[13]++;
        this->generalState_hireArmy->ArmyAmount++;
        this->generalState_hireArmy->CurrentArmyDamage += this->army_hireArmy->army[13].DPS;
    }
}

void HireArmy::on_soldier_btn_15_clicked()
{
    if(this->generalState_hireArmy->CurrentGold >= this->army_hireArmy->army[14].price) {
        this->army_hireArmy->soldiersAmount[14]++;
        this->generalState_hireArmy->ArmyAmount++;
        this->generalState_hireArmy->CurrentArmyDamage += this->army_hireArmy->army[14].DPS;
    }
}

void HireArmy::on_soldier_2_btn_1_clicked()
{
    if(this->generalState_hireArmy->CurrentGold >= this->army_hireArmy->army[15].price) {
        this->army_hireArmy->soldiersAmount[15]++;
        this->generalState_hireArmy->ArmyAmount++;
        this->generalState_hireArmy->CurrentArmyDamage += this->army_hireArmy->army[15].DPS;
    }
}

void HireArmy::on_soldier_2_btn_2_clicked()
{
    if(this->generalState_hireArmy->CurrentGold >= this->army_hireArmy->army[16].price) {
        this->army_hireArmy->soldiersAmount[16]++;
        this->generalState_hireArmy->ArmyAmount++;
        this->generalState_hireArmy->CurrentArmyDamage += this->army_hireArmy->army[16].DPS;
    }
}

void HireArmy::on_soldier_2_btn_3_clicked()
{
    if(this->generalState_hireArmy->CurrentGold >= this->army_hireArmy->army[17].price) {
        this->army_hireArmy->soldiersAmount[17]++;
        this->generalState_hireArmy->ArmyAmount++;
        this->generalState_hireArmy->CurrentArmyDamage += this->army_hireArmy->army[17].DPS;
    }
}

void HireArmy::on_soldier_2_btn_4_clicked()
{
    if(this->generalState_hireArmy->CurrentGold >= this->army_hireArmy->army[18].price) {
        this->army_hireArmy->soldiersAmount[18]++;
        this->generalState_hireArmy->ArmyAmount++;
        this->generalState_hireArmy->CurrentArmyDamage += this->army_hireArmy->army[18].DPS;
    }
}

void HireArmy::on_soldier_2_btn_5_clicked()
{
    if(this->generalState_hireArmy->CurrentGold >= this->army_hireArmy->army[19].price) {
        this->army_hireArmy->soldiersAmount[19]++;
        this->generalState_hireArmy->ArmyAmount++;
        this->generalState_hireArmy->CurrentArmyDamage += this->army_hireArmy->army[19].DPS;
    }
}

void HireArmy::on_soldier_2_btn_6_clicked()
{
    if(this->generalState_hireArmy->CurrentGold >= this->army_hireArmy->army[20].price) {
        this->army_hireArmy->soldiersAmount[20]++;
        this->generalState_hireArmy->ArmyAmount++;
        this->generalState_hireArmy->CurrentArmyDamage += this->army_hireArmy->army[20].DPS;
    }
}

void HireArmy::on_soldier_2_btn_7_clicked()
{
    if(this->generalState_hireArmy->CurrentGold >= this->army_hireArmy->army[21].price) {
        this->army_hireArmy->soldiersAmount[21]++;
        this->generalState_hireArmy->ArmyAmount++;
        this->generalState_hireArmy->CurrentArmyDamage += this->army_hireArmy->army[21].DPS;
    }
}

void HireArmy::on_soldier_2_btn_8_clicked()
{
    if(this->generalState_hireArmy->CurrentGold >= this->army_hireArmy->army[22].price) {
        this->army_hireArmy->soldiersAmount[22]++;
        this->generalState_hireArmy->ArmyAmount++;
        this->generalState_hireArmy->CurrentArmyDamage += this->army_hireArmy->army[22].DPS;
    }
}

void HireArmy::on_soldier_2_btn_9_clicked()
{
    if(this->generalState_hireArmy->CurrentGold >= this->army_hireArmy->army[23].price) {
        this->army_hireArmy->soldiersAmount[23]++;
        this->generalState_hireArmy->ArmyAmount++;
        this->generalState_hireArmy->CurrentArmyDamage += this->army_hireArmy->army[23].DPS;
    }
}

void HireArmy::on_soldier_2_btn_10_clicked()
{
    if(this->generalState_hireArmy->CurrentGold >= this->army_hireArmy->army[24].price) {
        this->army_hireArmy->soldiersAmount[24]++;
        this->generalState_hireArmy->ArmyAmount++;
        this->generalState_hireArmy->CurrentArmyDamage += this->army_hireArmy->army[24].DPS;
    }
}

void HireArmy::on_soldier_2_btn_11_clicked()
{
    if(this->generalState_hireArmy->CurrentGold >= this->army_hireArmy->army[25].price) {
        this->army_hireArmy->soldiersAmount[25]++;
        this->generalState_hireArmy->ArmyAmount++;
        this->generalState_hireArmy->CurrentArmyDamage += this->army_hireArmy->army[25].DPS;
    }
}

void HireArmy::on_soldier_2_btn_12_clicked()
{
    if(this->generalState_hireArmy->CurrentGold >= this->army_hireArmy->army[26].price) {
        this->army_hireArmy->soldiersAmount[26]++;
        this->generalState_hireArmy->ArmyAmount++;
        this->generalState_hireArmy->CurrentArmyDamage += this->army_hireArmy->army[26].DPS;
    }
}

void HireArmy::on_soldier_2_btn_13_clicked()
{
    if(this->generalState_hireArmy->CurrentGold >= this->army_hireArmy->army[27].price) {
        this->army_hireArmy->soldiersAmount[27]++;
        this->generalState_hireArmy->ArmyAmount++;
        this->generalState_hireArmy->CurrentArmyDamage += this->army_hireArmy->army[27].DPS;
    }
}

void HireArmy::on_soldier_2_btn_14_clicked()
{
    if(this->generalState_hireArmy->CurrentGold >= this->army_hireArmy->army[28].price) {
        this->army_hireArmy->soldiersAmount[28]++;
        this->generalState_hireArmy->ArmyAmount++;
        this->generalState_hireArmy->CurrentArmyDamage += this->army_hireArmy->army[28].DPS;
    }
}

void HireArmy::on_soldier_2_btn_15_clicked()
{
    if(this->generalState_hireArmy->CurrentGold >= this->army_hireArmy->army[29].price) {
        this->army_hireArmy->soldiersAmount[29]++;
        this->generalState_hireArmy->ArmyAmount++;
        this->generalState_hireArmy->CurrentArmyDamage += this->army_hireArmy->army[29].DPS;
    }
}
