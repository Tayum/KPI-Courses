#include "generalstate.h"

GeneralState::GeneralState()
{    
    // In constructor, default fields values are set.
    // Current state fields.
    this->CurrentLevel = 1;
    this->CurrentGold = 0;
    this->CurrentDiamonds = 0;
    this->CurrentTapDamage = 1;
    this->CurrentArmyDamage = 0;
    this->CurrentCriticalChance = 0.1;

    // General state fields.
    this->MissionsCompleted = 0;
    this->ArmyAmount = 0;
    this->ArtifactsUnlocked = 0;
    this->HeropowersUnlocked = 0;
    this->AwardsCollected = 0;
    this->DPSMultiplier = 0.0;
    this->GoldMultiplier = 0.0;
    this->CriticalHitMultiplier = 0.0;
    this->TotalGoldCollected = 0;
    this->TotalDiamondsCollected = 0;
    this->TotalTapsMade = 0;
    this->TotalMonsterKills = 0;

    // Played time field.
    // Tracking days is needed, because of Qtime::addMSecs behavior.
    this->TotalPlayTime = QTime(0,0,1);
    this->TotalDaysPlayed = 0;
}
