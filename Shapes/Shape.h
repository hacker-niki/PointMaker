//
// Created by nikita on 07.02.23.
//

#ifndef POINTMAKER_SHAPE_H
#define POINTMAKER_SHAPE_H

#include <QtWidgets>
#include <QPainter>

class Shape {


protected:
    QPolygon *polygon;
    QPoint Start;
public:
    virtual void drawNew(QPainter *painter, QPoint *Now, QPoint st, QLabel *label);

    virtual void drawPrev(QPainter *painter);

    virtual void setPoints(QPoint *Now);

    Shape();

    virtual int countSpace();
    virtual int countPerimeter();

    void setSpace(QLabel *l);

    virtual QPoint calculateCentroid();
};


#endif //POINTMAKER_SHAPE_H
