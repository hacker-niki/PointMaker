//
// Created by nikita on 07.02.23.
//

#ifndef POINTMAKER_CIRCLE_H
#define POINTMAKER_CIRCLE_H

#include "Shape.h"
#include <QDebug>

class Circle: public Shape{
private:
    QRect rect;
public:
    void drawNew(QPainter *painter, QPoint *Now, QPoint st, QLabel* l) override;
    void drawPrev(QPainter *painter) override;
    int countSpace() override;
    int countPerimeter() override;
    QPoint calculateCentroid() override;
};


#endif //POINTMAKER_CIRCLE_H
