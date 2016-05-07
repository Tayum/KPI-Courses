#include "dragonenemy.h"
#include "battlefield.h"

DragonEnemy::DragonEnemy(int currentLevel)
{
    // Fill dragon characteristics with default values.
    this->HP = currentLevel;
    this->GoldDropped = this->HP + 50;
    this->DiamondsDropped = this->HP + 1;
    this->CurrentHP = this->HP;
}

void DragonEnemy::goToNextDragon(DragonEnemy *dragonEnemy)
{
    // This function is needed in order to jump to the next dragon,
    // when current level is completed, without creating another DragonEnemy object.

    // All fields have their own formula and with changes in the
    // level all changes in dragon characteristics should be done.

    // Having formula, go to the next dragon.
    dragonEnemy->HP++;
    dragonEnemy->GoldDropped = dragonEnemy->HP + 1;
    dragonEnemy->DiamondsDropped = dragonEnemy->HP + 1;
    dragonEnemy->CurrentHP = dragonEnemy->HP;
}
