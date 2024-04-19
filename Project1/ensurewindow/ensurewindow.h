
#ifndef PROJECT1_ENSUREWINDOW_H
#define PROJECT1_ENSUREWINDOW_H

#include <QDialog>
#include "ensure.h"

QT_BEGIN_NAMESPACE
namespace Ui { class EnsureWindow; }
QT_END_NAMESPACE

class EnsureWindow : public QDialog {
Q_OBJECT

public:
    explicit EnsureWindow(QWidget *parent = nullptr);

    ~EnsureWindow() override;

    signals:
    void SendSure(bool);

private:
    Ui::EnsureWindow *ui;
private slots:
    void PushSure();
    void PushNotSure();
};


#endif //PROJECT1_ENSUREWINDOW_H
