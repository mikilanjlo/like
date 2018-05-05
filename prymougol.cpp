#include "prymougol.h"


Prymougol::Prymougol(QObject *parent) :
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

Prymougol::~Prymougol()
{

}

QRectF Prymougol::boundingRect() const
{
    return QRectF(-100,-100,800,800);   /// Ограничиваем область, в которой лежит объект
}

void Prymougol::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(!click){
        QPen(Qt::NoPen);
    }
    else{
        painter->setPen(QPen(Qt::blue,3,Qt::SolidLine, Qt::RoundCap));
    }
    painter->setBrush(Maincolor);
    painter->drawRect(x ,
                   y ,
                   h,
                   w);


    Q_UNUSED(option);
    Q_UNUSED(widget);
}

//получение размера из главного класса
void Prymougol::put(int r, int z){
    x=r;
    y=z;
    update(QRectF(-100,-100,800,800));
}

void Prymougol::change_razmer(int r, int z){
    h=r;
    w=z;
    update(QRectF(-100,-100,800,800));
}

void Prymougol::change_color(QColor color){
    Maincolor=color;
}

void Prymougol::clickresult(int usl){
    if (usl == 2){
        click=!click;
    }
    if (usl == 0){
        click = false;
    }
}
