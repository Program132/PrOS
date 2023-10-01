#include <QMainWindow>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QCoreApplication>
#include <QTimer>
#include <QAbstractAnimation>
#include <QPropertyAnimation>
#include <QMenu>
#include "CustomClass/ImageButton/ImageButton.h"
#include "CustomClass/TaskbarThemes/TaskBarThemes.h"
#include "CustomClass/TextLabel/TextLabel.h"
#include "Utils/GetTimeDate.h"
#include "CustomClass/ImageLabel/ImageLabel.h"

class MainWindow : public QMainWindow
{
public:
    QWidget *desktopWidget;
    QString projectPath = QCoreApplication::applicationDirPath();

    MainWindow() {
        resize(800, 600);
        this->w = 800;
        this->h = 600;
        defineWindow();
    }

    MainWindow(int weight, int height) {
        resize(weight, height);
        this->w = weight;
        this->h = height;
        defineWindow();
    }

private slots:
    static void updateTime(QLabel* dateText, QLabel* timeText);

private:
    [[maybe_unused]] int w;
    [[maybe_unused]] int h;

    void createContextMenu();
    static void createFolder();
    static void createFile();
    void showDesktopContextMenu(const QPoint &pos);
    void taskBar(QHBoxLayout *layout);
    void desktop(QVBoxLayout *layout) const;
    static void setWidgetFrame(QWidget *widget, const QString &startColor, const QString &endColor);

    void defineWindow() {
        // Principal Elements :
        auto *mainLayout = new QVBoxLayout;
        auto *centralWidget = new QWidget(this);
        centralWidget->setLayout(mainLayout);
        setCentralWidget(centralWidget);

        desktopWidget = new QWidget(centralWidget);
        auto *desktopLayout = new QVBoxLayout;
        desktopWidget->setLayout(desktopLayout);

        auto *taskBarWidget = new QWidget(centralWidget);
        auto *taskBarLayout = new QHBoxLayout;
        taskBarWidget->setLayout(taskBarLayout);

        // Main

        mainLayout->addWidget(desktopWidget,1);
        mainLayout->addWidget(taskBarWidget);

        // Calling definition
        desktop(desktopLayout);
        taskBar(taskBarLayout);

        desktopWidget->setContextMenuPolicy(Qt::CustomContextMenu);
        connect(desktopWidget, &QWidget::customContextMenuRequested, this, &MainWindow::showDesktopContextMenu);
        // QWidget::customContextMenuRequested = right click
    }
};