//
// Created by 18759 on 2024/4/19.
//

// You may need to build the project (run Qt uic code generator) to get "ui_EnsureWindow.h" resolved

#include "ensurewindow.h"
#include "ui_EnsureWindow.h"


EnsureWindow::EnsureWindow(QWidget *parent) :
        QDialog(parent), ui(new Ui::EnsureWindow) {
    ui->setupUi(this);
    connect(ui->pushButtonSure,SIGNAL(clicked()),this, SLOT(PushSure()));
    connect(ui->pushButtonNotSure,SIGNAL(clicked()),this, SLOT(PushNotSure()));
}

EnsureWindow::~EnsureWindow() {
    delete ui;
}

void EnsureWindow::PushSure() {
    SendSure(true);
    this->close();
}

void EnsureWindow::PushNotSure() {
    this->close();
}
