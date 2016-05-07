#include "hirearmy.h"
#include "ui_hirearmy.h"

HireArmy::HireArmy(Army *army, GeneralState *generalState, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HireArmy)
{
    // Initialize HireArmy Dialog UI.
    this->ui->setupUi(this);
    // Update UI labels and buttons text from .csv
    this->updateUI();

    // Disable 'help' button.
    Qt::WindowFlags flags = this->windowFlags();
    flags &= ~Qt::WindowContextHelpButtonHint;
    this->setWindowFlags(flags);

    // Copy data from main GeneralState and Army classes.
    this->armyObj = army;
    this->gnrlState = generalState;
}

HireArmy::~HireArmy()
{
    delete this->ui;
}

void HireArmy::soldierButtonAction(int index)
{
    // This function changes fields in GeneralState class.
    // When some button is pressed, player pays gold and gets army passive damage.

    // Check if player has enough gold to hire specific soldier.
    if(this->gnrlState->CurrentGold >= this->armyObj->army[index - 1].price) {
        // Manipulation with soldiers amount.
        this->armyObj->soldiersAmount[index - 1]++;
        this->gnrlState->ArmyAmount++;
        this->gnrlState->CurrentArmyDamage += this->armyObj->army[index - 1].DPS;
        // Payment for the hire.
        this->gnrlState->CurrentGold -= this->armyObj->army[index - 1].price;
    }
}

