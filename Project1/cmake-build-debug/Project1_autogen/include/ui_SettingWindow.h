/********************************************************************************
** Form generated from reading UI file 'settingwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGWINDOW_H
#define UI_SETTINGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_SettingWindow
{
public:
    QRadioButton *radioButton;
    QPushButton *pushButtonClose;

    void setupUi(QDialog *SettingWindow)
    {
        if (SettingWindow->objectName().isEmpty())
            SettingWindow->setObjectName("SettingWindow");
        SettingWindow->resize(400, 300);
        radioButton = new QRadioButton(SettingWindow);
        radioButton->setObjectName("radioButton");
        radioButton->setGeometry(QRect(150, 110, 111, 31));
        QFont font;
        font.setPointSize(12);
        radioButton->setFont(font);
        pushButtonClose = new QPushButton(SettingWindow);
        pushButtonClose->setObjectName("pushButtonClose");
        pushButtonClose->setGeometry(QRect(280, 250, 75, 24));

        retranslateUi(SettingWindow);

        QMetaObject::connectSlotsByName(SettingWindow);
    } // setupUi

    void retranslateUi(QDialog *SettingWindow)
    {
        SettingWindow->setWindowTitle(QCoreApplication::translate("SettingWindow", "SettingWindow", nullptr));
        radioButton->setText(QCoreApplication::translate("SettingWindow", "\350\220\275\345\255\220\345\211\215\347\241\256\350\256\244", nullptr));
        pushButtonClose->setText(QCoreApplication::translate("SettingWindow", "\345\205\263\351\227\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingWindow: public Ui_SettingWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGWINDOW_H
