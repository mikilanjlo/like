#ifndef PRYMOUGOL_H
#define PRYMOUGOL_H
#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>



class Prymougol : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Prymougol(QObject *parent = 0);
    ~Prymougol();
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


protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    qreal angle;        /// Угол поворота графического объекта


};
#endif // PRYMOUGOL_H