void HireArmy::updateUI()
{
    // Copy data about soldier types to labels and buttons text.
    // Information is stored in Army::army array in format Soldier_s{name,price,DPS}.

    // Copy soldiers name data.
    this->ui->soldier_btn_1->setText(this->armyObj->army[0].name);
    this->ui->soldier_btn_2->setText(this->armyObj->army[1].name);
    this->ui->soldier_btn_3->setText(this->armyObj->army[2].name);
    this->ui->soldier_btn_4->setText(this->armyObj->army[3].name);
    this->ui->soldier_btn_5->setText(this->armyObj->army[4].name);
    this->ui->soldier_btn_6->setText(this->armyObj->army[5].name);
    this->ui->soldier_btn_7->setText(this->armyObj->army[6].name);
    this->ui->soldier_btn_8->setText(this->armyObj->army[7].name);
    this->ui->soldier_btn_9->setText(this->armyObj->army[8].name);
    this->ui->soldier_btn_10->setText(this->armyObj->army[9].name);
    this->ui->soldier_btn_11->setText(this->armyObj->army[10].name);
    this->ui->soldier_btn_12->setText(this->armyObj->army[11].name);
    this->ui->soldier_btn_13->setText(this->armyObj->army[12].name);
    this->ui->soldier_btn_14->setText(this->armyObj->army[13].name);
    this->ui->soldier_btn_15->setText(this->armyObj->army[14].name);
    this->ui->soldier_2_btn_1->setText(this->armyObj->army[15].name);
    this->ui->soldier_2_btn_2->setText(this->armyObj->army[16].name);
    this->ui->soldier_2_btn_3->setText(this->armyObj->army[17].name);
    this->ui->soldier_2_btn_4->setText(this->armyObj->army[18].name);
    this->ui->soldier_2_btn_5->setText(this->armyObj->army[19].name);
    this->ui->soldier_2_btn_6->setText(this->armyObj->army[20].name);
    this->ui->soldier_2_btn_7->setText(this->armyObj->army[21].name);
    this->ui->soldier_2_btn_8->setText(this->armyObj->army[22].name);
    this->ui->soldier_2_btn_9->setText(this->armyObj->army[23].name);
    this->ui->soldier_2_btn_10->setText(this->armyObj->army[24].name);
    this->ui->soldier_2_btn_11->setText(this->armyObj->army[25].name);
    this->ui->soldier_2_btn_12->setText(this->armyObj->army[26].name);
    this->ui->soldier_2_btn_13->setText(this->armyObj->army[27].name);
    this->ui->soldier_2_btn_14->setText(this->armyObj->army[28].name);
    this->ui->soldier_2_btn_15->setText(this->armyObj->army[29].name);

    // Copy soldiers DPS data.
    this->ui->soldier_dmg_lbl_1->setText(QString::number(this->armyObj->army[0].DPS));
    this->ui->soldier_dmg_lbl_2->setText(QString::number(this->armyObj->army[1].DPS));
    this->ui->soldier_dmg_lbl_3->setText(QString::number(this->armyObj->army[2].DPS));
    this->ui->soldier_dmg_lbl_4->setText(QString::number(this->armyObj->army[3].DPS));
    this->ui->soldier_dmg_lbl_5->setText(QString::number(this->armyObj->army[4].DPS));
    this->ui->soldier_dmg_lbl_6->setText(QString::number(this->armyObj->army[5].DPS));
    this->ui->soldier_dmg_lbl_7->setText(QString::number(this->armyObj->army[6].DPS));
    this->ui->soldier_dmg_lbl_8->setText(QString::number(this->armyObj->army[7].DPS));
    this->ui->soldier_dmg_lbl_9->setText(QString::number(this->armyObj->army[8].DPS));
    this->ui->soldier_dmg_lbl_10->setText(QString::number(this->armyObj->army[9].DPS));
    this->ui->soldier_dmg_lbl_11->setText(QString::number(this->armyObj->army[10].DPS));
    this->ui->soldier_dmg_lbl_12->setText(QString::number(this->armyObj->army[11].DPS));
    this->ui->soldier_dmg_lbl_13->setText(QString::number(this->armyObj->army[12].DPS));
    this->ui->soldier_dmg_lbl_14->setText(QString::number(this->armyObj->army[13].DPS));
    this->ui->soldier_dmg_lbl_15->setText(QString::number(this->armyObj->army[14].DPS));
    this->ui->soldier_2_dmg_lbl_1->setText(QString::number(this->armyObj->army[15].DPS));
    this->ui->soldier_2_dmg_lbl_2->setText(QString::number(this->armyObj->army[16].DPS));
    this->ui->soldier_2_dmg_lbl_3->setText(QString::number(this->armyObj->army[17].DPS));
    this->ui->soldier_2_dmg_lbl_4->setText(QString::number(this->armyObj->army[18].DPS));
    this->ui->soldier_2_dmg_lbl_5->setText(QString::number(this->armyObj->army[19].DPS));
    this->ui->soldier_2_dmg_lbl_6->setText(QString::number(this->armyObj->army[20].DPS));
    this->ui->soldier_2_dmg_lbl_7->setText(QString::number(this->armyObj->army[21].DPS));
    this->ui->soldier_2_dmg_lbl_8->setText(QString::number(this->armyObj->army[22].DPS));
    this->ui->soldier_2_dmg_lbl_9->setText(QString::number(this->armyObj->army[23].DPS));
    this->ui->soldier_2_dmg_lbl_10->setText(QString::number(this->armyObj->army[24].DPS));
    this->ui->soldier_2_dmg_lbl_11->setText(QString::number(this->armyObj->army[25].DPS));
    this->ui->soldier_2_dmg_lbl_12->setText(QString::number(this->armyObj->army[26].DPS));
    this->ui->soldier_2_dmg_lbl_13->setText(QString::number(this->armyObj->army[27].DPS));
    this->ui->soldier_2_dmg_lbl_14->setText(QString::number(this->armyObj->army[28].DPS));
    this->ui->soldier_2_dmg_lbl_15->setText(QString::number(this->armyObj->army[29].DPS));

    // Copy soldiers price data.
    this->ui->soldier_price_lbl_1->setText(QString::number(this->armyObj->army[0].price));
    this->ui->soldier_price_lbl_2->setText(QString::number(this->armyObj->army[1].price));
    this->ui->soldier_price_lbl_3->setText(QString::number(this->armyObj->army[2].price));
    this->ui->soldier_price_lbl_4->setText(QString::number(this->armyObj->army[3].price));
    this->ui->soldier_price_lbl_5->setText(QString::number(this->armyObj->army[4].price));
    this->ui->soldier_price_lbl_6->setText(QString::number(this->armyObj->army[5].price));
    this->ui->soldier_price_lbl_7->setText(QString::number(this->armyObj->army[6].price));
    this->ui->soldier_price_lbl_8->setText(QString::number(this->armyObj->army[7].price));
    this->ui->soldier_price_lbl_9->setText(QString::number(this->armyObj->army[8].price));
    this->ui->soldier_price_lbl_10->setText(QString::number(this->armyObj->army[9].price));
    this->ui->soldier_price_lbl_11->setText(QString::number(this->armyObj->army[10].price));
    this->ui->soldier_price_lbl_12->setText(QString::number(this->armyObj->army[11].price));
    this->ui->soldier_price_lbl_13->setText(QString::number(this->armyObj->army[12].price));
    this->ui->soldier_price_lbl_14->setText(QString::number(this->armyObj->army[13].price));
    this->ui->soldier_price_lbl_15->setText(QString::number(this->armyObj->army[14].price));
    this->ui->soldier_2_price_lbl_1->setText(QString::number(this->armyObj->army[15].price));
    this->ui->soldier_2_price_lbl_2->setText(QString::number(this->armyObj->army[16].price));
    this->ui->soldier_2_price_lbl_3->setText(QString::number(this->armyObj->army[17].price));
    this->ui->soldier_2_price_lbl_4->setText(QString::number(this->armyObj->army[18].price));
    this->ui->soldier_2_price_lbl_5->setText(QString::number(this->armyObj->army[19].price));
    this->ui->soldier_2_price_lbl_6->setText(QString::number(this->armyObj->army[20].price));
    this->ui->soldier_2_price_lbl_7->setText(QString::number(this->armyObj->army[21].price));
    this->ui->soldier_2_price_lbl_8->setText(QString::number(this->armyObj->army[22].price));
    this->ui->soldier_2_price_lbl_9->setText(QString::number(this->armyObj->army[23].price));
    this->ui->soldier_2_price_lbl_10->setText(QString::number(this->armyObj->army[24].price));
    this->ui->soldier_2_price_lbl_11->setText(QString::number(this->armyObj->army[25].price));
    this->ui->soldier_2_price_lbl_12->setText(QString::number(this->armyObj->army[26].price));
    this->ui->soldier_2_price_lbl_13->setText(QString::number(this->armyObj->army[27].price));
    this->ui->soldier_2_price_lbl_14->setText(QString::number(this->armyObj->army[28].price));
    this->ui->soldier_2_price_lbl_15->setText(QString::number(this->armyObj->army[29].price));
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
