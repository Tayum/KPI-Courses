#pragma once

class DragonEnemy
{
public:
    DragonEnemy(int currentLevel);

    // Dragon objects characteristics.
    int HP;
    int CurrentHP;
    int GoldDropped;
    int DiamondsDropped;

    // Function to go to next dragon by certain formula.
    // This function is needed in order to jump to the next dragon,
    // when current level is completed without creating another DragonEnemy object.
    void goToNextDragon(DragonEnemy *dragonEnemy);
};
