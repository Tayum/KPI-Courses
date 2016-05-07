#pragma once

#include <QDialog>
#include <QTimer>

#include "achievements.h"

namespace Ui {
class AchievementsMenu;
}

class AchievementsMenu : public QDialog
{
    Q_OBJECT

public:
    explicit AchievementsMenu(Achievements *in_achievements, QWidget *parent = 0);
    ~AchievementsMenu();

private slots:
    // Slot to check if some achievement was unlocked.
    void updateUI();

private:
    // UI object.
    Ui::AchievementsMenu *ui;

    // Achievements class object to check if some achievement was unlocked.
    Achievements *achObj;

    // Timer to update Achievement Dialog to show that some achievement was achieved.
    QTimer *updateTimer;
};
