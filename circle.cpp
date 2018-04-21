#include "circle.h"


Circle::Circle(QObject *parent) :
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

void Circle::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

}

Circle::~Circle()
{

}

QRectF Circle::boundingRect() const
{
    return QRectF(-100,-100,800,800);   /// Ограничиваем область, в которой лежит объект
}

void Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(!click){
        QPen(Qt::NoPen);
    }
    else{
        painter->setPen(QPen(Qt::blue,5,Qt::SolidLine, Qt::RoundCap));
    }
    painter->setBrush(Maincolor);
    painter->drawEllipse(x ,
                   y ,
                   h,
                   w);


    Q_UNUSED(option);
    Q_UNUSED(widget);
}

//получение размера из главного класса
void Circle::put(int r, int z){
    x=r;
    y=z;
    update(QRectF(-100,-100,800,800));
}

void Circle::change_razmer(int r, int z){
    h=r;
    w=z;
    update(QRectF(-100,-100,800,800));
}

void Circle::change_color(QColor color){
    Maincolor=color;
    //update(QRectF(-100,-100,800,800));
}

void Circle::clickresult(){
   // click=!click;
}
