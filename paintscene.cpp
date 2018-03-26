#include "paintscene.h"


paintScene::paintScene(QObject *parent) :move(false), put(false),kist(false), QGraphicsScene(parent)
{

}

paintScene::~paintScene()
{

}

void paintScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(kist){
        // При нажатии кнопки мыши отрисовываем эллипс
        addEllipse(event->scenePos().x() - 5,
                   event->scenePos().y() - 5,
                   10,
                   10,
                   QPen(Qt::NoPen),
                   QBrush(Qt::red));
        // Сохраняем координаты точки нажатия
        previousPoint = event->scenePos();
    }else{

   /* Circle *alian= new Circle();
    alian->change_razmer(event->scenePos().x() - 5,
                         event->scenePos().y() - 5);
    addItem(alian);
    */

        move=!move;
        x=event->scenePos().x();
        y=event->scenePos().y();
        put=true;}

}

void paintScene::proverka(float &xx, float &yy,bool &add){
    add=put;
    if(put){
        xx=x;
        yy=y;

        put=!put;
    }


}

void paintScene::kistfalse(){

    kist=false;
}
void paintScene::kisttrue(){

    kist=true;
}

void paintScene::proverka2(float &xx, float &yy,bool &add){
    if(move){
        xx=movex;
        yy=movey;

    }
    add=move;

}

void paintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    // Отрисовываем линии с использованием предыдущей координаты
    if(kist){
        addLine(previousPoint.x(),
                previousPoint.y(),
                event->scenePos().x(),
                event->scenePos().y(),
                QPen(Qt::red,10,Qt::SolidLine,Qt::RoundCap));
        // Обновляем данные о предыдущей координате
        previousPoint = event->scenePos();
    }
    else{
        movex=event->scenePos().x();
        movey=event->scenePos().y();
        move=true;
    }
}
