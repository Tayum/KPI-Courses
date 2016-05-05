#include "achievements.h"

Achievements::Achievements()
{
    this->Ach_EarnNGold = false;
    this->Ach_EarnNDiamonds = false;
    this->Ach_KillNMonsters = false;
    this->Ach_ReachNStage = false;
    this->Ach_OwnNArtifacts = false;
    this->Ach_HireNSoldiers = false;
    this->Ach_TapNTimes = false;
    this->Ach_HeropowNTimes = false;
    this->Ach_DoNCritical = false;
    this->Ach_Hidden_MLG = false;
    this->Ach_Hidden_TenEach = false;
}

void Achievements::checkAchievements(GeneralState *generalState)
{
    // If some achievement was unlocked, change field to true.
    if(generalState->TotalGoldCollected == N_GOLD)
        this->Ach_EarnNGold = true;
    else if(generalState->TotalDiamondsCollected == N_DIAMONDS)
        this->Ach_EarnNDiamonds = true;
    else if(generalState->TotalMonsterKills == N_MONSTERS_KILLED)
        this->Ach_KillNMonsters = true;
    else if(generalState->CurrentLevel == N_LEVELS_COMPLETED)
        this->Ach_ReachNStage = true;
    else if(generalState->ArtifactsUnlocked == N_ARTIFACTS_OWNED)
        this->Ach_OwnNArtifacts = true;
    else if(generalState->ArmyAmount == N_SOLDIERS_HIRED)
        this->Ach_HireNSoldiers = true;
    else if(generalState->TotalTapsMade == N_TIMES_TAPPED)
        this->Ach_TapNTimes = true;
    else if(generalState->HeropowersUnlocked == N_HEROPOWERS_USED)
        this->Ach_HeropowNTimes = true;
    else if(generalState->CurrentCriticalChance == N_SOLDIERS_HIRED)
        this->Ach_DoNCritical = true;
}
