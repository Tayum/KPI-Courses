#include "battlefield.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    BattleField battleField;
    battleField.show();

    battleField.initUiLabels();
    return app.exec();
}
