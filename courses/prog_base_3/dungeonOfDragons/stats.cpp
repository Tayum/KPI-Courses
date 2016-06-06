#include "stats.h"

Stats::Stats()
{
    // Set default values to all fields.
    // Current stats fields.
    this->CurrentLevel = 1;
    this->CurrentGold = 0;
    this->CurrentDiamonds = 0;
    this->CurrentTapDamage = 1;
    this->CurrentArmyDamage = 0;
    this->CurrentCriticalChance = 0.1;
    // General status fields.
    this->MissionsCompleted = 0;
    this->ArmyAmount = 0;
    this->ArtifactsUnlocked = 0;
    this->HeropowersUnlocked = 0;
    this->AwardsCollected = 0;
    // Multipliers.
    this->DPSMultiplier = 0.0;
    this->GoldMultiplier = 0.0;
    this->CriticalHitMultiplier = 0.0;
    // Total status fields.
    this->TotalGoldCollected = 0;
    this->TotalDiamondsCollected = 0;
    this->TotalTapsMade = 0;
    this->TotalMonsterKills = 0;
    // Played time field.
    // Tracking days is needed, because of Qtime::addMSecs specific behavior.
    this->TotalPlayTime = QTime(0,0);
    this->TotalDaysPlayed = 0;
}

void Stats::checkDayPassed()
{
    if(this->TotalPlayTime.hour() == 0
            && this->TotalPlayTime.minute() == 0
            && this->TotalPlayTime.second() == 0
            && this->TotalPlayTime.msec() == 0)
    {
        this->TotalDaysPlayed++;
    }
}