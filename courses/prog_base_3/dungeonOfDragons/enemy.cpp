#include "enemy.h"
#include "stats.h"

Enemy::Enemy(int CurrentLevel)
{
    TotalHP = CurrentLevel;
    CurrentHP = 1;
    GoldDropped = 0;
    DiamondsDropped = 0;
}

Enemy::Enemy(int currentHP, int goldDropped, int diamondsDropped, int totalHP)
{
    this->CurrentHP = currentHP;
    this->GoldDropped = goldDropped;
    this->DiamondsDropped = diamondsDropped;
    this->TotalHP = totalHP;
}

void Enemy::goToNextDragon(Stats *stats)
{
    // Update current and global state fields.
    stats->CurrentGold += ( GoldDropped + stats->GoldMultiplier * GoldDropped );
    stats->CurrentDiamonds += ( DiamondsDropped + stats->DiamondsMultiplier * DiamondsDropped );
    stats->TotalGoldCollected += GoldDropped;
    stats->TotalDiamondsCollected += DiamondsDropped;
    stats->TotalMonsterKills++;
    stats->CurrentLevel++;
    // Generate new dragon.
    TotalHP = 5 + (int) pow(1.15, stats->CurrentLevel);
    TotalHP -= (int) TotalHP * stats->MonsterHPDecreaser;
    CurrentHP = TotalHP;
    GoldDropped = (int)TotalHP * 0.65;
    DiamondsDropped = (stats->CurrentLevel % 10 == 0) ? 1 : 0;
}

bool Enemy::doDamage(int inDamage)
{
    this->CurrentHP -= inDamage;
    return (this->CurrentHP <= 0);
}

bool Enemy::doTapDamage(Stats *stats)
{
    int randomNum = qrand() % 100;
    if(randomNum <= stats->CurrentCriticalChance * 100) {
        this->CurrentHP -= stats->CurrentTapDamage * (5 - 1);
        stats->TotalCriticalTapsMade++;
    }
    stats->TotalTapsMade++;
    this->CurrentHP -= stats->CurrentTapDamage;
    return (this->CurrentHP <= 0);
}
