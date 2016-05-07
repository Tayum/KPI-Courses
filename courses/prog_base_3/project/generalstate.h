#pragma once

#include <QTime>

class GeneralState
{
public:
    GeneralState();

    // Current status fields.
    int CurrentLevel;
    int CurrentGold;
    int CurrentDiamonds;
    int CurrentTapDamage;
    int CurrentArmyDamage;
    double CurrentCriticalChance;

    // General status fields.
    int ArmyAmount;
    int ArtifactsUnlocked;
    int AwardsCollected;
    int HeropowersUnlocked;
    int MissionsCompleted;

    // Multipliers.
    double CriticalHitMultiplier;
    double DPSMultiplier;
    double GoldMultiplier;

    // Total status fields.
    int TotalGoldCollected;
    int TotalDiamondsCollected;
    int TotalTapsMade;
    int TotalMonsterKills;

    // Played time field.
    QTime TotalPlayTime;
    int TotalDaysPlayed;
};
