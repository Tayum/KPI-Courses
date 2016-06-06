#pragma once

#include "stats.h"

class Enemy
{
public:
    Enemy(int CurrentLevel);
    // Dragon characteristics.
    int CurrentHP;
    int GoldDropped;
    int DiamondsDropped;
    int TotalHP;
    // Function, that jumps to the next dragon.
    void goToNextDragon(Stats *stats);
    // Functions to deal with HP and damage.
    bool doDamage(int inDamage);
    bool doCriticalDamage(double critChance, int tapDamage);
};
