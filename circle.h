#ifndef CIRCLE_H
#define CIRCLE_H
#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>
#include "mymy.h"



class Circle : public QObject , public Figure , public QGraphicsItem
{

    Q_OBJECT
public:
    explicit Circle(QObject *parent = 0);
    ~Circle();

public:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    double razmer;
    int step;
    int eye;
    float x,y,h,w;
    bool click;
    QColor Maincolor;
    QString  returnznach();
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

#endif // CIRCLE_H
