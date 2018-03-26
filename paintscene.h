#ifndef PAINTSCENE_H
#define PAINTSCENE_H
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QTimer>
#include <QDebug>

class paintScene : public QGraphicsScene
{

    Q_OBJECT

public:
    explicit paintScene(QObject *parent = 0);
    ~paintScene();
    float x,y,movex,movey;
    bool put ,  move;
    bool kist;
    void proverka(float &xx, float &yy, bool &add);
    void proverka2(float &xx, float &yy, bool &add);
    void kisttrue();
    void kistfalse();

private:
    QPointF     previousPoint;      // Координаты предыдущей точки

private:
    // Для рисования используем события мыши
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

};
#endif // PAINTSCENE_H
