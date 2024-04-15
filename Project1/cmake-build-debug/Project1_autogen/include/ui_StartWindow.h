/********************************************************************************
** Form generated from reading UI file 'startwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTWINDOW_H
#define UI_STARTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_StartWindow
{
public:
    QPushButton *pushButtonStart;
    QPushButton *pushButtonStartToSetting;

    void setupUi(QDialog *StartWindow)
    {
        if (StartWindow->objectName().isEmpty())
            StartWindow->setObjectName("StartWindow");
        StartWindow->resize(400, 300);
        pushButtonStart = new QPushButton(StartWindow);
        pushButtonStart->setObjectName("pushButtonStart");
        pushButtonStart->setGeometry(QRect(150, 100, 81, 41));
        QFont font;
        font.setPointSize(15);
        pushButtonStart->setFont(font);
        pushButtonStartToSetting = new QPushButton(StartWindow);
        pushButtonStartToSetting->setObjectName("pushButtonStartToSetting");
        pushButtonStartToSetting->setGeometry(QRect(150, 170, 81, 21));

        retranslateUi(StartWindow);

        QMetaObject::connectSlotsByName(StartWindow);
    } // setupUi

    void retranslateUi(QDialog *StartWindow)
    {
        StartWindow->setWindowTitle(QCoreApplication::translate("StartWindow", "StartWindow", nullptr));
        pushButtonStart->setText(QCoreApplication::translate("StartWindow", "\345\274\200\345\247\213", nullptr));
        pushButtonStartToSetting->setText(QCoreApplication::translate("StartWindow", "\350\256\276\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StartWindow: public Ui_StartWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTWINDOW_H
