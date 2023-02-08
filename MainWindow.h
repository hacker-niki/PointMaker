//
// Created by nikita on 07.02.23.
//

#ifndef POINTMAKER_MAINWINDOW_H
#define POINTMAKER_MAINWINDOW_H

#include <QtWidgets>
#include "Board.h"
#include <QLabel>

class MainWindow: public QWidget{
    Q_OBJECT
    QHBoxLayout *hBoxLayout;
    QVBoxLayout *vBoxLayout;
public:
    MainWindow();
};


#endif //POINTMAKER_MAINWINDOW_H
