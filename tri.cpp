#include "tri.h"


Tri::Tri(QObject *parent) :
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
    Maincolor = Qt::red;
}

Tri::~Tri()
{

}

QRectF Tri::boundingRect() const
{
    return QRectF(-100,-100,800,800);   /// Ограничиваем область, в которой лежит объект
}

void Tri::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen(Qt::NoPen);
    painter->setBrush(Maincolor);
    QPolygon polygon;   /// Используем класс полигона, чтобы отрисовать треугольник
    /// Помещаем координаты точек в полигональную модель
    polygon << QPoint(x,y) << QPoint(x,y+h) << QPoint(x+w,y+h);
    painter->drawPolygon(polygon);

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

//получение размера из главного класса
void Tri::put(int r, int z){
    x=r;
    y=z;
    update(QRectF(-100,-100,800,800));
}

void Tri::change_razmer(int r, int z){
    h=z;
    w=r;
    update(QRectF(-100,-100,800,800));
}

void Tri::change_color(QColor color){
    Maincolor=color;
}
