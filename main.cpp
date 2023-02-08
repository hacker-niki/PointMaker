#include <QApplication>
#include <QPushButton>
#include "MainWindow.h"
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow *win = new MainWindow;
    win->show();
    return QApplication::exec();
}
