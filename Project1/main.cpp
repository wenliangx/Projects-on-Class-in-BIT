#include <QApplication>
#include <QPushButton>
#include "startwindow/startwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    StartWindow startWindow;
    startWindow.show();
    return QApplication::exec();
}
