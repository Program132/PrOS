#include <QLabel>
#include <QPixmap>
#include <QString>

class ImageLabel : public QLabel {
public:
    ImageLabel() = default;
    ImageLabel(const QString& text, const QString& pathImage, QWidget* parent) {
        this->setText(text);
        this->setParent(parent);
        QPixmap image(pathImage);
        this->setPixmap(image);
    }
};