#include <QPushButton>
#include <QPixmap>

class ImageButton : public QPushButton {
public:
    ImageButton() = default;
    ImageButton(const QString& text, const QString& pathImage, const QString& style, QWidget* parent) {
        QPixmap buttonMapF(pathImage);
        QPixmap buttonMapS = buttonMapF.scaled(30, 30);
        QIcon buttonIcon(buttonMapS);
        this->setIcon(buttonIcon);
        this->setText(text);
        this->setIconSize(buttonMapS.rect().size());
        this->setFixedSize(40, 40);
        this->setStyleSheet(style);
    }
};