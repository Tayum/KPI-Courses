#pragma once

#include <QDialog>
#include <QTimer>

#include "generalstate.h"

namespace Ui {
class GlobalStatsMenu;
}

class GlobalStatsMenu : public QDialog
{
    Q_OBJECT

public:
    explicit GlobalStatsMenu(GeneralState *in_generalState, QWidget *parent = 0);
    ~GlobalStatsMenu();

private slots:
    // Function to update text in and labels.
    void updateUI();

private:
    // UI object.
    Ui::GlobalStatsMenu *ui;

    // GeneralState class object to reach the global state.
    GeneralState *gnrlState;

    // Timer to update every 100ms global status menu.
    QTimer *updateTimer;
};
