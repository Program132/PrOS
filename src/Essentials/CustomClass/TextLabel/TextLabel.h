#include <QLabel>

class TextLabel : public QLabel {
public:
    TextLabel() = default;
    TextLabel(const QString& text, const QString& style, int w, int h, QWidget* parent) {
        this->setParent(parent);
        this->setText(text);
        this->setFixedSize(w, h);
        this->setStyleSheet(style);
    }

    TextLabel(const QString& text, const QString& style, int w, int h, Qt::Alignment allign ,QWidget* parent) {
        this->setParent(parent);
        this->setText(text);
        this->setFixedSize(w, h);
        this->setStyleSheet(style);
        this->setAlignment(allign);
    }
};