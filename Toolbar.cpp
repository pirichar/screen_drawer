#include "Toolbar.h"
#include <QHBoxLayout>
#include <QPushButton>
#include <QSlider>
#include <QSpinBox>
#include <QColorDialog>
#include <QColor>

Toolbar::Toolbar(QWidget *parent) : QWidget(parent), currentColor(Qt::red)
{
    setWindowFlags(Qt::WindowStaysOnTopHint | Qt::Tool);
    setWindowTitle("ScreenDraw Toolbar");

    QHBoxLayout *layout = new QHBoxLayout(this);

    penButton = new QPushButton("Pen", this);
    penButton->setCheckable(true);
    penButton->setChecked(true);
    connect(penButton, &QPushButton::clicked, this, &Toolbar::selectPen);
    layout->addWidget(penButton);

    textButton = new QPushButton("Text", this);
    textButton->setCheckable(true);
    connect(textButton, &QPushButton::clicked, this, &Toolbar::selectText);
    layout->addWidget(textButton);

    eraserButton = new QPushButton("Eraser", this);
    eraserButton->setCheckable(true);
    connect(eraserButton, &QPushButton::clicked, this, &Toolbar::selectEraser);
    layout->addWidget(eraserButton);

    colorButton = new QPushButton("Color", this);
    connect(colorButton, &QPushButton::clicked, this, &Toolbar::openColorDialog);
    layout->addWidget(colorButton);

    thicknessSlider = new QSlider(Qt::Horizontal, this);
    thicknessSlider->setRange(1, 20);
    thicknessSlider->setValue(5);
    connect(thicknessSlider, &QSlider::valueChanged, this, &Toolbar::thicknessChanged);
    layout->addWidget(thicknessSlider);

    opacitySlider = new QSlider(Qt::Horizontal, this);
    opacitySlider->setRange(0, 255);
    opacitySlider->setValue(255);
    connect(opacitySlider, &QSlider::valueChanged, this, &Toolbar::opacityChanged);
    layout->addWidget(opacitySlider);

    fontSizeSpinBox = new QSpinBox(this);
    fontSizeSpinBox->setRange(8, 72);
    fontSizeSpinBox->setValue(16);
    connect(fontSizeSpinBox, QOverload<int>::of(&QSpinBox::valueChanged), this, &Toolbar::fontSizeChanged);
    layout->addWidget(fontSizeSpinBox);

    undoButton = new QPushButton("Undo", this);
    connect(undoButton, &QPushButton::clicked, this, &Toolbar::undoTriggered);
    layout->addWidget(undoButton);

    clearButton = new QPushButton("Clear", this);
    connect(clearButton, &QPushButton::clicked, this, &Toolbar::clearTriggered);
    layout->addWidget(clearButton);

    setLayout(layout);
}

void Toolbar::selectPen()
{
    penButton->setChecked(true);
    textButton->setChecked(false);
    eraserButton->setChecked(false);
    emit toolChanged(Pen);
}

void Toolbar::selectText()
{
    penButton->setChecked(false);
    textButton->setChecked(true);
    eraserButton->setChecked(false);
    emit toolChanged(Text);
}

void Toolbar::selectEraser()
{
    penButton->setChecked(false);
    textButton->setChecked(false);
    eraserButton->setChecked(true);
    emit toolChanged(Eraser);
}

void Toolbar::openColorDialog()
{
    QColor newColor = QColorDialog::getColor(currentColor, this, "Select Color");
    if (newColor.isValid()) {
        currentColor = newColor;
        emit colorChanged(currentColor);
    }
}
