#pragma once

#include "generalstate.h"

#define N_GOLD 1000
#define N_DIAMONDS 1000
#define N_MONSTERS_KILLED 100
#define N_LEVELS_COMPLETED 100
#define N_ARTIFACTS_OWNED 50
#define N_SOLDIERS_HIRED 1000
#define N_TIMES_TAPPED 1000
#define N_HEROPOWERS_USED 10
#define N_CRITICAL 0.25

class Achievements
{
public:
    Achievements();

    bool Ach_EarnNGold;
    bool Ach_EarnNDiamonds;
    bool Ach_KillNMonsters;
    bool Ach_ReachNStage;
    bool Ach_OwnNArtifacts;
    bool Ach_HireNSoldiers;
    bool Ach_TapNTimes;
    bool Ach_HeropowNTimes;
    bool Ach_DoNCritical;

    //TODO: these two achievements.
    bool Ach_Hidden_MLG;
    bool Ach_Hidden_TenEach;

    void checkAchievements(GeneralState *generalState);
};
