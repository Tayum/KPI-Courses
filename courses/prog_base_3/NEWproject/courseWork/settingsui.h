#ifndef SETTINGSUI_H
#define SETTINGSUI_H

#include <QDialog>

namespace Ui {
class SettingsUI;
}

class SettingsUI : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsUI(QWidget *parent = 0);
    ~SettingsUI();

private:
    Ui::SettingsUI *ui;
};

#endif // SETTINGSUI_H
