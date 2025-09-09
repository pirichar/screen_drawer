#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPoint>
#include <QPixmap>
#include <QVector>
#include "Toolbar.h"

class QLineEdit;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private slots:
    void onToolChanged(Toolbar::Tool tool);
    void onColorChanged(const QColor &color);
    void onThicknessChanged(int thickness);
    void onOpacityChanged(int opacity);
    void onFontSizeChanged(int size);
    void onUndo();
    void onClear();
    void onTextEdited();
    void onDrawModeToggled(bool enabled);

private:
    void drawLineTo(const QPoint &endPoint);
    void createTextInput(const QPoint &position);

    Toolbar *toolbar;
    bool drawing;
    QPoint lastPoint;
    QPixmap canvas;
    QVector<QPixmap> history;
    QLineEdit *textInput;

    Toolbar::Tool currentTool;
    QColor currentColor;
    int currentThickness;
    int currentOpacity;
    int currentFontSize;
    bool drawModeActive;
};

#endif // MAINWINDOW_H
