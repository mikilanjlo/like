#include "kvadr.h"


Kvadr::Kvadr(QObject *parent) :
    QObject(parent), QGraphicsItem()
{
    angle = 0;      // Задаём угол поворота графического объекта
    setRotation(angle);     // Устанавливаем угол поворота графического объекта
    razmer=27;
    step=-1;// сторона рисунка
    eye=2;
    x=0;
    y=0;
    h=0;
    w=0;
    click=false;
    Maincolor = Qt::red;
}

Kvadr::~Kvadr()
{

}

QRectF Kvadr::boundingRect() const
{
    return QRectF(-100,-100,800,800);   /// Ограничиваем область, в которой лежит объект
}

void Kvadr::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen(Qt::NoPen);
    painter->setBrush(Maincolor);
    painter->drawRect(x ,
                   y ,
                   h,
                   w);


    Q_UNUSED(option);
    Q_UNUSED(widget);
}

//получение размера из главного класса
void Kvadr::put(int r, int z){
    x=r;
    y=z;
    update(QRectF(-100,-100,800,800));
}

void Kvadr::change_razmer(int r, int z){
    h=(r+z)/2;
    w=(r+z)/2;
    update(QRectF(-100,-100,800,800));
}

void Kvadr::change_color(QColor color){
    Maincolor=color;
}
