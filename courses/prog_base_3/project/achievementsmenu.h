#pragma once

#include <QDialog>
#include <QTimer>

#include "achievements.h"
#include "generalstate.h"

namespace Ui {
class AchievementsMenu;
}

class AchievementsMenu : public QDialog
{
    Q_OBJECT

public:
    explicit AchievementsMenu(Achievements *in_achievements, QWidget *parent = 0);
    ~AchievementsMenu();

    Achievements *achObj;

private slots:
    void updateUI();

private:
    QTimer *updateTimer;
    Ui::AchievementsMenu *ui;
};
