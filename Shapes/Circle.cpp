//
// Created by nikita on 07.02.23.
//

#include "Circle.h"

void Circle::drawNew(QPainter *painter, QPoint *Now, QPoint st, QLabel *l) {
    Start = st;
    int radius = qMin(qAbs(Now->x() - Start.x()), qAbs(Now->y() - Start.y()));
    rect = QRect(Start.x() - radius, Start.y() - radius, 2 * radius, 2 * radius);
//    qDebug() << rect.bottomLeft().x() << ' ' << rect.bottomLeft().y() << ' ' << rect.topLeft().x() << ' '
//             << rect.topLeft().y();
    painter->drawEllipse(rect);
    setSpace(l);
}

void Circle::drawPrev(QPainter *painter) {
    painter->drawEllipse(rect);
}

int Circle::countSpace() {
    return (rect.height() / 2) * (rect.height() / 2) * M_PI;
}

int Circle::countPerimeter() {
    return rect.height() * M_PI;
}

QPoint Circle::calculateCentroid() {
    return Start;
}