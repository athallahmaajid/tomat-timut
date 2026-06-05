#ifndef STATSWINDOW_H
#define STATSWINDOW_H

#include <QDialog>
#include <QJsonObject>
#include <QWidget>
#include <QVector>
#include <QPair>
#include <QDate>

class ChartWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ChartWidget(const QJsonObject &stats, QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QVector<QPair<QString, int>> m_data;
    void prepareData(const QJsonObject &stats);
};

class StatsWindow : public QDialog
{
    Q_OBJECT
public:
    explicit StatsWindow(const QJsonObject &stats, QWidget *parent = nullptr);
};

#endif
