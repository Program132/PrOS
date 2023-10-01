#include <QMainWindow>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QCoreApplication>
#include <ctime>
#include "CustomClass/ImageButton/ImageButton.h"
#include "CustomClass/TaskbarThemes/TaskBarThemes.h"
#include "CustomClass/TextLabel/TextLabel.h"

class MainWindow : public QMainWindow
{
public:
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

private:
    int w;
    int h;

    void defineWindow() {
        auto *desktopWidget = new QWidget(this);
        auto *desktopLayout = new QVBoxLayout;
        desktopWidget->setLayout(desktopLayout);

        auto *taskBarWidget = new QWidget(this);
        auto *taskBarLayout = new QHBoxLayout;
        taskBarWidget->setLayout(taskBarLayout);
        taskBar(taskBarLayout);

        auto *mainLayout = new QVBoxLayout;
        mainLayout->addWidget(desktopWidget);
        mainLayout->addWidget(taskBarWidget, 1, Qt::AlignBottom);

        auto *centralWidget = new QWidget(this);
        centralWidget->setLayout(mainLayout);
        setCentralWidget(centralWidget);
    }

    void taskBar(QHBoxLayout *layout) {
        // Time + Date Vars:
        std::time_t rawtime;
        std::tm *timeinfo;
        char buffer[80];
        std::time(&rawtime);
        timeinfo = std::localtime(&rawtime);
        std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", timeinfo);
        QString dateString(buffer);
        std::strftime(buffer, sizeof(buffer), "%H:%M:%S", timeinfo);
        QString timeString(buffer);

        // Define taskbar:
        auto *dateTimeWidget = new QWidget(this);
        auto *themesWidget = new QWidget(this);
        auto *appWidget = new QWidget(this);

        setWidgetFrame(dateTimeWidget, "#5B5B5B", "#808080");
        setWidgetFrame(themesWidget, "#5B5B5B", "#808080");
        setWidgetFrame(appWidget, "#5B5B5B", "#808080");

        auto *prOSManagerButton = new ImageButton("", projectPath + "/src/img/onoff.png", "background: transparent;", appWidget);

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

        layout->addWidget(appWidget);
        layout->addItem(spacerLeft);
        layout->addWidget(themesWidget);
        layout->addItem(spacerRight);
        layout->addWidget(dateTimeWidget);
    }

    static void setWidgetFrame(QWidget *widget, const QString &startColor, const QString &endColor) {
        widget->setObjectName("WidgetFrame");
        widget->setStyleSheet(QString("#WidgetFrame { background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 %1, stop:1 %2); border-radius: 13px; }").arg(startColor, endColor));
    }
};