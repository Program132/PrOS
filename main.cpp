#include <iostream>
#include <QApplication>
#include "src/Essentials/MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow PrOS_Window(1000,800);

    PrOS_Window.setMinimumSize(1000,800);

    PrOS_Window.show();
    return QApplication::exec();
}