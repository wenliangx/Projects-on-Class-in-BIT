//
// Created by 18759 on 2024/4/15.
//

#ifndef PROJECT1_SETTINGWINDOW_H
#define PROJECT1_SETTINGWINDOW_H

#include <QDialog>


QT_BEGIN_NAMESPACE
namespace Ui { class SettingWindow; }
QT_END_NAMESPACE

class SettingWindow : public QDialog {
Q_OBJECT

public:
    explicit SettingWindow(QWidget *parent = nullptr);

    ~SettingWindow() override;

private:
    Ui::SettingWindow *ui;
private slots:
    void on_pushButtonClose_clicked();
};


#endif //PROJECT1_SETTINGWINDOW_H
