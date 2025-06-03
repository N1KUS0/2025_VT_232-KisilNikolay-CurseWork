#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QLocale::setDefault(QLocale(QLocale::Russian, QLocale::Russia));
    QApplication::setStyle("Fusion");

    MainWindow w;
    w.setWindowTitle("Трекер привычек v1.0");
    w.show();

    return a.exec();
}
