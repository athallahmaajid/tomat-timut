#include "mainwindow.h"
#include <string>
#include "./ui_mainwindow.h"
#include <QTimer>
#include <sstream>
#include <QFile>
#include <QJsonDocument>
#include <QCoreApplication>
#include <QDate>
#include <QApplication>
#include "statswindow.h"
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(570, 420);

    timer = new QTimer(this);
    isFocus = true;
    focusTime = 25;
    timeLeft = focusTime * 60;
    breakTime = 5;
    statsFile = QCoreApplication::applicationDirPath() + "/stats.json";

    setWindowTitle("Pomodoro");

    connect(timer, &QTimer::timeout, this, &MainWindow::updateTimer);
    updateUI();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startButton_clicked()
{
    if (timer->isActive()) {
        timer->stop();
        ui->startButton->setText("Start");
    }
    else {
        timer->start(1000);
        ui->startButton->setText("Pause");
        updateTimer();
    }
}


void MainWindow::on_resetButton_clicked()
{
    timer->stop();
    if (isFocus) timeLeft = focusTime * 60;
    else timeLeft = breakTime * 60;
    updateUI();
    ui->startButton->setText("Start");
}

void MainWindow::updateTimer()
{

    if (timeLeft > 0) {
        timeLeft--;
        updateUI();
    } else {
        timer->stop();
        QApplication::beep();
        if (isFocus) {
            recordSession();
            timeLeft = breakTime * 60;
            isFocus = false;
        } else {
            QJsonObject stats = loadStats();
            QString key = todayKey();
            QJsonObject day = stats[key].toObject();
            day["breaks"] = day["breaks"].toInt() + 1;
            stats[key] = day;
            saveStats(stats);
            timeLeft = focusTime * 60;
            isFocus = true;
        }
        timer->start(1000);
    }
}

void MainWindow::updateUI()
{
    int minutes = timeLeft / 60;
    int seconds = timeLeft % 60;

    QString timeString = QString("%1:%2")
                             .arg(minutes, 2, 10, QChar('0'))
                             .arg(seconds, 2, 10, QChar('0'));

    ui->timer->setText(timeString);
    ui->label_4->setText(isFocus ? "FOCUS" : "BREAK");
}


void MainWindow::on_decrementBreak_clicked()
{
    int a;
    stringstream(ui->breakTime->text().toStdString()) >> a;
    a--;
    ui->breakTime->setText(QString(QString::fromStdString(to_string(a))));
    stringstream(ui->breakTime->text().toStdString()) >> breakTime;
    MainWindow::on_resetButton_clicked();
}


void MainWindow::on_incrementBreak_clicked()
{
    int a;
    stringstream(ui->breakTime->text().toStdString()) >> a;
    a++;
    ui->breakTime->setText(QString(QString::fromStdString(to_string(a))));
    stringstream(ui->breakTime->text().toStdString()) >> breakTime;
    MainWindow::on_resetButton_clicked();
}


void MainWindow::on_decrementFocus_clicked()
{
    int a;
    stringstream(ui->focusTime->text().toStdString()) >> a;
    a--;
    ui->focusTime->setText(QString(QString::fromStdString(to_string(a))));
    stringstream(ui->focusTime->text().toStdString()) >> focusTime;
    MainWindow::on_resetButton_clicked();
}


void MainWindow::on_incrementFocus_clicked()
{
    int a;
    stringstream(ui->focusTime->text().toStdString()) >> a;
    a++;
    ui->focusTime->setText(QString(QString::fromStdString(to_string(a))));
    stringstream(ui->focusTime->text().toStdString()) >> focusTime;
    MainWindow::on_resetButton_clicked();
}

QString MainWindow::todayKey()
{
    return QDate::currentDate().toString("yyyy-MM-dd");
}

QJsonObject MainWindow::loadStats()
{
    QFile file(statsFile);
    if (!file.open(QIODevice::ReadOnly))
        return QJsonObject();
    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    file.close();
    return doc.object();
}

void MainWindow::saveStats(const QJsonObject &stats)
{
    QFile file(statsFile);
    if (file.open(QIODevice::WriteOnly))
        file.write(QJsonDocument(stats).toJson());
}

void MainWindow::recordSession()
{
    QJsonObject stats = loadStats();
    QString key = todayKey();
    QJsonObject day = stats[key].toObject();

    int pomodoros = day["pomodoros"].toInt() + 1;
    int focusSeconds = day["focusSeconds"].toInt() + focusTime * 60;

    day["pomodoros"] = pomodoros;
    day["focusSeconds"] = focusSeconds;
    stats[key] = day;

    saveStats(stats);
}

void MainWindow::on_pushButton_3_clicked()
{
    QJsonObject stats = loadStats();
    StatsWindow sw(stats, this);
    sw.exec();
}

