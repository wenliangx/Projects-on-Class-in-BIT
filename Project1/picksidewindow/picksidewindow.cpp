//
// Created by 18759 on 2024/4/17.
//

// You may need to build the project (run Qt uic code generator) to get "ui_PickSideWindow.h" resolved

#include "picksidewindow.h"
#include "ui_PickSideWindow.h"


PickSideWindow::PickSideWindow(QWidget *parent) :
        QDialog(parent), ui(new Ui::PickSideWindow) {
    ui->setupUi(this);

    QIcon black_icon;
    QIcon white_icon;
    black_icon.addFile(":/image/chesspiece/blackchesspiece.png");
    white_icon.addFile(":/image/chesspiece/whitechesspiece.png");

    ui->comboBoxPickSide->addItem(black_icon,"黑子");
    ui->comboBoxPickSide->addItem(white_icon,"白子");

    ui->comboBoxPickSide->setCurrentIndex(0);
    connect(ui->pushButtonPickSide, SIGNAL(clicked()), this, SLOT(close()));
}

PickSideWindow::~PickSideWindow() {
    delete ui;
}

int PickSideWindow::GetSide() const {
    if(ui->comboBoxPickSide->currentIndex()){
        return 1;
    }else{
        return -1;
    }
}

void PickSideWindow::closeEvent(QCloseEvent * e) {
    SendSide(GetSide());
    e->accept();
}