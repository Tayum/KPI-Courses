#include <QFile>
#include <QTextStream>
#include <QString>

#include "army.h"

Army::Army()
{
    // Parse from army.csv to this->army array.
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
        this->army[i].DPS = data[2].toInt();
        i++;
    }

    // Fill soldiersAmount array with zeros.
    for (i = 0 ; i < SOLDIERS_AMOUNT; i++)
        this->soldiersAmount[i] = 0;
}

int Army::getArmyDamage()
{
    int totalDPS = 0;
    for(int i = 0; i < SOLDIERS_AMOUNT; i++)
    {
        totalDPS += this->army[i].DPS * this->soldiersAmount[i];
    }
    return (totalDPS);
}

int Army::getArmyAmount()
{
    int totalAmount = 0;
    for(int i = 0; i < SOLDIERS_AMOUNT; i++)
    {
        totalAmount += this->soldiersAmount[i];
    }
    return (totalAmount);
}
