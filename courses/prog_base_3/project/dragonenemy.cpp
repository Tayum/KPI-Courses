#include "dragonenemy.h"
#include "battlefield.h"

DragonEnemy::DragonEnemy(int currentLevel)
{
    // Fill default dragon characteristics with default values.
    this->HP = currentLevel;
    this->GoldDropped = this->HP + 50;
    this->DiamondsDropped = this->HP + 1;
    this->CurrentHP = this->HP;
}

void DragonEnemy::goToNextDragon(DragonEnemy *dragonEnemy)
{
    // Having formula, go to the next dragon.
    // All fields have their own formula and with changes in the
    // level all changes in dragon characteristics should be done.
    dragonEnemy->HP++;
    dragonEnemy->GoldDropped = dragonEnemy->HP + 1;
    dragonEnemy->DiamondsDropped = dragonEnemy->HP + 1;
    dragonEnemy->CurrentHP = dragonEnemy->HP;
}
