#include "QtHexGame.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QtHexGame window;
    window.show();
    return app.exec();
}
