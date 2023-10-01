#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

class StartMenu : public QWidget {
public:
    explicit StartMenu(QWidget *parent = nullptr) : QWidget(parent) {
        auto *restartOS = new QPushButton("Restart PrOS", this);
        auto *stopOS = new QPushButton("Stop PrOS", this);
        restartOS->setStyleSheet("font-size: 14px; font-weight: bold; ");
        stopOS->setStyleSheet("font-size: 14px; font-weight: bold; ");

        auto *layout = new QVBoxLayout(this);
        layout->addWidget(restartOS);
        layout->addWidget(stopOS);

        setMinimumSize(300,100);
    }
};