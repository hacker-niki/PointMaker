//
// Created by nikita on 07.02.23.
//

#include "Shape.h"

void Shape::setPoints(QPoint *Now) {
    if (!polygon->isEmpty())
        polygon->erase(polygon->begin(), polygon->end());
    int m = qMin(qAbs(Now->x() - Start.x()), qAbs(Now->y() - Start.y()));
    polygon->append(Start);
    polygon->append(QPoint(Start.x() + m, Start.y()));
    polygon->append(QPoint(Start.x() + m, Start.y() + m));
    polygon->append(QPoint(Start.x(), Start.y() + m));
}

void Shape::drawNew(QPainter *painter, QPoint *Now, QPoint st, QLabel *l) {
    Start = st;
    setPoints(Now);
    painter->drawPolygon(*polygon);
    setSpace(l);
}

void Shape::drawPrev(QPainter *painter) {
    painter->drawPolygon(*polygon);
}

Shape::Shape() {
    polygon = new QPolygon;
    Start = QPoint(0, 0);
}

void Shape::setSpace(QLabel *l) {
    l->setText("SPACE: " + QString::number(countSpace()) + "\nPERIMETER: " + QString::number(countPerimeter()) +
               "\nCenter x:" + QString::number(calculateCentroid().x()) + " y:" +
               QString::number(calculateCentroid().y()));
}

int Shape::countSpace() {
    int ans = 0;
    for (int i = 0; i < polygon->size() - 1; i++) {
        ans += polygon->at(i).x() * polygon->at(i + 1).y();
        ans -= polygon->at(i + 1).x() * polygon->at(i).y();
    }
    ans += polygon->at(polygon->size() - 1).x() * polygon->at(0).y();
    ans -= polygon->at(polygon->size() - 1).y() * polygon->at(0).x();
    return qAbs(ans / 2);
}

int Shape::countPerimeter() {
    int perimeter = 0;
    int pointCount = polygon->size();

    for (int i = 0; i < pointCount - 1; i++) {
        QPoint point1 = polygon->at(i);
        QPoint point2 = polygon->at(i + 1);
        int dx = point2.x() - point1.x();
        int dy = point2.y() - point1.y();
        perimeter += qSqrt(dx * dx + dy * dy);
    }
    QPoint point1 = polygon->at(pointCount - 1);
    QPoint point2 = polygon->at(0);
    int dx = point2.x() - point1.x();
    int dy = point2.y() - point1.y();
    perimeter += qSqrt(dx * dx + dy * dy);
    return perimeter;
}

QPoint Shape::calculateCentroid() {
    int sumX = 0;
    int sumY = 0;
    int area = 0;
    int pointCount = polygon->size();

    for (int i = 0; i < pointCount - 1; i++) {
        QPoint point1 = polygon->at(i);
        QPoint point2 = polygon->at(i + 1);
        int x1 = point1.x();
        int y1 = point1.y();
        int x2 = point2.x();
        int y2 = point2.y();
        int factor = x1 * y2 - x2 * y1;
        sumX += (x1 + x2) * factor;
        sumY += (y1 + y2) * factor;
        area += factor;
    }

    QPoint point1 = polygon->at(pointCount - 1);
    QPoint point2 = polygon->at(0);
    int x1 = point1.x();
    int y1 = point1.y();
    int x2 = point2.x();
    int y2 = point2.y();
    int factor = x1 * y2 - x2 * y1;
    sumX += (x1 + x2) * factor;
    sumY += (y1 + y2) * factor;
    area += factor;

    if (area == 0)
        return QPoint(0, 0);
    area /= 2;
    return QPoint(sumX / (6 * area), sumY / (6 * area));
}