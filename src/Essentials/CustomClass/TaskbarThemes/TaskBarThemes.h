#include <QPushButton>

class TaskbarThemes : public QPushButton {
public:
    TaskbarThemes() = default;
    TaskbarThemes(const QString& text, const QString& style, int w, int h, QWidget* parent) {
        this->setParent(parent);
        this->setText(text);
        this->setFixedSize(w, h);
        this->setStyleSheet(style);
    }
};