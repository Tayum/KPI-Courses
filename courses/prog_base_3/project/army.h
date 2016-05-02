#pragma once

#include <QString>

#define SOLDIERS_AMOUNT 30

class Army
{
public:
    Army();

    struct Soldier_S
    {
        QString name;
        int price;
        int DPS;
    };
    Soldier_S army[SOLDIERS_AMOUNT];
    int soldiersAmount[SOLDIERS_AMOUNT];

    int getArmyDamage();
    int getArmyAmount();
};
