#include "mainwindow.h"
#include "cardfactory.h"
#include "register.cpp"
#include <QApplication>
#include <QDir>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QDir::setCurrent(QCoreApplication::applicationDirPath());
    MainWindow w;
    w.show();
    return a.exec();
}
