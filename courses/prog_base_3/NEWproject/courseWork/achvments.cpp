#include "achvments.h"
#include "stats.h"

#define N_GOLD 1000
#define N_DIAMONDS 1000
#define N_MONSTERS_KILLED 100
#define N_LEVELS_COMPLETED 100
#define N_ARTIFACTS_OWNED 50
#define N_SOLDIERS_HIRED 1000
#define N_TIMES_TAPPED 1000
#define N_HEROPOWERS_USED 10
#define N_CRITICAL 0.25

Achvments::Achvments()
{
    // As default, all achievements are locked.
    this->EarnNGold = false;
    this->EarnNDiamonds = false;
    this->KillNMonsters = false;
    this->ReachNStage = false;
    this->OwnNArtifacts = false;
    this->HireNSoldiers = false;
    this->TapNTimes = false;
    this->HeropowNTimes = false;
    this->DoNCritical = false;
}

void Achvments::checkAchievements(Stats *generalState)
{
    if(generalState->TotalGoldCollected >= N_GOLD)
        this->EarnNGold = true;
    if(generalState->TotalDiamondsCollected >= N_DIAMONDS)
        this->EarnNDiamonds = true;
    if(generalState->TotalMonsterKills >= N_MONSTERS_KILLED)
        this->KillNMonsters = true;
    if(generalState->CurrentLevel >= N_LEVELS_COMPLETED)
        this->ReachNStage = true;
    if(generalState->ArtifactsUnlocked >= N_ARTIFACTS_OWNED)
        this->OwnNArtifacts = true;
    if(generalState->ArmyAmount >= N_SOLDIERS_HIRED)
        this->HireNSoldiers = true;
    if(generalState->TotalTapsMade >= N_TIMES_TAPPED)
        this->TapNTimes = true;
    if(generalState->HeropowersUnlocked >= N_HEROPOWERS_USED)
        this->HeropowNTimes = true;
    if(generalState->CurrentCriticalChance >= N_CRITICAL)
        this->DoNCritical = true;
}
