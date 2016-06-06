#pragma once

#include <QTime>

#define MULTIPLIER_COST 20

class Stats
{
public:
    Stats();
    // Current status fields.
    int CurrentLevel;
    int CurrentGold;
    int CurrentDiamonds;
    int CurrentTapDamage;
    int CurrentArmyDamage;
    double CurrentCriticalChance;
    // General status fields.
    int ArmyAmount;
    int ArtifactsUnlocked; // TODO
    int AwardsCollected; // TODO
    int HeropowersUnlocked; // TODO
    int MissionsCompleted; // TODO
    // Multipliers.
    double CriticalHitMultiplier;
    double GoldMultiplier;
    double DiamondsMultiplier;
    double MonsterHPDecreaser;
    double PerksCostDecreaser;
    // Total status fields.
    int TotalGoldCollected;
    int TotalDiamondsCollected;
    int TotalTapsMade;
    int TotalCriticalTapsMade;
    int TotalMonsterKills;
    // Played time field.
    QTime TotalPlayTime;
    int TotalDaysPlayed;

    void checkDayPassed();
};
