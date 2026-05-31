#ifndef STATSWINDOW_H
#define STATSWINDOW_H

#include <QDialog>
#include <QJsonObject>

class StatsWindow : public QDialog
{
    Q_OBJECT
public:
    explicit StatsWindow(const QJsonObject &stats, QWidget *parent = nullptr);
};
#endif
