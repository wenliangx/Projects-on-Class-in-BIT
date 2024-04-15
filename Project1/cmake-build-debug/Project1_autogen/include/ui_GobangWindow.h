/********************************************************************************
** Form generated from reading UI file 'gobangwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GOBANGWINDOW_H
#define UI_GOBANGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_GobangWindow
{
public:
    QPushButton *pushButtonBack;
    QPushButton *pushButtonGobangToSetting;

    void setupUi(QDialog *GobangWindow)
    {
        if (GobangWindow->objectName().isEmpty())
            GobangWindow->setObjectName("GobangWindow");
        GobangWindow->resize(800, 600);
        pushButtonBack = new QPushButton(GobangWindow);
        pushButtonBack->setObjectName("pushButtonBack");
        pushButtonBack->setGeometry(QRect(690, 500, 75, 24));
        pushButtonGobangToSetting = new QPushButton(GobangWindow);
        pushButtonGobangToSetting->setObjectName("pushButtonGobangToSetting");
        pushButtonGobangToSetting->setGeometry(QRect(690, 440, 75, 24));

        retranslateUi(GobangWindow);

        QMetaObject::connectSlotsByName(GobangWindow);
    } // setupUi

    void retranslateUi(QDialog *GobangWindow)
    {
        GobangWindow->setWindowTitle(QCoreApplication::translate("GobangWindow", "GobangWindow", nullptr));
        pushButtonBack->setText(QCoreApplication::translate("GobangWindow", "\350\277\224\345\233\236", nullptr));
        pushButtonGobangToSetting->setText(QCoreApplication::translate("GobangWindow", "\350\256\276\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GobangWindow: public Ui_GobangWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GOBANGWINDOW_H
