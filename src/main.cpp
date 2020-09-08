#include <QtWidgets>

#include "widgets/MainWindow.hpp"

using namespace ui;

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    MainWindow mainWindow;
    mainWindow.show();

    return app.exec();
}