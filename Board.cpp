//
// Created by nikita on 07.02.23.
//

#include "Board.h"

Board::Board(QWidget *par, QLabel* la) : QWidget(par), mousePressed(false), l(la) {
    resize(par->width(), par->height());
    startTimer(20);
    setMouseTracking(true);
    currentTool = sq;
}

void Board::mousePressEvent(QMouseEvent *event) {
    mousePressed = true;
    StartMouse = event->pos();
}

void Board::mouseReleaseEvent(QMouseEvent *event) {
    mousePressed = false;
    NowMouse = event->pos();
}

void Board::mouseMoveEvent(QMouseEvent *event) {
    NowMouse = event->pos();
}

void Board::paintEvent(QPaintEvent *event) {
    auto *p = new QPainter(this);
    auto *brush = new QBrush;
    brush->setColor(QColor(100, 100, 100));
    p->setBrush(*brush);
    switch (currentTool) {
        case sq: {
            if (mousePressed)
                square.drawNew(p, &NowMouse, StartMouse, l);

            else
                square.drawPrev(p);
            break;
        }
        case rq: {
            if (mousePressed)
                rectangular.drawNew(p, &NowMouse, StartMouse, l);
            else
                rectangular.drawPrev(p);
            break;
        }
        case rd: {
            if (mousePressed)
                circle.drawNew(p, &NowMouse, StartMouse, l);
            else
                circle.drawPrev(p);
            break;
        }
    }

    p->end();
}

void Board::timerEvent(QTimerEvent *event) {
    update();
}

void Board::setSquare() { currentTool = sq; }

void Board::setRectangular() { currentTool = rq; }

void Board::setCircle() { currentTool = rd; }
