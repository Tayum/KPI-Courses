#pragma once

class DragonEnemy
{
public:
    DragonEnemy(int currentLevel);

    // Dragon characteristics.
    int CurrentHP;
    int GoldDropped;
    int DiamondsDropped;
    int HP;

    // Function that jumps to the next dragon.
    void goToNextDragon(DragonEnemy *dragonEnemy);
};
