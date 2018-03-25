#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    //QPushButton kist;
    //QObject::connect(&kist, SIGNAL(clicked()), w, SLOT(kists()));

    return a.exec();
}
