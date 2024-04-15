//
// Created by 18759 on 2024/4/15.
//

// You may need to build the project (run Qt uic code generator) to get "ui_GobangWindow.h" resolved

#include "gobangwindow.h"
#include "ui_GobangWindow.h"
#include "../startwindow/startwindow.h"
#include "../settingwindow/settingwindow.h"

GobangWindow::GobangWindow(QWidget *parent) :
        QDialog(parent), ui(new Ui::GobangWindow) {
    ui->setupUi(this);
    x = new int[NUM];
    y = new int[NUM];
    for(int i = 0; i<NUM;++i){
        if(i){
            x[i] = x[i-1] + DISTANCE;
            y[i] = y[i-1] + DISTANCE;
        }else{
            x[i] = X_START;
            y[i] = y_START;
        }
    }
}

GobangWindow::~GobangWindow() {
    delete ui;
}

void GobangWindow::on_pushButtonBack_clicked() {
    StartWindow* startWindow = new StartWindow;
    this->close();
    startWindow->show();
}

void GobangWindow::on_pushButtonGobangToSetting_clicked() {
    SettingWindow* settingWindow = new SettingWindow(this);
    settingWindow->setModal(true);
    settingWindow->show();
}

void GobangWindow::paintEvent(QPaintEvent *) {
    QPainter main_painter(this);
    QPen main_pen;
    main_pen.setColor(Qt::black);
    main_pen.setWidth(2);
    main_pen.setStyle(Qt::SolidLine);
    main_painter.setPen(main_pen);
    for(int i = 0; i < NUM; ++i){
        auto a = x[i];
        auto b = y[0];
        auto c = x[i];
        auto d = y[NUM-1];
        main_painter.drawLine(a, b, c, d);
        a = x[0];
        b = y[i];
        c = x[NUM-1];
        d = y[i];
        main_painter.drawLine(a, b, c, d);
    }
}
