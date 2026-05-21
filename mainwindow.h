#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QJsonObject>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void on_startButton_clicked();
    void on_resetButton_clicked();
    void updateTimer();
    void on_decrementBreak_clicked();
    void on_incrementBreak_clicked();
    void on_decrementFocus_clicked();
    void on_incrementFocus_clicked();
    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    int timeLeft;
    int time;
    int breakTime;
    int focusTime;
    bool isFocus;

    void updateUI();
    void recordSession();
    void saveStats(const QJsonObject &stats);
    QJsonObject loadStats();
    QString todayKey();
    QString statsFile;
};
#endif // MAINWINDOW_H
