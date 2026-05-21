/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *container;
    QPushButton *startButton;
    QPushButton *resetButton;
    QLabel *timer;
    QLabel *label_4;
    QPushButton *pushButton_3;
    QLabel *label_6;
    QLabel *label_8;
    QLabel *label_7;
    QLabel *label_9;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_15;
    QLabel *label_10;
    QLabel *label_17;
    QLabel *label_13;
    QLabel *label_14;
    QGroupBox *groupBox_3;
    QGroupBox *groupBox;
    QLabel *breakLength;
    QToolButton *decrementBreak;
    QToolButton *incrementBreak;
    QLabel *label_3;
    QGroupBox *groupBox_4;
    QGroupBox *groupBox_5;
    QLabel *focusTime;
    QToolButton *decrementFocus;
    QToolButton *incrementFocus;
    QLabel *label_16;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(573, 424);
        MainWindow->setMouseTracking(false);
        MainWindow->setStyleSheet(QString::fromUtf8("QWidget {\n"
"	background-color: #FAFFCB;\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        container = new QGroupBox(centralwidget);
        container->setObjectName("container");
        container->setGeometry(QRect(110, 60, 341, 171));
        container->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"	background-color: #F9D0CD;\n"
"	border-radius: 16px;\n"
"}"));
        startButton = new QPushButton(container);
        startButton->setObjectName("startButton");
        startButton->setGeometry(QRect(80, 110, 88, 34));
        startButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #F13E93;\n"
"}"));
        resetButton = new QPushButton(container);
        resetButton->setObjectName("resetButton");
        resetButton->setGeometry(QRect(170, 110, 88, 34));
        resetButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #F13E93;\n"
"}"));
        timer = new QLabel(container);
        timer->setObjectName("timer");
        timer->setGeometry(QRect(0, 50, 341, 51));
        timer->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        timer->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: black;\n"
"	background-color: transparent;\n"
"	font-size: 32px;\n"
"	font-family: monospace;\n"
"}"));
        timer->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_4 = new QLabel(container);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(0, 30, 341, 20));
        label_4->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: black;\n"
"	background-color: transparent;\n"
"	font-size: 18px;\n"
"	font-family: arial;\n"
"}"));
        label_4->setAlignment(Qt::AlignmentFlag::AlignCenter);
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(240, 350, 81, 31));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #F9D0CD;\n"
"	color: black;\n"
"	font-family: arial;\n"
"	border: 0px solid;\n"
"	border-radius: 8px;\n"
"}"));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 350, 71, 71));
        label_6->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background-color: transparent;\n"
"}"));
        label_6->setPixmap(QPixmap(QString::fromUtf8(":/flowers/assets/flower3.png")));
        label_6->setScaledContents(true);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(460, 150, 101, 141));
        label_8->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background-color: transparent;\n"
"}"));
        label_8->setPixmap(QPixmap(QString::fromUtf8(":/flowers/assets/flower4.png")));
        label_8->setScaledContents(true);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(130, 340, 81, 71));
        label_7->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background-color: transparent;\n"
"}"));
        label_7->setPixmap(QPixmap(QString::fromUtf8(":/flowers/assets/flower2.png")));
        label_7->setScaledContents(true);
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(0, 0, 91, 91));
        label_9->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background-color: transparent;\n"
"}"));
        label_9->setPixmap(QPixmap(QString::fromUtf8(":/flowers/assets/flower6.png")));
        label_9->setScaledContents(true);
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(350, -10, 81, 71));
        label_11->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background-color: transparent;\n"
"}"));
        label_11->setPixmap(QPixmap(QString::fromUtf8(":/flowers/assets/flower2.png")));
        label_11->setScaledContents(true);
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(480, 330, 91, 91));
        label_12->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background-color: transparent;\n"
"}"));
        label_12->setPixmap(QPixmap(QString::fromUtf8(":/flowers/assets/flower6.png")));
        label_12->setScaledContents(true);
        label_15 = new QLabel(centralwidget);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(430, 210, 41, 41));
        label_15->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background-color: transparent;\n"
"}"));
        label_15->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/flower7.png")));
        label_15->setScaledContents(true);
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(360, 340, 71, 71));
        label_10->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background-color: transparent;\n"
"}"));
        label_10->setPixmap(QPixmap(QString::fromUtf8(":/flowers/assets/flower1.png")));
        label_10->setScaledContents(true);
        label_17 = new QLabel(centralwidget);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(130, -10, 71, 71));
        label_17->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background-color: transparent;\n"
"}"));
        label_17->setPixmap(QPixmap(QString::fromUtf8(":/flowers/assets/flower1.png")));
        label_17->setScaledContents(true);
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(10, 150, 101, 141));
        label_13->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background-color: transparent;\n"
"}"));
        label_13->setPixmap(QPixmap(QString::fromUtf8(":/flowers/assets/flower4.png")));
        label_13->setScaledContents(true);
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(490, 10, 71, 71));
        label_14->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background-color: transparent;\n"
