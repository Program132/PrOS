#include <QPushButton>

class TaskbarThemes : public QPushButton {
public:
    TaskbarThemes() = default;
    TaskbarThemes(const QString& text, const QString& style, int w, int h, QWidget* parent) {
        this->setParent(parent);
        this->setText(text);
        this->setFixedSize(w, h);
        this->setStyleSheet(style);
        this->normalStyle = style;
        this->pressedStyle = style;
    }

    TaskbarThemes(const QString& text, const QString& style, const QString& pressedStyle, int w, int h, QWidget* parent) {
        this->setParent(parent);
        this->setText(text);
        this->setFixedSize(w, h);
        this->setStyleSheet(style);
        this->normalStyle = style;
        this->pressedStyle = pressedStyle;
    }

protected:
    void mousePressEvent(QMouseEvent* event) override {
        QPushButton::mousePressEvent(event);
        setStyleSheet(pressedStyle);
    }

    void mouseReleaseEvent(QMouseEvent* event) override {
        QPushButton::mouseReleaseEvent(event);
        setStyleSheet(normalStyle);
    }

private:
    QString normalStyle;
    QString pressedStyle;
};