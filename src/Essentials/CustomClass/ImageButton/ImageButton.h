#include <QPushButton>

class ImageButton : public QPushButton {
public:
    ImageButton() = default;
    ImageButton(const QString& text, const QString& pathImage, QWidget* parent) {
        QPixmap buttonMapF(pathImage);
        QPixmap buttonMapS = buttonMapF.scaled(30, 30);
        QIcon buttonIcon(buttonMapS);
        this->setIcon(buttonIcon);
        this->setIconSize(buttonMapS.rect().size());
        this->setFixedSize(40, 40);
    }
    ImageButton(const QString& text, const QString& pathImage, const QString& style, QWidget* parent) {
        QPixmap buttonMapF(pathImage);
        QPixmap buttonMapS = buttonMapF.scaled(30, 30);
        QIcon buttonIcon(buttonMapS);
        this->setIcon(buttonIcon);
        this->setIconSize(buttonMapS.rect().size());
        this->setFixedSize(40, 40);
        this->setStyleSheet(style);
    }
};