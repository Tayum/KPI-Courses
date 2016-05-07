#ifndef GLOBALSTATSMENU_H
#define GLOBALSTATSMENU_H

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
    void updateUI();

private:
    GeneralState *gnrlState;
    QTimer *updateTimer;
    Ui::GlobalStatsMenu *ui;
};

#endif // GLOBALSTATSMENU_H
