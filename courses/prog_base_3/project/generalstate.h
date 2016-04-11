#ifndef GENERALSTATE_H
#define GENERALSTATE_H

#include <QTime>

class GeneralState
{
public:
    GeneralState();

    int LevelsCompleted;
    int MissionsCompleted;
    int ArmyAmount;
    int ArtifactsUnlocked;
    int HeropowersUnlocked;
    int AwardsCollected;
    double DPSMultiplier;
    double GoldMultiplier;
    double CriticalHitMultiplier;
    int GoldCollected;
    int TapsMade;
    int MonsterKills;
    QTime PlayTime;
};

#endif // GENERALSTATE_H
