#pragma once

#include "generalstate.h"

class Achievements
{
public:
    Achievements();

    // Achievement fields.
    bool Ach_EarnNGold;
    bool Ach_EarnNDiamonds;
    bool Ach_KillNMonsters;
    bool Ach_ReachNStage;
    bool Ach_OwnNArtifacts;
    bool Ach_HireNSoldiers;
    bool Ach_TapNTimes;
    bool Ach_HeropowNTimes;
    bool Ach_DoNCritical;
    bool Ach_Hidden_MLG;
    bool Ach_Hidden_TenEach;

    // Function to go through all achievements and
    // check if some of them are accomplished.
    void checkAchievements(GeneralState *generalState);
};
