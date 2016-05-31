#ifndef BATTLEFIELDUI_H
#define BATTLEFIELDUI_H

#include <QMainWindow>

namespace Ui {
class BattleFieldUI;
}

class BattleFieldUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit BattleFieldUI(QWidget *parent = 0);
    ~BattleFieldUI();

private:
    Ui::BattleFieldUI *ui;
};

#endif // BATTLEFIELDUI_H
