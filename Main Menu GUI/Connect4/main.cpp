#include <QApplication>
#include <QMainWindow>
#include <QFile>
#include <QString>
#include <QDebug>
#include <QTextStream>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
