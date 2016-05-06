#include "achievements.h"

#include "generalstate.h"
#include <QDebug>

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
    if(generalState->TotalGoldCollected >= N_GOLD)
        this->Ach_EarnNGold = true;
    if(generalState->TotalDiamondsCollected >= N_DIAMONDS)
        this->Ach_EarnNDiamonds = true;
    if(generalState->TotalMonsterKills >= N_MONSTERS_KILLED)
        this->Ach_KillNMonsters = true;
    if(generalState->CurrentLevel >= N_LEVELS_COMPLETED)
        this->Ach_ReachNStage = true;
    if(generalState->ArtifactsUnlocked >= N_ARTIFACTS_OWNED)
        this->Ach_OwnNArtifacts = true;
    if(generalState->ArmyAmount >= N_SOLDIERS_HIRED)
        this->Ach_HireNSoldiers = true;
    if(generalState->TotalTapsMade >= N_TIMES_TAPPED)
        this->Ach_TapNTimes = true;
    if(generalState->HeropowersUnlocked >= N_HEROPOWERS_USED)
        this->Ach_HeropowNTimes = true;
    if(generalState->CurrentCriticalChance >= N_CRITICAL)
        this->Ach_DoNCritical = true;
}
