#include "line.h"


Line::Line(QObject *parent) :
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
}

Line::~Line()
{

}

QRectF Line::boundingRect() const
{
    return QRectF(-100,-100,800,800);   /// Ограничиваем область, в которой лежит объект
}

void Line::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //QPen(Qt::NoPen);
    painter->setBrush(Qt::red);
    //painter->SetPen(QPen(Qt::red,10,Qt::SolidLine,Qt::RoundCap));
    painter->setPen(QPen(Qt::red,5,Qt::SolidLine, Qt::RoundCap));
    painter->drawLine(x,y,x+h,y+w);

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

//получение размера из главного класса
void Line::put(int r, int z){
    x=r;
    y=z;
    update(QRectF(-100,-100,800,800));
}

void Line::change_razmer(int r, int z){
    h=r;
    w=z;
    update(QRectF(-100,-100,800,800));
}
