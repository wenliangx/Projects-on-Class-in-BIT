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
    connect(ui->pushButtonRestart, SIGNAL(clicked()), this, SLOT(Restart()));
    connect(ui->pushButtonSurround1,SIGNAL(clicked()),this, SLOT(PressSurround1()));
    connect(ui->pushButtonSurround2,SIGNAL(clicked()),this, SLOT(PressSurround2()));

    if(if_ensure){
        sure = false;
    }else{
        sure = true;
    }
    last_chess_label = nullptr;

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
    QImage eblack_chess_piece_image(QString(":/image/chesspiece/eblackchesspiece.png"));
    eblack_chess_piece_image = eblack_chess_piece_image.scaled(CHESS_PIECE_SIZE, CHESS_PIECE_SIZE, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    eblack_chess_piece_pixmap = QPixmap::fromImage(eblack_chess_piece_image);
    QImage ewhite_chess_piece_image(QString(":/image/chesspiece/ewhitechesspiece.png"));
    ewhite_chess_piece_image = ewhite_chess_piece_image.scaled(CHESS_PIECE_SIZE, CHESS_PIECE_SIZE, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    ewhite_chess_piece_pixmap = QPixmap::fromImage(ewhite_chess_piece_image);

    auto pick_side_window = new PickSideWindow(this);
    connect(pick_side_window,SIGNAL(SendSide(int)),this,SLOT(PickSide(int)));
    pick_side_window->setModal(true);
    pick_side_window->show();

    player1label = new QLabel(this);
    player2label = new QLabel(this);
    player1label->setGeometry(700,500,CHESS_PIECE_SIZE,CHESS_PIECE_SIZE);
    player2label->setGeometry(700,100,CHESS_PIECE_SIZE,CHESS_PIECE_SIZE);

    ui->labelDraw->setText(QString());
    ui->labelPlayer1->setText(QString());
    ui->labelPlayer2->setText(QString());

    chess = new QLabel**[15];
    for(int i = 0;i<SIZE;++i){
        chess[i] = new QLabel * [15];
        for(int j = 0;j<SIZE;++j){
            chess[i][j] = new QLabel(this);
            chess[i][j]->setGeometry(x[i]-CHESS_PIECE_SIZE/2,y[j]-CHESS_PIECE_SIZE/2,CHESS_PIECE_SIZE,CHESS_PIECE_SIZE);
            chess[i][j]->setPixmap(QPixmap());
        }
    }
    last_mouse = nullptr;
    last_chess = nullptr;
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
    broad->InitGobang(s);
    if(s==-1){
        player1label->setPixmap(black_chess_piece_pixmap);
        player2label->setPixmap(white_chess_piece_pixmap);
    }else{
        player1label->setPixmap(white_chess_piece_pixmap);
        player2label->setPixmap(black_chess_piece_pixmap);
    }

}

void GobangWindow::mouseMoveEvent(QMouseEvent *event){
    if(broad->GetWinner()==1){
        ui->labelPlayer1->setText(QString("WIN!"));
    }else if(broad->GetWinner()==2){
        ui->labelPlayer2->setText(QString("WIN!"));
    }else if(broad->Full()){
        ui->labelDraw->setText(QString("平局"));
    }else {
        auto p = event->pos();
        int xi = (p.x() - 60) / 20;
        int yj = p.y() / 20;
        if (xi >= 0 && xi < 30 && yj >= 0 && yj < 30) {
            int i = xi / 2;
            int j = yj / 2;
            if (last_mouse) {
                if (last_chess->state == EMPTY) {
                    last_mouse->setPixmap(QPixmap());
                }
            }
            if ((broad->GetPlayer1()->first && broad->GetPlayer1()->color == -1) ||
                (!broad->GetPlayer1()->first && broad->GetPlayer1()->color == 1)) {
                if (broad->GetChessPiece(i, j)->state == EMPTY) {
                    chess[i][j]->setPixmap(trans_black_pixmap);
                }
            } else {
                if (broad->GetChessPiece(i, j)->state == EMPTY) {
                    chess[i][j]->setPixmap(trans_white_pixmap);
                }

            }
            last_mouse = chess[i][j];
            last_chess = broad->GetChessPiece(i, j);
        } else {
            if (last_mouse) {
                if (last_chess->state == EMPTY) {
                    last_mouse->setPixmap(QPixmap());
                }
                last_mouse = nullptr;
            }
        }
    }
}

void GobangWindow::mousePressEvent(QMouseEvent *event) {
    if(broad->GetWinner()==1){
        ui->labelPlayer1->setText(QString("WIN!"));
    }else if(broad->GetWinner()==2){
        ui->labelPlayer2->setText(QString("WIN!"));
    }else if(broad->Full()){
        ui->labelDraw->setText(QString("平局"));
    }else{
        if(if_ensure){
            sure = false;
        }else{
            sure = true;
        }
        auto p = event->pos();
        int xi = (p.x() - 60) / 20;
        int yj = p.y() / 20;
        if(xi>=0 && xi < 30&&yj>=0 && yj < 30){
            int i = xi / 2;
            int j = yj / 2;
            if(broad->GetChessPiece(i,j)->state == EMPTY){
                if(if_ensure){
                    auto ensure_window = new EnsureWindow(this);
                    connect(ensure_window,SIGNAL(SendSure(bool)),this,SLOT(PressSure(bool)));
                    ensure_window->setModal(true);
                    ensure_window->exec();
                }
                if(sure){
                    auto press_chess = broad->Move(i, j);
                    if(press_chess->state == BLACK){
                        if(last_chess_label){
                            last_chess_label->setPixmap(white_chess_piece_pixmap);
                        }
                        chess[i][j]->setPixmap(eblack_chess_piece_pixmap);

                    } else if(press_chess->state == WHITE){
                        if(last_chess_label){
                            last_chess_label->setPixmap(black_chess_piece_pixmap);
                        }
                        chess[i][j]->setPixmap(ewhite_chess_piece_pixmap);
                    }
                    last_chess_label = chess[i][j];
                }
            }

        }
        if(broad->GetWinner()==1){
            ui->labelPlayer1->setText(QString("WIN!"));
        }else if(broad->GetWinner()==2){
            ui->labelPlayer2->setText(QString("WIN!"));
        }else if(broad->Full()){
            ui->labelDraw->setText(QString("平局"));
        }
    }
}

void GobangWindow::Restart() {
    if(if_ensure){
        sure = false;
    }else{
        sure = true;
    }
    last_chess_label = nullptr;
    auto pick_side_window = new PickSideWindow(this);
    connect(pick_side_window,SIGNAL(SendSide(int)),this,SLOT(PickSide(int)));
    pick_side_window->setModal(true);
    pick_side_window->exec();
    ui->labelDraw->setText(QString());
    ui->labelPlayer1->setText(QString());
    ui->labelPlayer2->setText(QString());
    for(int i = 0;i<SIZE;++i){
        for(int j = 0;j<SIZE;++j){
            chess[i][j]->setPixmap(QPixmap());
        }
    }
    last_mouse = nullptr;
    last_chess = nullptr;
}

void GobangWindow::PressSure(bool b){
    sure = b;
}

void GobangWindow::PressSurround1() {
    broad->SetWinner(2);
    if(broad->GetWinner()==2){
        ui->labelPlayer2->setText(QString("WIN!"));
    }

}

void GobangWindow::PressSurround2() {
    broad->SetWinner(1);
    if(broad->GetWinner()==1){
        ui->labelPlayer1->setText(QString("WIN!"));
    }

}
