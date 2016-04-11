#include "generalstate.h"

GeneralState::GeneralState()
{
    this->LevelsCompleted = 0;
    this->MissionsCompleted = 0;
    this->ArmyAmount = 0;
    this->ArtifactsUnlocked = 0;
    this->HeropowersUnlocked = 0;
    this->AwardsCollected = 0;
    this->DPSMultiplier = 0.0;
    this->GoldMultiplier = 0.0;
    this->CriticalHitMultiplier = 0.0;
    this->GoldCollected = 0;
    this->TapsMade = 0;
    this->MonsterKills = 0;
    this->PlayTime = QTime(0,0,0,0);
}
