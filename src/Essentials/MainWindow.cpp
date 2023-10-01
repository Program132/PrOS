#include "MainWindow.h"

void MainWindow::updateTime(QLabel* dateText, QLabel* timeText) {
    std::time_t rawtime;
    std::tm *timeinfo;
    char buffer[80];
    std::time(&rawtime);
    timeinfo = std::localtime(&rawtime);
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", timeinfo);
    QString dateString(buffer);
    std::strftime(buffer, sizeof(buffer), "%H:%M:%S", timeinfo);
    QString timeString(buffer);

    dateText->setText(dateString);
    timeText->setText(timeString);
}