"}"));
        label_14->setPixmap(QPixmap(QString::fromUtf8(":/flowers/assets/flower3.png")));
        label_14->setScaledContents(true);
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(110, 240, 161, 101));
        groupBox_3->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"	background-color: #F13E93;\n"
"	border-radius: 16px;\n"
"}"));
        groupBox = new QGroupBox(groupBox_3);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 10, 141, 51));
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"	background-color: #F9D0CD;\n"
"	border-radius: 16px;\n"
"  display: flex;\n"
"  justify-content: center;\n"
"  align-items: center;  \n"
"}"));
        breakLength = new QLabel(groupBox);
        breakLength->setObjectName("breakLength");
        breakLength->setGeometry(QRect(0, 10, 141, 31));
        breakLength->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: black;\n"
"	background-color: transparent;\n"
"	font-size: 18px;\n"
"}"));
        breakLength->setAlignment(Qt::AlignmentFlag::AlignCenter);
        decrementBreak = new QToolButton(groupBox);
        decrementBreak->setObjectName("decrementBreak");
        decrementBreak->setGeometry(QRect(0, 0, 41, 51));
        decrementBreak->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"	color: #F13E93;\n"
"	background-color: transparent;\n"
"	font-size: 24px;\n"
"	border: none;\n"
"}"));
        incrementBreak = new QToolButton(groupBox);
        incrementBreak->setObjectName("incrementBreak");
        incrementBreak->setGeometry(QRect(105, 0, 31, 51));
        incrementBreak->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"	color: #F13E93;\n"
"	background-color: transparent;\n"
"	font-size: 24px;\n"
"	border: none;\n"
"}"));
        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(3, 70, 161, 20));
        label_3->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: #FAFFCB;\n"
"	background-color: transparent;\n"
"	font-weight: bold;\n"
"}"));
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(290, 240, 161, 101));
        groupBox_4->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"	background-color: #F13E93;\n"
"	border-radius: 16px;\n"
"}"));
        groupBox_5 = new QGroupBox(groupBox_4);
        groupBox_5->setObjectName("groupBox_5");
        groupBox_5->setGeometry(QRect(10, 10, 141, 51));
        groupBox_5->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"	background-color: #F9D0CD;\n"
"	border-radius: 16px;\n"
"  display: flex;\n"
"  justify-content: center;\n"
"  align-items: center;  \n"
"}"));
        focusTime = new QLabel(groupBox_5);
        focusTime->setObjectName("focusTime");
        focusTime->setGeometry(QRect(0, 10, 141, 31));
        focusTime->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: black;\n"
"	background-color: transparent;\n"
"	font-size: 18px;\n"
"}"));
        focusTime->setAlignment(Qt::AlignmentFlag::AlignCenter);
        decrementFocus = new QToolButton(groupBox_5);
        decrementFocus->setObjectName("decrementFocus");
        decrementFocus->setGeometry(QRect(0, 0, 41, 51));
        decrementFocus->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"	color: #F13E93;\n"
"	background-color: transparent;\n"
"	font-size: 24px;\n"
"	border: none;\n"
"}"));
        incrementFocus = new QToolButton(groupBox_5);
        incrementFocus->setObjectName("incrementFocus");
        incrementFocus->setGeometry(QRect(105, 0, 31, 51));
        incrementFocus->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"	color: #F13E93;\n"
"	background-color: transparent;\n"
"	font-size: 24px;\n"
"	border: none;\n"
"}"));
        label_16 = new QLabel(groupBox_4);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(0, 70, 161, 20));
        label_16->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: #FAFFCB;\n"
"	background-color: transparent;\n"
"	font-weight: bold;\n"
"}"));
        label_16->setAlignment(Qt::AlignmentFlag::AlignCenter);
        MainWindow->setCentralWidget(centralwidget);
        groupBox_3->raise();
        label_13->raise();
        label_10->raise();
        label_15->raise();
        label_9->raise();
        label_8->raise();
        container->raise();
        pushButton_3->raise();
        label_6->raise();
        label_7->raise();
        label_11->raise();
        label_12->raise();
        label_17->raise();
        label_14->raise();
        groupBox_4->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        container->setTitle(QString());
        startButton->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        resetButton->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        timer->setText(QCoreApplication::translate("MainWindow", "25:00", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "SESSION", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Statistics", nullptr));
        label_6->setText(QString());
        label_8->setText(QString());
        label_7->setText(QString());
        label_9->setText(QString());
        label_11->setText(QString());
        label_12->setText(QString());
        label_15->setText(QString());
        label_10->setText(QString());
        label_17->setText(QString());
        label_13->setText(QString());
        label_14->setText(QString());
        groupBox_3->setTitle(QString());
        groupBox->setTitle(QString());
        breakLength->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        decrementBreak->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        incrementBreak->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Break Length", nullptr));
        groupBox_4->setTitle(QString());
        groupBox_5->setTitle(QString());
        focusTime->setText(QCoreApplication::translate("MainWindow", "25", nullptr));
        decrementFocus->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        incrementFocus->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Focus Time", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
