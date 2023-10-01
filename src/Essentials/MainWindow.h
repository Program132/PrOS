#include <QMainWindow>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QCoreApplication>
#include <QTimer>
#include <QAbstractAnimation>
#include <QPropertyAnimation>
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
    }

    void taskBar(QHBoxLayout *layout) {
        // Time + Date Vars:
        QString dateString = os_getDate();
        QString timeString = os_getTime();

        // Define taskbar:
        auto *dateTimeWidget = new QWidget(this);
        auto *themesWidget = new QWidget(this);
        auto *appWidget = new QWidget(this);

        setWidgetFrame(dateTimeWidget, "#5B5B5B", "#808080");
        setWidgetFrame(themesWidget, "#5B5B5B", "#808080");
        setWidgetFrame(appWidget, "#5B5B5B", "#808080");

        auto *prOSManagerButton = new ImageButton("", projectPath + "/src/img/onoff.png", "background: transparent;", appWidget);
        auto *terminalButton = new ImageButton("", projectPath + "/src/img/terminal_app.png", "background: transparent;", appWidget);


        auto *theme_matrix = new TaskbarThemes("Matrix Theme",
                                               QString("font-size: 14px; font-weight: bold; background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 %1, stop:1 %2); border-radius: 5px; ")
                                               .arg("#099718", "#037A0F"),
                                               QString("font-size: 13px; font-weight: bold; background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 %1, stop:1 %2); border-radius: 5px; ")
                                                       .arg("#099718", "#037A0F"),
                                               100, 30, themesWidget);
        auto *theme_purple = new TaskbarThemes("Purple Theme",
                                               QString("font-size: 14px; font-weight: bold; background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 %1, stop:1 %2); border-radius: 5px; ")
                                               .arg("#720997", "#46037A"),
                                               QString("font-size: 13px; font-weight: bold; background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 %1, stop:1 %2); border-radius: 5px; ")
                                                       .arg("#720997", "#46037A"),
                                               100, 30, themesWidget);
        auto *theme_blue = new TaskbarThemes("Blue Theme",
                                             QString("font-size: 14px; font-weight: bold; background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 %1, stop:1 %2); border-radius: 5px; ")
                                             .arg("#100CCA", "#4376F9"),
                                             QString("font-size: 13px; font-weight: bold; background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 %1, stop:1 %2); border-radius: 5px; ")
                                                     .arg("#100CCA", "#4376F9"),
                                             100, 30, themesWidget);


        auto *dateText = new TextLabel(dateString,
                                       "font-size: 16px; color: white; font-weight: bold;",
                                       100, 30,
                                       dateTimeWidget);
        auto *timeText = new TextLabel(timeString,
                                       "font-size: 16px; color: white; font-weight: bold;",
                                       100, 30,
                                       dateTimeWidget);


        auto *spacerLeft = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Preferred);
        auto *spacerBetweenThemes = new QSpacerItem(10, 0, QSizePolicy::Fixed, QSizePolicy::Preferred);
        auto *spacerRight = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Preferred);

        auto *dateTimeLayout = new QHBoxLayout(dateTimeWidget);
        dateTimeLayout->addWidget(dateText);
        dateTimeLayout->addWidget(timeText);

        auto *themesLayout = new QHBoxLayout(themesWidget);
        themesLayout->addWidget(theme_matrix);
        themesLayout->addItem(spacerBetweenThemes);
        themesLayout->addWidget(theme_purple);
        themesLayout->addItem(spacerBetweenThemes);
        themesLayout->addWidget(theme_blue);

        auto *appLayout = new QHBoxLayout(appWidget);
        appLayout->addWidget(prOSManagerButton);
        appLayout->addWidget(terminalButton);

        layout->addWidget(appWidget);
        layout->addItem(spacerLeft);
        layout->addWidget(themesWidget);
        layout->addItem(spacerRight);
        layout->addWidget(dateTimeWidget);

        // Events :

        auto *timer = new QTimer(this);
        connect(timer, &QTimer::timeout, [dateText, timeText] {
            updateTime(dateText, timeText);
        });
        timer->start(1000);

        connect(theme_matrix, &QPushButton::clicked, [=, this]() {
            desktopWidget->setStyleSheet("background-image: url(" + projectPath + "/src/img/matrix_bg.png)");
        });
        connect(theme_purple, &QPushButton::clicked, [=, this]() {
            desktopWidget->setStyleSheet("background-image: url(" + projectPath + "/src/img/purple_bg.png)");
        });
        connect(theme_blue, &QPushButton::clicked, [=, this]() {
            desktopWidget->setStyleSheet("background-image: url(" + projectPath + "/src/img/blue_bg.png)");
        });
    }

    void desktop(QVBoxLayout *layout) const {
        desktopWidget->setStyleSheet("background-image: url(" + projectPath + "/src/img/matrix_bg.png)");
    }

    static void setWidgetFrame(QWidget *widget, const QString &startColor, const QString &endColor) {
        widget->setObjectName("WidgetFrame");
        widget->setStyleSheet(QString("#WidgetFrame { background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 %1, stop:1 %2); border-radius: 13px; }").arg(startColor, endColor));
    }
};