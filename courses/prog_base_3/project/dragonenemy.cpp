#include "dragonenemy.h"
#include "battlefield.h"

DragonEnemy::DragonEnemy(int currentLevel)
{
    // TODO: formulas for HP, gold, diamonds depending on level.
    /* Ideas for formulas:
     * 1. Rand() in range
     * 2. currLevel + someNum
     * 3. different f-as for [0,10], [10,20] and so on levels.     *
     */
    this->HP = currentLevel + 24;
    this->GoldDropped = currentLevel + 24;
    this->DiamondsDropped = currentLevel + 1;
    this->CurrentHP = this->HP;
}
