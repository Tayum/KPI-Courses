#include <QFile>
#include <QTextStream>
#include <QString>

#include "army.h"

Army::Army()
{
    // Parse from army.csv to army types array.
    QFile file("army.csv");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);
    QString line = "";
    int i = 0;
    while((line = in.readLine()) != NULL)
    {
        QStringList data = line.split(',');
        this->army[i].name = data[0];
        this->army[i].price = data[1].toInt();
        this->army[i++].DPS = data[2].toInt();
    }
    // Fill soldiersAmount array with zeros.
    memset(this->soldiersAmount, 0, SOLDIERS_AMOUNT * sizeof(int));
}

int Army::getArmyDamage()
{
    // Count army total DPS.
    int totalDPS = 0;
    for(int i = 0; i < SOLDIERS_AMOUNT; i++)
    {
        totalDPS += this->army[i].DPS * this->soldiersAmount[i];
    }
    return (totalDPS);
}

int Army::getArmyAmount()
{
    // Count amount of soldiers in army.
    int totalAmount = 0;
    for(int i = 0; i < SOLDIERS_AMOUNT; i++)
    {
        totalAmount += this->soldiersAmount[i];
    }
    return (totalAmount);
}
