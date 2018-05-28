#ifndef MYMY_H
#define MYMY_H
#include <iostream>
#include <QGraphicsScene>
class Figure{
public:
    virtual void draw(QGraphicsScene *scene) = 0;
    virtual void put(int x,int y)= 0;
    virtual void change_color(QColor color)= 0;
    virtual void change_razmer(int r, int z)= 0;
    //QString zapis();
};

#endif // MYMY_H
