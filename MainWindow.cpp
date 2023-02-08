//
// Created by nikita on 07.02.23.
//

#include "MainWindow.h"


MainWindow::MainWindow() : QWidget() {
    resize(1000, 600);
    setMinimumSize(1000, 600);
    hBoxLayout = new QHBoxLayout;
    vBoxLayout = new QVBoxLayout;
    auto *label = new QLabel;
    auto *board = new Board(this, label);
    hBoxLayout->addWidget(board, 2);
    setLayout(hBoxLayout);

    auto *square = new QPushButton("Square");
    vBoxLayout->addWidget(square);
    auto *rectangular = new QPushButton("Rect");
    vBoxLayout->addWidget(rectangular);
    auto *circle = new QPushButton("Circle");
    vBoxLayout->addWidget(circle);
    vBoxLayout->addWidget(label);

    connect(square, SIGNAL(clicked(bool)), board, SLOT(setSquare()));
    connect(rectangular, SIGNAL(clicked(bool)), board, SLOT(setRectangular()));
    connect(circle, SIGNAL(clicked(bool)), board, SLOT(setCircle()));


    hBoxLayout->addLayout(vBoxLayout);
}
