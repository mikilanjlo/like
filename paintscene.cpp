#include "paintscene.h"


paintScene::paintScene(QObject *parent) : QGraphicsScene(parent)
{

}

paintScene::~paintScene()
{

}

void paintScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    // При нажатии кнопки мыши отрисовываем эллипс
    /*addEllipse(event->scenePos().x() - 5,
               event->scenePos().y() - 5,
               10,
               10,
               QPen(Qt::NoPen),
               QBrush(Qt::red));
    // Сохраняем координаты точки нажатия
    previousPoint = event->scenePos();*/

   /* Circle *alian= new Circle();
    alian->change_razmer(event->scenePos().x() - 5,
                         event->scenePos().y() - 5);
    addItem(alian);
    */
    x=event->scenePos().x();
    y=event->scenePos().y();
    put=true;
}

void paintScene::proverka(float &xx, float &yy,bool &add){
    if(put){
        xx=x;
        yy=y;
        add=put;
        put=!put;
    }

}

void paintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    // Отрисовываем линии с использованием предыдущей координаты
   /* addLine(previousPoint.x(),
            previousPoint.y(),
            event->scenePos().x(),
            event->scenePos().y(),
            QPen(Qt::red,10,Qt::SolidLine,Qt::RoundCap));
    // Обновляем данные о предыдущей координате
    previousPoint = event->scenePos();*/
}
