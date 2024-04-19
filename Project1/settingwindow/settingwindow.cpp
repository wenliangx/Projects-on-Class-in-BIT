//
// Created by 18759 on 2024/4/15.
//

// You may need to build the project (run Qt uic code generator) to get "ui_SettingWindow.h" resolved

#include "settingwindow.h"
#include "ui_SettingWindow.h"


SettingWindow::SettingWindow(QWidget *parent) :
        QDialog(parent), ui(new Ui::SettingWindow) {
    ui->setupUi(this);
    connect(ui->pushButtonClose,SIGNAL(clicked()),this,SLOT(close()));
    ui->radioButton->setChecked(if_ensure);
}

SettingWindow::~SettingWindow() {
    delete ui;
}

void SettingWindow::closeEvent(QCloseEvent *) {
    ChangeEnsure(ui->radioButton->isChecked());
}


