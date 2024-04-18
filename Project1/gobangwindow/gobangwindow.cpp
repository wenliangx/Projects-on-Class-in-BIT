//
// Created by 18759 on 2024/4/15.
//

// You may need to build the project (run Qt uic code generator) to get "ui_GobangWindow.h" resolved

#include <QResource>
#include "gobangwindow.h"
#include "ui_GobangWindow.h"
#include "../startwindow/startwindow.h"
#include "../settingwindow/settingwindow.h"
#include "../picksidewindow/picksidewindow.h"


GobangWindow::GobangWindow(QWidget *parent) :
        QDialog(parent), ui(new Ui::GobangWindow) {
    ui->setupUi(this);

    connect(ui->ButtonGobangToSetting, SIGNAL(clicked()), this, SLOT(OpenSetting()));
    connect(ui->ButtonGobangBack, SIGNAL(clicked()), this, SLOT(GobangBack()));

    broad = new Gobang;

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

    QImage black_chess_piece_image(QString(":/image/chesspiece/blackchesspiece.png"));
    black_chess_piece_image = black_chess_piece_image.scaled(CHESS_PIECE_SIZE, CHESS_PIECE_SIZE, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    black_chess_piece_pixmap = QPixmap::fromImage(black_chess_piece_image);
    QImage white_chess_piece_image(QString(":/image/chesspiece/whitechesspiece.png"));
    white_chess_piece_image = white_chess_piece_image.scaled(CHESS_PIECE_SIZE, CHESS_PIECE_SIZE, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    white_chess_piece_pixmap = QPixmap::fromImage(white_chess_piece_image);
    QImage trans_black_image(":/image/chesspiece/transblack.png");
    trans_black_image = trans_black_image.scaled(CHESS_PIECE_SIZE,CHESS_PIECE_SIZE,Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    trans_black_pixmap = QPixmap::fromImage(trans_black_image);
    QImage trans_white_image(":/image/chesspiece/transwhite.png");
    trans_white_image = trans_white_image.scaled(CHESS_PIECE_SIZE,CHESS_PIECE_SIZE,Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    trans_white_pixmap = QPixmap::fromImage(trans_white_image);

    auto pick_side_window = new PickSideWindow(this);
    connect(pick_side_window,SIGNAL(SendSide(int)),this,SLOT(PickSide(int)));
    pick_side_window->setModal(true);
    pick_side_window->show();

    player1label = new QLabel(this);
    player2label = new QLabel(this);
    player1label->setGeometry(700,100,CHESS_PIECE_SIZE,CHESS_PIECE_SIZE);
    player2label->setGeometry(700,500,CHESS_PIECE_SIZE,CHESS_PIECE_SIZE);
    chess = new QLabel**[15];
    for(int i = 0;i<SIZE;++i){
        chess[i] = new QLabel * [15];
        for(int j = 0;j<SIZE;++j){
            chess[i][j] = new QLabel(this);
            chess[i][j]->setGeometry(x[i]-CHESS_PIECE_SIZE/2,y[j]-CHESS_PIECE_SIZE/2,CHESS_PIECE_SIZE,CHESS_PIECE_SIZE);
            chess[i][j]->setPixmap(QPixmap());
            //chess[i][j]->setPixmap(black_chess_piece_pixmap);
        }
    }
    last_mouse = nullptr;
    setMouseTracking(true);

}

GobangWindow::~GobangWindow() {
    delete ui;
}

void GobangWindow::GobangBack() {
    auto startWindow = new StartWindow;
    this->close();
    startWindow->show();
}

void GobangWindow::OpenSetting() {
    auto settingWindow = new SettingWindow(this);
    settingWindow->setModal(true);
    settingWindow->show();
}

void GobangWindow::paintEvent(QPaintEvent *) {
    QPainter main_painter(this);

    QColor color(222, 184, 135);
    main_painter.setBrush(color);
    main_painter.drawRect(this->rect());
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

void GobangWindow::PickSide(int s) {

    if(s){
        broad->InitPlayer(-1);
        player1label->setPixmap(black_chess_piece_pixmap);
        player2label->setPixmap(white_chess_piece_pixmap);
    }else{
        broad->InitPlayer(1);
        player1label->setPixmap(white_chess_piece_pixmap);
        player2label->setPixmap(black_chess_piece_pixmap);
    }

}

void GobangWindow::mouseMoveEvent(QMouseEvent *event){
    auto p = event->pos();
    int xi = (p.x() - 60) / 20;
    int yj = p.y() / 20;
    if(xi>=0 && xi < 30&&yj>=0 && yj < 30){
        int i = xi / 2;
        int j = yj / 2;
        if(last_mouse){
            last_mouse->setPixmap(QPixmap());
        }
        chess[i][j]->setPixmap(trans_white_pixmap);
        last_mouse = chess[i][j];
    }else{
        if(last_mouse){
            last_mouse->setPixmap(QPixmap());
            last_mouse = nullptr;
        }
    }

}
