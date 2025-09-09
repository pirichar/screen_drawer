#ifndef TOOLBAR_H
#define TOOLBAR_H

#include <QWidget>
#include <QColor>

class QPushButton;
class QSlider;
class QSpinBox;
class QColorDialog;

class Toolbar : public QWidget
{
    Q_OBJECT

public:
    explicit Toolbar(QWidget *parent = nullptr);

    enum Tool { Pen, Text, Eraser };

signals:
    void toolChanged(Tool tool);
    void colorChanged(const QColor &color);
    void thicknessChanged(int thickness);
    void opacityChanged(int opacity);
    void fontSizeChanged(int size);
    void undoTriggered();
    void clearTriggered();

private slots:
    void selectPen();
    void selectText();
    void selectEraser();
    void openColorDialog();

private:
    QPushButton *penButton;
    QPushButton *textButton;
    QPushButton *eraserButton;
    QPushButton *colorButton;
    QSlider *thicknessSlider;
    QSlider *opacitySlider;
    QSpinBox *fontSizeSpinBox;
    QPushButton *undoButton;
    QPushButton *clearButton;
    QColorDialog *colorDialog;

    QColor currentColor;
};

#endif // TOOLBAR_H
