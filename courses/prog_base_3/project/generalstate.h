#pragma once

#include <QTime>

class GeneralState
{
public:
    GeneralState();

    // Current state fields.
    int CurrentLevel;
    int CurrentGold;
    int CurrentDiamonds;
    int CurrentTapDamage;
    int CurrentArmyDamage;
    double CurrentCriticalChance;

    // General state fields.
    int MissionsCompleted;
    int ArmyAmount;
    int ArtifactsUnlocked;
    int HeropowersUnlocked;
    int AwardsCollected;
    double DPSMultiplier;
    double GoldMultiplier;
    double CriticalHitMultiplier;
    int TotalGoldCollected;
    int TotalDiamondsCollected;
    int TotalTapsMade;
    int TotalMonsterKills;

    // Played time field.
    QTime TotalPlayTime;
    int TotalDaysPlayed;
};
