//
// Created by 18759 on 2024/4/15.
//

#ifndef PROJECT1_GOBANGWINDOW_H
#define PROJECT1_GOBANGWINDOW_H

#include <QDialog>
#include <QMouseEvent>
#include "QPainter"
#include "gobang.h"

#define DISTANCE 40
#define NUM 15
#define X_START 80
#define y_START 20
#define CHESS_PIECE_SIZE 20

QT_BEGIN_NAMESPACE
namespace Ui { class GobangWindow; }
QT_END_NAMESPACE

class GobangWindow : public QDialog {
Q_OBJECT

public:
    explicit GobangWindow(QWidget *parent = nullptr);

    ~GobangWindow() override;

    void paintEvent(QPaintEvent*) override;


private:
    Ui::GobangWindow *ui;
    int* x;
    int* y;
    QLabel*** chess;
    QLabel* last_mouse;
    QPixmap black_chess_piece_pixmap;
    QPixmap white_chess_piece_pixmap;
    QPixmap trans_black_pixmap;
    QPixmap trans_white_pixmap;
    QLabel* player1label;
    QLabel* player2label;
    Gobang* broad;
    ChessPiece* last_chess{};
private slots:
    void GobangBack();
    void OpenSetting();
    void PickSide(int);
    void Restart();
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
};


#endif //PROJECT1_GOBANGWINDOW_H
