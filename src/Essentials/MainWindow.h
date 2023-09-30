#include <QMainWindow>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QCoreApplication>

class MainWindow : public QMainWindow
{
public:
    QString projectPath = QCoreApplication::applicationDirPath();

    MainWindow() {
        resize(800, 600);
        defineWindow();
    }

    MainWindow(int weight, int height) {
        resize(weight, height);
        defineWindow();
    }

private:
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

    void taskBar(QHBoxLayout* layout) {
        // Define taskbar :
        auto *prOSManagerButton = new QPushButton("", this);

        QPixmap prOSManagerButtonPixMap(projectPath + "/src/img/onoff.png");

        QPixmap prOSManagerButtonScaledPixMap = prOSManagerButtonPixMap.scaled(30, 30);
        QIcon prOSManagerButtonIcon(prOSManagerButtonScaledPixMap);
        prOSManagerButton->setIcon(prOSManagerButtonIcon);
        prOSManagerButton->setIconSize(prOSManagerButtonScaledPixMap.rect().size());
        prOSManagerButton->setFixedSize(40, 40);
        prOSManagerButton->show();

        auto *theme_matrix = new QPushButton("Matrix Theme", this);
        auto *theme_purple = new QPushButton("Purple Theme", this);
        auto *theme_blue = new QPushButton("Blue Theme", this);
        int maxButtonWidth = 100;
        int buttonHeight = 40;
        theme_matrix->setFixedSize(maxButtonWidth, buttonHeight);
        theme_purple->setFixedSize(maxButtonWidth, buttonHeight);
        theme_blue->setFixedSize(maxButtonWidth, buttonHeight);
        theme_matrix->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        theme_purple->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        theme_blue->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

        auto *dateText = new QLabel("Date", this);
        auto *timeText = new QLabel("Time", this);
        dateText->setFixedSize(maxButtonWidth, buttonHeight);
        timeText->setFixedSize(maxButtonWidth, buttonHeight);


        // Adding elements to layout :
        layout->addWidget(prOSManagerButton);
        layout->addStretch(30);
        layout->addWidget(theme_matrix);
        layout->addWidget(theme_purple);
        layout->addWidget(theme_blue);
        layout->addStretch(1);
        layout->addWidget(dateText);
        layout->addWidget(timeText);
        layout->addStretch(1);
    }

};