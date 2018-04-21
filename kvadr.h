#ifndef KVADR_H
#define KVADR_H
#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>



class Kvadr : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Kvadr(QObject *parent = 0);
    ~Kvadr();
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


protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    qreal angle;        /// Угол поворота графического объекта


};
#endif // KVADR_H
