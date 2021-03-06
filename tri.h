#ifndef TRI_H
#define TRI_H
#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>
#include "mymy.h"


class Tri : public QObject, public QGraphicsItem, public Figure
{
    Q_OBJECT
public:
    explicit Tri(QObject *parent = 0);
    ~Tri();
public:
    double razmer;
    int step;
    int eye;
    float x,y,h,w;
    bool click;
    QColor Maincolor;
public slots:
    void put(int r, int z);
    void change_razmer(int r, int z);
    void change_color(QColor color);
    void clickresult(int usl);
    void draw(QGraphicsScene *scene);

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    qreal angle;        /// Угол поворота графического объекта


};
#endif // TRI_H
