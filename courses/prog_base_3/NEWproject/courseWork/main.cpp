#include "battlefieldui.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BattleFieldUI w;
    w.show();

    return a.exec();
}
