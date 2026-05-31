#include "statswindow.h"
#include <QVBoxLayout>
#include <QTableWidget>
#include <QHeaderView>
#include <QPushButton>
#include <algorithm>

StatsWindow::StatsWindow(const QJsonObject &stats, QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("Daily Statistics");
    setFixedSize(500, 400);
    setStyleSheet("QDialog { background-color: #FAFFCB; }");

    auto *layout = new QVBoxLayout(this);
    auto *table = new QTableWidget(this);
    table->setColumnCount(4);
    table->setHorizontalHeaderLabels({"Date", "Pomodoros", "Focus Time", "Breaks"});
    table->horizontalHeader()->setStretchLastSection(true);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table->setSelectionBehavior(QAbstractItemView::SelectRows);
    table->setStyleSheet(
        "QTableWidget { background-color: white; color: black; gridline-color: #ccc; }"
        "QHeaderView::section { background-color: #F9D0CD; color: black; }"
    );

    QStringList dates = stats.keys();
    std::sort(dates.begin(), dates.end(), std::greater<QString>());

    table->setRowCount(dates.size());
    for (int i = 0; i < dates.size(); ++i) {
        QJsonObject day = stats[dates[i]].toObject();
        int pomodoros = day["pomodoros"].toInt();
        int focusSecs = day["focusSeconds"].toInt();
        int breaks = day["breaks"].toInt();

        QString focusTime = QString("%1m %2s")
                                .arg(focusSecs / 60)
                                .arg(focusSecs % 60);

        auto *dateItem = new QTableWidgetItem(dates[i]);
        dateItem->setForeground(Qt::black);
        table->setItem(i, 0, dateItem);
        auto *pomItem = new QTableWidgetItem(QString::number(pomodoros));
        pomItem->setForeground(Qt::black);
        table->setItem(i, 1, pomItem);
        auto *focusItem = new QTableWidgetItem(focusTime);
        focusItem->setForeground(Qt::black);
        table->setItem(i, 2, focusItem);
        auto *breakItem = new QTableWidgetItem(QString::number(breaks));
        breakItem->setForeground(Qt::black);
        table->setItem(i, 3, breakItem);
    }

    table->resizeColumnsToContents();
    layout->addWidget(table);

    auto *closeBtn = new QPushButton("Close", this);
    connect(closeBtn, &QPushButton::clicked, this, &QDialog::accept);
    layout->addWidget(closeBtn);
}
