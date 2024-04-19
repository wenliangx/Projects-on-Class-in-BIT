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
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GobangWindow
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QPushButton *ButtonGobangBack;
    QLabel *labelDraw;
    QPushButton *ButtonGobangToSetting;
    QLabel *labelPlayer2;
    QLabel *labelPlayer1;
    QPushButton *pushButtonRestart;
    QPushButton *pushButtonSurround1;
    QPushButton *pushButtonSurround2;

    void setupUi(QDialog *GobangWindow)
    {
        if (GobangWindow->objectName().isEmpty())
            GobangWindow->setObjectName("GobangWindow");
        GobangWindow->resize(800, 606);
        layoutWidget = new QWidget(GobangWindow);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(690, 200, 77, 211));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        ButtonGobangBack = new QPushButton(layoutWidget);
        ButtonGobangBack->setObjectName("ButtonGobangBack");

        verticalLayout_2->addWidget(ButtonGobangBack);

        labelDraw = new QLabel(layoutWidget);
        labelDraw->setObjectName("labelDraw");

        verticalLayout_2->addWidget(labelDraw);

        ButtonGobangToSetting = new QPushButton(layoutWidget);
        ButtonGobangToSetting->setObjectName("ButtonGobangToSetting");

        verticalLayout_2->addWidget(ButtonGobangToSetting);

        labelPlayer2 = new QLabel(GobangWindow);
        labelPlayer2->setObjectName("labelPlayer2");
        labelPlayer2->setGeometry(QRect(700, 40, 54, 16));
        labelPlayer1 = new QLabel(GobangWindow);
        labelPlayer1->setObjectName("labelPlayer1");
        labelPlayer1->setGeometry(QRect(700, 550, 54, 16));
        pushButtonRestart = new QPushButton(GobangWindow);
        pushButtonRestart->setObjectName("pushButtonRestart");
        pushButtonRestart->setGeometry(QRect(690, 450, 75, 24));
        pushButtonSurround1 = new QPushButton(GobangWindow);
        pushButtonSurround1->setObjectName("pushButtonSurround1");
        pushButtonSurround1->setGeometry(QRect(690, 570, 75, 24));
        pushButtonSurround2 = new QPushButton(GobangWindow);
        pushButtonSurround2->setObjectName("pushButtonSurround2");
        pushButtonSurround2->setGeometry(QRect(690, 10, 75, 24));

        retranslateUi(GobangWindow);

        QMetaObject::connectSlotsByName(GobangWindow);
    } // setupUi

    void retranslateUi(QDialog *GobangWindow)
    {
        GobangWindow->setWindowTitle(QCoreApplication::translate("GobangWindow", "GobangWindow", nullptr));
        ButtonGobangBack->setText(QCoreApplication::translate("GobangWindow", "\350\277\224\345\233\236", nullptr));
        labelDraw->setText(QCoreApplication::translate("GobangWindow", "TextLabel", nullptr));
        ButtonGobangToSetting->setText(QCoreApplication::translate("GobangWindow", "\350\256\276\347\275\256", nullptr));
        labelPlayer2->setText(QCoreApplication::translate("GobangWindow", "TextLabel", nullptr));
        labelPlayer1->setText(QCoreApplication::translate("GobangWindow", "TextLabel", nullptr));
        pushButtonRestart->setText(QCoreApplication::translate("GobangWindow", "\351\207\215\346\226\260\345\274\200\345\247\213", nullptr));
        pushButtonSurround1->setText(QCoreApplication::translate("GobangWindow", "\347\216\251\345\256\2661\346\212\225\351\231\215", nullptr));
        pushButtonSurround2->setText(QCoreApplication::translate("GobangWindow", "\347\216\251\345\256\2662\346\212\225\351\231\215", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GobangWindow: public Ui_GobangWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GOBANGWINDOW_H
