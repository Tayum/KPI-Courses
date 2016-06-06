#include "enemy.h"
#include "stats.h"

#define CRITICAL_MULTIPLIER 5

Enemy::Enemy(int CurrentLevel)
{
    this->TotalHP = CurrentLevel;
    this->CurrentHP = this->TotalHP;
    this->GoldDropped = this->TotalHP + 50;
    this->DiamondsDropped = this->TotalHP + 1;
}

void Enemy::goToNextDragon(Stats *stats)
{
    // Update current and global state fields.
    stats->CurrentGold += GoldDropped;
    stats->CurrentDiamonds += DiamondsDropped;
    stats->TotalGoldCollected += GoldDropped;
    stats->TotalDiamondsCollected += DiamondsDropped;
    stats->TotalMonsterKills++;
    stats->CurrentLevel++;
    // Generate new dragon.
    int step = TotalHP;
    TotalHP = step + 1;
    CurrentHP = step;
    GoldDropped = step + 1;
    DiamondsDropped = step + 1;
}

bool Enemy::doDamage(int inDamage)
{
    this->CurrentHP -= inDamage;
    return (this->CurrentHP <= 0);
}

bool Enemy::doCriticalDamage(double critChance, int tapDamage)
{
    int randomNum = qrand() % 100;
    if(randomNum <= critChance * 100)
        this->CurrentHP -= tapDamage * (CRITICAL_MULTIPLIER - 1);
    this->CurrentHP -= tapDamage;
    return (this->CurrentHP <= 0);
}