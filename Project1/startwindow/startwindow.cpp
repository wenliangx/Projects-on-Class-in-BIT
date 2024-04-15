//
// Created by 18759 on 2024/4/15.
//

// You may need to build the project (run Qt uic code generator) to get "ui_StartWindow.h" resolved

#include "startwindow.h"
#include "ui_StartWindow.h"
#include "../gobangwindow/gobangwindow.h"
#include "../settingwindow/settingwindow.h"


StartWindow::StartWindow(QWidget *parent) :
        QDialog(parent), ui(new Ui::StartWindow) {
    ui->setupUi(this);
}

StartWindow::~StartWindow() {
    delete ui;
}

void StartWindow::on_pushButtonStart_clicked() {
    GobangWindow *gobangWindow = new GobangWindow;
    this->close();
    gobangWindow->show();
}

void StartWindow::on_pushButtonStartToSetting_clicked() {
    SettingWindow* settingWindow = new SettingWindow(this);
    settingWindow->setModal(true);
    settingWindow->show();
}
