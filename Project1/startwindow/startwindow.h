//
// Created by 18759 on 2024/4/15.
//

#ifndef PROJECT1_STARTWINDOW_H
#define PROJECT1_STARTWINDOW_H

#include <QDialog>


QT_BEGIN_NAMESPACE
namespace Ui { class StartWindow; }
QT_END_NAMESPACE

class StartWindow : public QDialog {
Q_OBJECT

public:
    explicit StartWindow(QWidget *parent = nullptr);

    ~StartWindow() override;

private:
    Ui::StartWindow *ui;

private slots:
    void on_pushButtonStart_clicked();
    void on_pushButtonStartToSetting_clicked();
};


#endif //PROJECT1_STARTWINDOW_H
