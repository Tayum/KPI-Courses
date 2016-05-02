#ifndef HIREARMY_H
#define HIREARMY_H

#include <QDialog>
#include "army.h"
#include "generalstate.h"

namespace Ui {
class HireArmy;
}

class HireArmy : public QDialog
{
    Q_OBJECT

public:
    explicit HireArmy(Army *army, GeneralState *generalState, QWidget *parent = 0);
    ~HireArmy();

    Army *army_hireArmy;
    GeneralState *generalState_hireArmy;

private slots:
    void on_soldier_btn_1_clicked();
    void on_soldier_btn_2_clicked();
    void on_soldier_btn_3_clicked();
    void on_soldier_btn_4_clicked();
    void on_soldier_btn_5_clicked();
    void on_soldier_btn_6_clicked();
    void on_soldier_btn_7_clicked();
    void on_soldier_btn_8_clicked();
    void on_soldier_btn_9_clicked();
    void on_soldier_btn_10_clicked();
    void on_soldier_btn_11_clicked();
    void on_soldier_btn_12_clicked();
    void on_soldier_btn_13_clicked();
    void on_soldier_btn_14_clicked();
    void on_soldier_btn_15_clicked();
    void on_soldier_2_btn_1_clicked();
    void on_soldier_2_btn_2_clicked();
    void on_soldier_2_btn_3_clicked();
    void on_soldier_2_btn_4_clicked();
    void on_soldier_2_btn_5_clicked();
    void on_soldier_2_btn_6_clicked();
    void on_soldier_2_btn_7_clicked();
    void on_soldier_2_btn_8_clicked();
    void on_soldier_2_btn_9_clicked();
    void on_soldier_2_btn_10_clicked();
    void on_soldier_2_btn_11_clicked();
    void on_soldier_2_btn_12_clicked();
    void on_soldier_2_btn_13_clicked();
    void on_soldier_2_btn_14_clicked();
    void on_soldier_2_btn_15_clicked();

private:
    Ui::HireArmy *ui;
};

#endif // HIREARMY_H
