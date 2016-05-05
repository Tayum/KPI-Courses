#pragma once

class DragonEnemy
{
public:
    DragonEnemy(int currentLevel);

    int HP;
    int CurrentHP;
    int GoldDropped;
    int DiamondsDropped;

    void goToNextDragon(DragonEnemy *dragonEnemy);
};
