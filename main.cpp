#include "mainwindow.h"

#include <QApplication>
#include "mainwidget.h".h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // MainWindow w;
    // w.show();
    MainWidget m;
    m.show();
    return a.exec();
}
