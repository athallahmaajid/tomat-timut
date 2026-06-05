#include "statswindow.h"
#include <QVBoxLayout>
#include <QTableWidget>
#include <QHeaderView>
#include <QPushButton>
#include <QLabel>
#include <QPainter>
#include <algorithm>
#include <QFontMetrics>
#include <QtMath>

ChartWidget::ChartWidget(const QJsonObject &stats, QWidget *parent)
    : QWidget(parent)
{
    setMinimumHeight(200);
    setMaximumHeight(280);
    prepareData(stats);
}

void ChartWidget::prepareData(const QJsonObject &stats)
{
    m_data.clear();
    QDate today = QDate::currentDate();
    for (int i = 13; i >= 0; --i) {
        QDate date = today.addDays(-i);
        QString key = date.toString("yyyy-MM-dd");
        int count = 0;
        if (stats.contains(key))
            count = stats[key].toObject()["pomodoros"].toInt();
        m_data.append({date.toString("dd/MM"), count});
    }
}

void ChartWidget::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);

    int w = width();
    int h = height();
    int left = 50;
    int right = 20;
    int top = 20;
    int bottom = 40;
    int chartW = w - left - right;
    int chartH = h - top - bottom;

    p.fillRect(rect(), QColor("#FAFFCB"));

    if (chartW < 10 || chartH < 10) return;

    int maxVal = 0;
    for (auto &d : m_data)
        maxVal = qMax(maxVal, d.second);
    if (maxVal == 0) maxVal = 5;
    else maxVal = ((maxVal + 4) / 5) * 5;

    p.setPen(QColor(200, 200, 200));
    for (int i = 0; i <= 4; ++i) {
        int y = top + chartH - (chartH * i / 4);
        p.drawLine(left, y, w - right, y);
        p.setPen(Qt::black);
        p.drawText(0, y - 8, left - 8, 16, Qt::AlignRight | Qt::AlignVCenter,
                   QString::number(maxVal * i / 4));
        p.setPen(QColor(200, 200, 200));
    }

    int n = m_data.size();
    if (n == 0) return;

    int barWidth = qMin(chartW / n - 4, 40);
    if (barWidth < 6) barWidth = 6;

    QDate today = QDate::currentDate();

    for (int i = 0; i < n; ++i) {
        int x = left + chartW * i / n + (chartW / n - barWidth) / 2;
        int barH = (m_data[i].second * chartH) / maxVal;
        if (barH == 0 && m_data[i].second > 0) barH = 2;

        int y = top + chartH - barH;

        QColor barColor;
        QString key = today.addDays(i - 13).toString("yyyy-MM-dd");
        QString todayKey = today.toString("yyyy-MM-dd");
        if (key == todayKey)
            barColor = QColor("#F13E93");
        else
            barColor = QColor(241, 62, 147, 160);

        p.setBrush(barColor);
        p.setPen(Qt::NoPen);
        p.drawRoundedRect(x, y, barWidth, barH, 3, 3);

        if (m_data[i].second > 0) {
            p.setPen(Qt::black);
            QFont f = p.font();
            f.setPointSize(8);
            p.setFont(f);
            p.drawText(x, y - 14, barWidth, 12, Qt::AlignCenter,
                       QString::number(m_data[i].second));
        }

        p.setPen(Qt::black);
        QFont f = p.font();
        f.setPointSize(7);
        p.setFont(f);
        p.drawText(x - 6, top + chartH + 4, barWidth + 12, 30, Qt::AlignCenter | Qt::TextWordWrap,
                   m_data[i].first);
    }

    p.setPen(QColor(100, 100, 100));
    QFont f = p.font();
    f.setPointSize(9);
    f.setBold(true);
    p.setFont(f);
    p.drawText(left, 2, chartW, top, Qt::AlignCenter, "Pomodoros per Day (Last 14 Days)");
}

StatsWindow::StatsWindow(const QJsonObject &stats, QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("Daily Statistics");
    setFixedSize(600, 520);
    setStyleSheet("QDialog { background-color: #FAFFCB; }");

    auto *layout = new QVBoxLayout(this);

    auto *chart = new ChartWidget(stats, this);
    layout->addWidget(chart);

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

    int totalPomodoros = 0;
    int totalFocusSecs = 0;

    table->setRowCount(dates.size());
    for (int i = 0; i < dates.size(); ++i) {
        QJsonObject day = stats[dates[i]].toObject();
        int pomodoros = day["pomodoros"].toInt();
        int focusSecs = day["focusSeconds"].toInt();
        int breaks = day["breaks"].toInt();

        totalPomodoros += pomodoros;
        totalFocusSecs += focusSecs;

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
    closeBtn->setStyleSheet(
        "QPushButton { background-color: #F13E93; color: white; padding: 6px 20px; "
        "border-radius: 8px; font-size: 14px; }"
    );
    connect(closeBtn, &QPushButton::clicked, this, &QDialog::accept);
    layout->addWidget(closeBtn);
}
