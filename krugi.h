#ifndef KRUGI_H
#define KRUGI_H
#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>



class Krugi : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Krugi(QObject *parent = 0);
    ~Krugi();
public:
    double razmer;
    int step;
    int eye;
    float x,y,h,w;
public slots:
    void put(int r, int z);
    void change_razmer(int r, int z);



protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    qreal angle;        /// Угол поворота графического объекта


};
#endif // KRUGI_H
