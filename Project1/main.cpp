#include <QApplication>
#include <QPushButton>
#include <QResource>
#include "startwindow/startwindow.h"



int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QResource::registerResource(qApp->applicationDirPath() + "/resource/chessresource.rcc");
    StartWindow startWindow;
    startWindow.show();
    return QApplication::exec();
}
