//
// Created by nikita on 07.02.23.
//

#ifndef POINTMAKER_BOARD_H
#define POINTMAKER_BOARD_H

#include <QtWidgets>
#include "Shapes/Shape.h"
#include "Shapes/Square.h"
#include "Shapes/Rectangular.h"
#include "Shapes/Circle.h"

class Board : public QWidget {
Q_OBJECT
public:
    explicit Board(QWidget *par, QLabel *la);

    bool mousePressed;

    QPoint StartMouse;
    QPoint NowMouse;
    Rectangular rectangular;
    Square square;
    Circle circle;
    QLabel *l;

    enum Tools {
        sq, rq, rd, el, st5, st6, st7, st8
    };

    short int currentTool;

    void mousePressEvent(QMouseEvent *event) override;

    void mouseReleaseEvent(QMouseEvent *event) override;

    void mouseMoveEvent(QMouseEvent *event) override;

    void paintEvent(QPaintEvent *event) override;

    void timerEvent(QTimerEvent *event) override;

public slots:

    void setSquare();

    void setRectangular();

    void setCircle();

};


#endif //POINTMAKER_BOARD_H
