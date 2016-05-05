#include "dragonenemy.h"
#include "battlefield.h"

DragonEnemy::DragonEnemy(int currentLevel)
{
    this->HP = currentLevel;
    this->GoldDropped = this->HP + 1;
    this->DiamondsDropped = this->HP + 1;
    this->CurrentHP = this->HP;
}

void DragonEnemy::goToNextDragon(DragonEnemy *dragonEnemy)
{
    dragonEnemy->HP++;
    dragonEnemy->GoldDropped = dragonEnemy->HP + 1;
    dragonEnemy->DiamondsDropped = dragonEnemy->HP + 1;
    dragonEnemy->CurrentHP = dragonEnemy->HP;
}
