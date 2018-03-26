#include "widget.h"
#include "circle.h"
#include "krugi.h"
#include "ui_widget.h"

Widget::Widget() :add(false),move(false), QWidget(0),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    scene = new paintScene();       // Инициализируем графическую сцену
    ui->graphicsView->setScene(scene);  // Устанавливаем графическую сцену

    timer = new QTimer();       // Инициализируем таймер
    connect(timer, &QTimer::timeout, this, &Widget::slotTimer);
    timer->start(100);          // Запускаем таймер
    timer1 = new QTimer();       // Инициализируем таймер
    connect(timer1, &QTimer::timeout, this, &Widget::addanything);
    timer1->start(15);
    kist= false;
    krugi= false;
    kvadrati= false;
    prymougol= false;
    otrezki= false;
    treugol = false;
    ovali = false;
    krug = NULL;
    krugs = NULL;
    kvadr = NULL;
    pr = NULL;

}

Widget::~Widget()
{
    delete ui;
}

void Widget::slotTimer()
{
    /* Переопределяем размеры графической сцены в зависимости
     * от размеров окна
     * */
    timer->stop();
    scene->setSceneRect(0,0, ui->graphicsView->width()-20, ui->graphicsView->height()-20 );
}

void Widget::addanything(){
    scene->proverka(x,y,add);
    scene->proverka2(movex,movey,move);
    if(add||move){
        if(ovali){
            if(add){
                Circle *alian= new Circle();
                    alian->put(x,y);
                    krug=alian;
                    scene->addItem(alian);

            }

            if(move && krug!=NULL){
               krug->change_razmer(movex-x,movey-y) ;

            }
        }
       else{
            krug = NULL;
        }
            if(krugi){
                if(add){
                    Krugi *alians= new Krugi();
                        alians->put(x,y);
                        krugs=alians;
                        scene->addItem(alians);

                }

                if(move && krugs!=NULL){
                   krugs->change_razmer(movex-x,movey-y) ;

                }
            }
            else{
                krugs = NULL;
            }
                if(kvadrati){
                     if(add){
                         Kvadr *aliankv= new Kvadr();
                             aliankv->put(x,y);
                             kvadr=aliankv;
                             scene->addItem(aliankv);

                     }

                     if(move && kvadr!=NULL){
                        kvadr->change_razmer(movex-x,movey-y) ;

                     }
                 }
                else{
                    kvadr=NULL;
                }
                if(prymougol){
                     if(add){
                         Prymougol *alianpr= new Prymougol();
                             alianpr->put(x,y);
                             pr=alianpr;
                             scene->addItem(alianpr);

                     }

                     if(move && pr!=NULL){
                        pr->change_razmer(movex-x,movey-y) ;

                     }
                 }
                else{
                    pr=NULL;
                }



    }

}



void Widget::resizeEvent(QResizeEvent *event)
{
    timer->start(100);
    QWidget::resizeEvent(event);
}



void Widget::on_kist_clicked()
{

    krugi= false;
    kvadrati= false;
    prymougol= false;
    otrezki= false;
    treugol = false;
    ovali = false;
    kist=true;
    scene->kisttrue();
}

void Widget::on_krug_clicked()
{
    krugi= true;
    kvadrati= false;
    prymougol= false;
    otrezki= false;
    treugol = false;
    ovali = false;
    kist=false;
    scene->kistfalse();
}

void Widget::on_elipse_clicked()
{
    krugi= false;
    kvadrati= false;
    prymougol= false;
    otrezki= false;
    treugol = false;
    ovali = true;
    kist=false;
    scene->kistfalse();
}

void Widget::on_kvadrat_clicked()
{
    krugi= false;
    kvadrati= true;
    prymougol= false;
    otrezki= false;
    treugol = false;
    ovali = false;
    kist=false;
    scene->kistfalse();
}

void Widget::on_prymougolnic_pressed()
{
    krugi= false;
    kvadrati= false;
    prymougol= true;
    otrezki= false;
    treugol = false;
    ovali = false;
    kist=false;
    scene->kistfalse();
}
