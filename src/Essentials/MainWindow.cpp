#include "MainWindow.h"

void MainWindow::updateTime(QLabel* dateText, QLabel* timeText) {
    dateText->setText(os_getDate());
    timeText->setText(os_getTime());
}