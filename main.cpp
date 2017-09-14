#include <QApplication>
#include <QDebug>

#include "Controller/controller.h"

int main(int argc, char* argv[]){

    QApplication a(argc, argv);
    Controller z;

    z.startApplication();
    return a.exec();
}










