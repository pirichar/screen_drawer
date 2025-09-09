#include "MainWindow.h"
#include <QGuiApplication>
#include <QScreen>
#include <QPainter>
#include <QMouseEvent>
#include <QLineEdit>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), drawing(false), textInput(nullptr), currentTool(Toolbar::Pen), currentColor(Qt::red), currentThickness(5), currentOpacity(255), currentFontSize(16), drawModeActive(false)
{
    // Make the window fullscreen, borderless, transparent, and stay on top
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::WindowDoesNotAcceptFocus | Qt::WindowTransparentForInput);
    setAttribute(Qt::WA_TranslucentBackground);
    setAttribute(Qt::WA_NoSystemBackground);
    setAttribute(Qt::WA_ShowWithoutActivating);
    setGeometry(QGuiApplication::primaryScreen()->geometry());
    
    qDebug() << "MainWindow created with geometry:" << geometry();

    // Initialize the canvas
    canvas = QPixmap(size());
    canvas.fill(Qt::transparent);

    // Create and show the toolbar
    toolbar = new Toolbar();
    connect(toolbar, &Toolbar::toolChanged, this, &MainWindow::onToolChanged);
    connect(toolbar, &Toolbar::colorChanged, this, &MainWindow::onColorChanged);
    connect(toolbar, &Toolbar::thicknessChanged, this, &MainWindow::onThicknessChanged);
    connect(toolbar, &Toolbar::opacityChanged, this, &MainWindow::onOpacityChanged);
    connect(toolbar, &Toolbar::fontSizeChanged, this, &MainWindow::onFontSizeChanged);
    connect(toolbar, &Toolbar::undoTriggered, this, &MainWindow::onUndo);
    connect(toolbar, &Toolbar::clearTriggered, this, &MainWindow::onClear);
    connect(toolbar, &Toolbar::drawModeToggled, this, &MainWindow::onDrawModeToggled);
    toolbar->show();

    history.push_back(canvas);
}

MainWindow::~MainWindow()
{
    delete toolbar;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, canvas);
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "Mouse press event at:" << event->pos() << "Tool:" << currentTool << "Draw mode:" << drawModeActive;
    
    if (event->button() == Qt::LeftButton && drawModeActive) {
        if (currentTool == Toolbar::Pen || currentTool == Toolbar::Eraser) {
            lastPoint = event->pos();
            drawing = true;
            history.push_back(canvas);
            qDebug() << "Started drawing at:" << lastPoint;
        } else if (currentTool == Toolbar::Text) {
            createTextInput(event->pos());
        }
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if ((event->buttons() & Qt::LeftButton) && drawing && drawModeActive) {
        qDebug() << "Drawing line to:" << event->pos();
        drawLineTo(event->pos());
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && drawing && drawModeActive) {
        drawing = false;
    }
}

void MainWindow::onToolChanged(Toolbar::Tool tool)
{
    currentTool = tool;
}

void MainWindow::onColorChanged(const QColor &color)
{
    currentColor = color;
}

void MainWindow::onThicknessChanged(int thickness)
{
    currentThickness = thickness;
}

void MainWindow::onOpacityChanged(int opacity)
{
    currentOpacity = opacity;
}

void MainWindow::onFontSizeChanged(int size)
{
    currentFontSize = size;
}

void MainWindow::onUndo()
{
    if (history.size() > 1) {
        history.pop_back();
        canvas = history.last();
        update();
    }
}

void MainWindow::onClear()
{
    history.push_back(canvas);
    canvas.fill(Qt::transparent);
    update();
}

void MainWindow::drawLineTo(const QPoint &endPoint)
{
    QPainter painter(&canvas);
    QPen pen(currentColor);
    pen.setCapStyle(Qt::RoundCap);
    pen.setWidth(currentThickness);

    if (currentTool == Toolbar::Eraser) {
        painter.setCompositionMode(QPainter::CompositionMode_Clear);
        pen.setColor(Qt::transparent);
    } else {
        QColor color = currentColor;
        color.setAlpha(currentOpacity);
        pen.setColor(color);
    }

    painter.setPen(pen);
    painter.drawLine(lastPoint, endPoint);
    lastPoint = endPoint;
    update();
}

void MainWindow::createTextInput(const QPoint &position)
{
    if (textInput) {
        onTextEdited();
    }
    history.push_back(canvas);
    textInput = new QLineEdit(this);
    textInput->move(position);
    textInput->setFixedSize(200, 30);
    textInput->setStyleSheet("background-color: white;");
    connect(textInput, &QLineEdit::editingFinished, this, &MainWindow::onTextEdited);
    textInput->show();
    textInput->setFocus();
}

void MainWindow::onTextEdited()
{
    if (!textInput) return;

    QPainter painter(&canvas);
    QFont font;
    font.setPointSize(currentFontSize);
    painter.setFont(font);

    QColor color = currentColor;
    color.setAlpha(currentOpacity);
    painter.setPen(color);

    painter.drawText(textInput->geometry().bottomLeft(), textInput->text());

    textInput->deleteLater();
    textInput = nullptr;
    update();
}

void MainWindow::onDrawModeToggled(bool enabled)
{
    drawModeActive = enabled;
    qDebug() << "Draw mode toggled to:" << enabled;
    
    if (enabled) {
        // When draw mode is enabled, make sure the window stays on top and can receive mouse events
        setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
        setAttribute(Qt::WA_TranslucentBackground);
        show();
        raise();
        activateWindow();
    } else {
        // When disabled, make it non-interactive but still visible
        setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::WindowDoesNotAcceptFocus);
        setAttribute(Qt::WA_TranslucentBackground);
        setAttribute(Qt::WA_ShowWithoutActivating);
        show();
    }
}

