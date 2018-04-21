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
    tre = NULL;
    line =NULL;
   /* fcircles= NULL;
    fkrugis= NULL;
    fkvadrs= NULL;
    flines= NULL;
    fpryms= NULL;
    ftris= NULL;*/
    flist = new list;
    MainColor=Qt::white;
    ui->kraska->setStyleSheet("background-color: "+MainColor.name());
}

Widget::~Widget()
{
    delete ui;
}

void Widget::funccircle(Circle* x){
    // Включение в список нового компонента
        listcircle* y = new listcircle;
        listcircle* c = new listcircle;
        c->object = x;
        c->next = NULL;
        if (flist->circles == NULL){
            flist->circles = c;
        }
        else{
            y = flist->circles;
            while( y->next != NULL){
                y = y->next;
            }
            y->next = c;
        }
}

void Widget::funckrugi(Krugi* x){
    // Включение в список нового компонента
        listkrugi* y = new listkrugi;
        listkrugi* c = new listkrugi;
        c->object = x;
        c->next = NULL;
        if (flist->krugis == NULL){
            flist->krugis = c;
        }
        else{
            y = flist->krugis;
            while( y->next != NULL){
                y = y->next;
            }
            y->next = c;
        }
}

void Widget::funckvadr(Kvadr* x){
    // Включение в список нового компонента
        listkvadr* y = new listkvadr;
        listkvadr* c = new listkvadr;
        c->object = x;
        c->next = NULL;
        if (flist->kvadrs == NULL){
            flist->kvadrs = c;
        }
        else{
            y = flist->kvadrs;
            while( y->next != NULL){
                y = y->next;
            }
            y->next = c;
        }
}

void Widget::funcline(Line* x){
    // Включение в список нового компонента
        listline* y = new listline;
        listline* c = new listline;
        c->object = x;
        c->next = NULL;
        if (flist->lines == NULL){
            flist->lines = c;
        }
        else{
            y = flist->lines;
            while( y->next != NULL){
                y = y->next;
            }
            y->next = c;
        }
}

void Widget::funcprym(Prymougol* x){
    // Включение в список нового компонента
        listprym* y = new listprym;
        listprym* c = new listprym;
        c->object = x;
        c->next = NULL;
        if (flist->pryms == NULL){
            flist->pryms = c;
        }
        else{
            y = flist->pryms;
            while( y->next != NULL){
                y = y->next;
            }
            y->next = c;
        }
}

void Widget::functri(Tri* x){
    // Включение в список нового компонента
        listtri* y = new listtri;
        listtri* c = new listtri;
        c->object = x;
        c->next = NULL;
        if (flist->tris == NULL){
            flist->tris = c;
        }
        else{
            y = flist->tris;
            while( y->next != NULL){
                y = y->next;
            }
            y->next = c;
        }
}


void Widget::slotTimer()
{
    /* Переопределяем размеры графической сцены в зависимости
     * от размеров окна
     * */
    timer->stop();
    scene->setSceneRect(0,0, ui->graphicsView->width()-20, ui->graphicsView->height()-20 );
}

void Widget::proverca_click(){

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
                    alian->change_color(MainColor);
                    funccircle(alian);
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
                        alians->change_color(MainColor);
                        funckrugi(alians);
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
                             aliankv->change_color(MainColor);
                             funckvadr(aliankv);
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
                             alianpr->change_color(MainColor);
                             funcprym(alianpr);
                             scene->addItem(alianpr);

                     }

                     if(move && pr!=NULL){
                        pr->change_razmer(movex-x,movey-y) ;

                     }
                 }
                else{
                    pr=NULL;
                }
                if(treugol){
                     if(add){
                         Tri *aliantr= new Tri();
                             aliantr->put(x,y);
                             tre=aliantr;
                             aliantr->change_color(MainColor);
                             functri(aliantr);
                             scene->addItem(aliantr);

                     }

                     if(move && tre!=NULL){
                        tre->change_razmer(movex-x,movey-y) ;

                     }
                 }
                else{
                    tre=NULL;
                }
                if(otrezki){
                     if(add){
                         Line *alianln = new Line();
                             alianln->put(x,y);
                             line=alianln;
                             alianln->change_color(MainColor);
                             funcline(alianln);
                             scene->addItem(alianln);

                     }

                     if(move && line!=NULL){
                        line->change_razmer(movex-x,movey-y) ;

                     }
                 }
                else{
                    line=NULL;
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

void Widget::on_treugolnik_clicked()
{
    krugi= false;
    kvadrati= false;
    prymougol= false;
    otrezki= false;
    treugol = true;
    ovali = false;
    kist=false;
    scene->kistfalse();
}

void Widget::on_otrezok_clicked()
{
    krugi= false;
    kvadrati= false;
    prymougol= false;
    otrezki= true;
    treugol = false;
    ovali = false;
    kist=false;
    scene->kistfalse();

}

void Widget::on_kraska_clicked()
{
    QColor color = QColorDialog::getColor(MainColor);
    if (!color.isValid() ) {
      qDebug() << "Cancel";
    }
    else{
        MainColor=color;
        scene->change_color(MainColor);
        ui->kraska->setStyleSheet("background-color: "+color.name());
    }
}

void Widget::on_klick_clicked()
{
    krugi= false;
    kvadrati= false;
    prymougol= false;
    otrezki= false;
    treugol = false;
    ovali = false;
    kist=false;
    scene->kistfalse();
}
