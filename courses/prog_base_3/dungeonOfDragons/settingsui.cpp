#include "settingsui.h"
#include "ui_settingsui.h"

SettingsUI::SettingsUI(Stats *stats, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsUI)
{
    // Initialize Settings Dialog UI.
    ui->setupUi(this);

    // Disable 'help' button.
    Qt::WindowFlags flags = this->windowFlags();
    flags &= ~Qt::WindowContextHelpButtonHint;
    this->setWindowFlags(flags);

    // Set first tab as default.
    ui->settingsTabs_tabWidget->setCurrentIndex(0);

    this->stats = stats;

    this->updateUITimer = new QTimer(this);
    connect(updateUITimer, SIGNAL(timeout()), this, SLOT(updateUI()));
    this->updateUITimer->start(100);
}

SettingsUI::~SettingsUI()
{
    delete ui;
    delete this->updateUITimer;
}

void SettingsUI::updateUI()
{
    this->ui->val_lbl_1->setText(QString::number(this->stats->CurrentLevel));
    this->ui->val_lbl_2->setText(QString::number(this->stats->MissionsCompleted));
    this->ui->val_lbl_3->setText(QString::number(this->stats->ArmyAmount));
    this->ui->val_lbl_4->setText(QString::number(this->stats->ArtifactsUnlocked));
    this->ui->val_lbl_5->setText(QString::number(this->stats->HeropowersUnlocked));
    this->ui->val_lbl_6->setText(QString::number(this->stats->AwardsCollected));
    this->ui->val_lbl_7->setText(QString::number(this->stats->CurrentTapDamage));
    this->ui->val_lbl_8->setText(QString::number(this->stats->CurrentCriticalChance));
    this->ui->val_lbl_9->setText(QString::number(this->stats->CurrentArmyDamage));
    this->ui->val_lbl_10->setText(QString::number(this->stats->DPSMultiplier));
    this->ui->val_lbl_11->setText(QString::number(this->stats->CriticalHitMultiplier));
    this->ui->val_lbl_12->setText(QString::number(this->stats->GoldMultiplier));
    this->ui->val_lbl_13->setText(QString::number(this->stats->TotalGoldCollected));
    this->ui->val_lbl_14->setText(QString::number(this->stats->TotalTapsMade));
    this->ui->val_lbl_15->setText(QString::number(this->stats->TotalCriticalTapsMade));
    this->ui->val_lbl_16->setText(QString::number(this->stats->TotalMonsterKills));
    this->ui->val_lbl_17->setText(QString("%1d %2").arg(this->stats->TotalDaysPlayed).arg(this->stats->TotalPlayTime.toString("hh-mm-ss")));
    this->ui->val_lbl_18->setText(QString::number(-1));
}
