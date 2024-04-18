//
// Created by 18759 on 2024/4/17.
//

#ifndef PROJECT1_PICKSIDEWINDOW_H
#define PROJECT1_PICKSIDEWINDOW_H

#include <QDialog>
#include "QCloseEvent"

QT_BEGIN_NAMESPACE
namespace Ui { class PickSideWindow; }
QT_END_NAMESPACE

class PickSideWindow : public QDialog {
Q_OBJECT

public:
    explicit PickSideWindow(QWidget *parent = nullptr);

    ~PickSideWindow() override;

    int GetSide() const;

    signals:
    void SendSide(int);

private:
    Ui::PickSideWindow *ui;

protected:
    void closeEvent(QCloseEvent *) override;
};


#endif //PROJECT1_PICKSIDEWINDOW_H
