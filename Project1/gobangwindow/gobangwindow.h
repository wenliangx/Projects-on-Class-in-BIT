//
// Created by 18759 on 2024/4/15.
//

#ifndef PROJECT1_GOBANGWINDOW_H
#define PROJECT1_GOBANGWINDOW_H

#include <QDialog>
#include "QPainter"


#define DISTANCE 40
#define NUM 15
#define X_START 80
#define y_START 20

QT_BEGIN_NAMESPACE
namespace Ui { class GobangWindow; }
QT_END_NAMESPACE

class GobangWindow : public QDialog {
Q_OBJECT

public:
    explicit GobangWindow(QWidget *parent = nullptr);

    ~GobangWindow() override;

    void paintEvent(QPaintEvent*);

private:
    Ui::GobangWindow *ui;
    int* x;
    int* y;
private slots:
    void on_pushButtonBack_clicked();
    void on_pushButtonGobangToSetting_clicked();
};


#endif //PROJECT1_GOBANGWINDOW_H
