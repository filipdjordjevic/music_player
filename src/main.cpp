#include <QtWidgets>

#include "widgets/MainWindow.hpp"

using namespace ui;

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    // set stylesheet
    QFile file(":/qss/style.qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    app.setStyleSheet(styleSheet);

    MainWindow mainWindow;
    mainWindow.show();

    return app.exec();
}