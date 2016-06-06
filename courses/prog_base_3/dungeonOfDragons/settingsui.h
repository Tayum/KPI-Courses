#pragma once

#include <QDialog>
#include <QTimer>

#include "stats.h"

namespace Ui {
class SettingsUI;
}

class SettingsUI : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsUI(Stats *stats, QWidget *parent = 0);
    ~SettingsUI();

private slots:
    void updateUI();

private:
    Ui::SettingsUI *ui;
    QTimer *updateUITimer;
    Stats *stats;

};
