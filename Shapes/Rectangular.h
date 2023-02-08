//
// Created by nikita on 07.02.23.
//

#ifndef POINTMAKER_RECTANGULAR_H
#define POINTMAKER_RECTANGULAR_H

#include "Square.h"

class Rectangular: public Square{
public:
    void setPoints(QPoint *Now) override;
};


#endif //POINTMAKER_RECTANGULAR_H
