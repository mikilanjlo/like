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
    click = false;
    krug = NULL;
    krugs = NULL;
    kvadr = NULL;
    pr = NULL;
    tre = NULL;
    line =NULL;
    Circlename = 0;
    Kruginame = 0;
    Kvadrname = 0;
    Linename = 0;
    Prymname = 0;
    Triname = 0;
    flist = new list;
    flist->circles=NULL;
    flist->krugis=NULL;
    flist->kvadrs=NULL;
    flist->lines=NULL;
    flist->pryms=NULL;
    flist->tris=NULL;
    ylist = new list;
    ylist->circles=NULL;
    ylist->krugis=NULL;
    ylist->kvadrs=NULL;
    ylist->lines=NULL;
    ylist->pryms=NULL;
    ylist->tris=NULL;
    headbut=NULL;
    MainColor=Qt::white;
    ui->kraska->setStyleSheet("background-color: "+MainColor.name());
    keyCtrlZ = new QShortcut(this);   // Инициализируем объект
        keyCtrlZ->setKey(Qt::CTRL + Qt::Key_Z);    // Устанавливаем код клавиши
        // цепляем обработчик нажатия клавиши
        connect(keyCtrlZ, SIGNAL(activated()), this, SLOT(nazad()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::nazad(){
    if(headbut != NULL){
        buttons *b = new buttons;
        buttons *predb = new buttons;
        b = headbut;
        while(b->next != NULL){
            predb=b;
            b = b->next;
        }
        namebut = b->but->text();
        QStringList lst = namebut.split("_");
        QString str = lst.at(1);
        int count = str.toInt();
        if(lst.at(0) == "Treugolnig"){
           if(count == 0){
                ylist->tris = flist->tris;
                scene->removeItem(flist->tris->object);
                flist->tris = NULL;

            }
            else{
                listtri *y = new listtri;
                listtri *del = new listtri;
                y = flist->tris;
                for(int i = 0; i < count; i++){
                  del = y;
                  y = y->next;
                }
                ylist->tris = y;
                scene->removeItem(y->object);
                del->next = NULL;

            }
           Triname--;
        }
        if(lst.at(0) == "Pryamougolnick"){
            if(count == 0){
                 ylist->pryms = flist->pryms;
                 scene->removeItem(flist->pryms->object);
                 flist->pryms = NULL;

             }
             else{
                 listprym *y = new listprym;
                 listprym *del = new listprym;
                 y = flist->pryms;
                 for(int i = 0; i < count; i++){
                   del = y;
                   y = y->next;
                 }
                 ylist->pryms = y;
                 scene->removeItem(y->object);
                 del->next = NULL;

             }
            Prymname--;
        }
        if(lst.at(0) == "Krug"){
            if(count == 0){
                 ylist->krugis = flist->krugis;
                 scene->removeItem(flist->krugis->object);
                 flist->krugis = NULL;

             }
             else{
                 listkrugi *y = new listkrugi;
                 listkrugi *del = new listkrugi;
                 y = flist->krugis;
                 for(int i = 0; i < count; i++){
                   del = y;
                   y = y->next;
                 }
                 ylist->krugis = y;
                 scene->removeItem(y->object);
                 del->next = NULL;

             }
            Kruginame--;
        }
        if(lst.at(0) == "Liniya"){
            if(count == 0){
                 ylist->lines = flist->lines;
                 scene->removeItem(flist->lines->object);
                 flist->lines = NULL;

             }
             else{
                 listline *y = new listline;
                 listline *del = new listline;
                 y = flist->lines;
                 for(int i = 0; i < count; i++){
                   del = y;
                   y = y->next;
                 }
                 ylist->lines = y;
                 scene->removeItem(y->object);
                 del->next = NULL;

             }
            Linename--;
        }
        if(lst.at(0) == "Kvadrat"){
            if(count == 0){
                 ylist->kvadrs = flist->kvadrs;
                 scene->removeItem(flist->kvadrs->object);
                 flist->kvadrs = NULL;

             }
             else{
                 listkvadr *y = new listkvadr;
                 listkvadr *del = new listkvadr;
                 y = flist->kvadrs;
                 for(int i = 0; i < count; i++){
                   del = y;
                   y = y->next;
                 }
                 ylist->kvadrs = y;
                 scene->removeItem(y->object);
                 del->next = NULL;

             }
            Kvadrname--;
        }
        if(lst.at(0) == "Oval"){
            if(count == 0){
                 ylist->circles = flist->circles;
                 scene->removeItem(flist->circles->object);
                 flist->circles = NULL;

             }
             else{
                 listcircle *y = new listcircle;
                 listcircle *del = new listcircle;
                 y = flist->circles;
                 for(int i = 0; i < count; i++){
                   del = y;
                   y = y->next;
                 }
                 ylist->circles = y;
                 scene->removeItem(y->object);
                 del->next = NULL;

             }
            Circlename--;

        }
        if(headbut->next != NULL){
            b->but->deleteLater();
            predb->next = NULL;
            delete b;
        }
        else{
           b->but->deleteLater();
           headbut =NULL;
           delete b;
        }
    }

}

void Widget::funccircle(Circle* x){
    // Включение в список нового компонента
        listcircle* y = new listcircle;
        listcircle* c = new listcircle;
        c->object = x;
        c->next = NULL;
        c->name = Circlename;
        create_button(QString("Oval"),c->name);
        Circlename++;

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
        c->name = Kruginame;
        create_button(QString("Krug"),c->name);
        Kruginame++;
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
        c->name = Kvadrname;
        create_button(QString("Kvadrat"),c->name);
        Kvadrname++;
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
        c->name = Linename;
        create_button(QString("Liniya"),c->name);
        Linename++;
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
        c->name = Prymname;
        create_button(QString("Pryamougolnick"),c->name);
        Prymname++;
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
        c->name = Triname;
        create_button(QString("Treugolnig"),c->name);
        Triname++;
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
    buttons* by = new buttons;
    by = headbut;
    while( by != NULL)  {
        if(by->but->isChecked()){
            namebut = by->but->text();

            click_my_button();
            break;
        }
        by = by->next;
    }
    by = headbut;
    while( by != NULL)  {
        by->but->setChecked(false);
        by = by->next;
    }
}

void Widget::create_button(QString s, int x){
    QPushButton *button = new QPushButton(s+QString("_")+QString::number(x), ui->scrollAreaWidgetContents);

      // устанавливаем размер и положение кнопки
      button->setGeometry(QRect(QPoint(0, 50*(Circlename+Kruginame+Kvadrname+Linename+Prymname+Triname)),
      QSize(150, 50)));
      //ui->scrollArea->setWidget(button);
      if(50*(Circlename+Kruginame+Kvadrname+Linename+Prymname+Triname)>=ui->scrollAreaWidgetContents->height()){
        ui->scrollAreaWidgetContents->resize(ui->scrollAreaWidgetContents->width(),50*(Circlename+Kruginame+Kvadrname+Linename+Prymname+Triname+1));
      }
      //QObject::connect(button,SIGNAL(pressed()),button,SLOT(setEnabled(bool=false)));
      //connect(button,SIGNAL(clicked(bool)),this,SLOT(click_my_button()));
      // ui->verticalLayout_3->addWidget(button);
      button->setVisible(true);
      button->setCheckable(true);
      button->setChecked(false);
      buttons* b = new buttons;
      buttons* by = new buttons;
      b->but = button;
      b->next = NULL;
      if (headbut == NULL){
          headbut = b;
      }
      else{
          by = headbut;
          while( by->next != NULL){
              by = by->next;
          }
          by->next = b;
      }
}

void Widget::deleteborder(){


        if(krug!=NULL){
           krug->clickresult(0);
        }
        if(krugs!=NULL){
           krugs->clickresult(0);
        }
        if(pr!=NULL){
           pr->clickresult(0);
        }
        if(tre!=NULL){
           tre->clickresult(0);
        }
        if(kvadr!=NULL){
           kvadr->clickresult(0);
        }
        if(line!=NULL){
           line->clickresult(0);
        }


}

void Widget::click_my_button(){
    deleteborder();
    QStringList lst = namebut.split("_");
    QString str = lst.at(1);
    int count = str.toInt();
    if(lst.at(0) == "Treugolnig"){
        ui->treugolnik->click();
        if(count == 0){
            tre = flist->tris->object;
        }
        else{
            listtri *y = new listtri;
            y = flist->tris;
            for(int i = 0; i < count; i++){
              y = y->next;
            }
            tre = y->object;
        }
        tre->clickresult(2);



    }
    if(lst.at(0) == "Pryamougolnick"){
        ui->prymougolnic->click();
        if(count == 0){
            pr = flist->pryms->object;
        }
        else{
            listprym *y = new listprym;
            y = flist->pryms;
            for(int i = 0; i < count; i++){
              y = y->next;
            }
            pr = y->object;
        }
        pr->clickresult(2);
    }
    if(lst.at(0) == "Krug"){
        ui->krug->click();
        if(count == 0){
            krugs = flist->krugis->object;
        }
        else{
            listkrugi *y = new listkrugi;
            y = flist->krugis;
            for(int i = 0; i < count; i++){
              y = y->next;
            }
            krugs = y->object;
        }
        krugs->clickresult(2);
    }
    if(lst.at(0) == "Liniya"){
        ui->otrezok->click();
        if(count == 0){
            line = flist->lines->object;
        }
        else{
            listline *y = new listline;
            y = flist->lines;
            for(int i = 0; i < count; i++){
              y = y->next;
            }
            line = y->object;
        }
        line->clickresult(2);
    }
    if(lst.at(0) == "Kvadrat"){
        ui->kvadrat->click();
        if(count == 0){
            kvadr = flist->kvadrs->object;
        }
        else{
            listkvadr *y = new listkvadr;
            y = flist->kvadrs;
            for(int i = 0; i < count; i++){
              y = y->next;
            }
            kvadr = y->object;
        }
        kvadr->clickresult(2);
    }
    if(lst.at(0) == "Oval"){
        ui->elipse->click();
        if(count == 0){
            krug = flist->circles->object;
        }
        else{
            listcircle *y = new listcircle;
            y = flist->circles;
            for(int i = 0; i < count; i++){
              y = y->next;
            }
            krug = y->object;
        }
        krug->clickresult(2);

    }

    click = true;
}

void Widget::addanything(){
    proverca_click();
    if(true/*!click*/){
        scene->proverka(x,y,add);
        scene->proverka2(movex,movey,move);

        if(add||move){
            if(ovali){

                if(add){
                    if(!click){
                        deleteY();
                    Circle *alian= new Circle();
                        alian->put(x,y);
                        krug=alian;
                        alian->change_color(MainColor);
                        funccircle(alian);
                        scene->addItem(alian);
                    }
                    else{ 
                        krug->put(x,y);
                    }


                }
                if(click)
                    krug->change_color(MainColor);

                if(move && krug!=NULL){
                   krug->change_razmer(movex-x,movey-y) ;

                }
            }
           else{
                krug = NULL;
            }
                if(krugi){
                    if(add){
                        if(!click){
                            deleteY();
                        Krugi *alians= new Krugi();
                            alians->put(x,y);
                            krugs=alians;
                            alians->change_color(MainColor);
                            funckrugi(alians);
                            scene->addItem(alians);
                        }
                        else{
                            krugs->put(x,y);
                        }

                    }
                    if(click)
                        krugs->change_color(MainColor);

                    if(move && krugs!=NULL){
                       krugs->change_razmer(movex-x,movey-y) ;

                    }
                }
                else{
                    krugs = NULL;
                }
                    if(kvadrati){
                         if(add){
                             if(!click){
                                 deleteY();
                             Kvadr *aliankv= new Kvadr();
                                 aliankv->put(x,y);
                                 kvadr=aliankv;
                                 aliankv->change_color(MainColor);
                                 funckvadr(aliankv);
                                 scene->addItem(aliankv);
                             }
                             else{
                                 kvadr->put(x,y);
                             }

                         }
                         if(click)
                             kvadr->change_color(MainColor);

                         if(move && kvadr!=NULL){
                            kvadr->change_razmer(movex-x,movey-y) ;

                         }
                     }
                    else{
                        kvadr=NULL;
                    }
                    if(prymougol){
                         if(add){
                             if(!click){
                                 deleteY();
                             Prymougol *alianpr= new Prymougol();
                                 alianpr->put(x,y);
                                 pr=alianpr;
                                 alianpr->change_color(MainColor);
                                 funcprym(alianpr);
                                 scene->addItem(alianpr);
                             }
                             else{
                                 pr->put(x,y);
                             }

                         }
                         if(click)
                             pr->change_color(MainColor);

                         if(move && pr!=NULL){
                            pr->change_razmer(movex-x,movey-y) ;

                         }
                     }
                    else{
                        pr=NULL;
                    }
                    if(treugol){

                         if(add){
                             if(!click){
                                 deleteY();
                                 Tri *aliantr= new Tri();
                                     aliantr->put(x,y);
                                     tre=aliantr;
                                     aliantr->change_color(MainColor);
                                     functri(aliantr);
                                     scene->addItem(aliantr);
                             }
                             else{
                                 tre->put(x,y);
                             }

                         }
                         if(click)
                             tre->change_color(MainColor);

                         if(move && tre!=NULL){
                            tre->change_razmer(movex-x,movey-y) ;

                         }
                     }
                    else{
                        tre=NULL;
                    }
                    if(otrezki){
                         if(add){
                             if(!click){
                                 deleteY();
                             Line *alianln = new Line();
                                 alianln->put(x,y);
                                 line=alianln;
                                 alianln->change_color(MainColor);
                                 funcline(alianln);
                                 scene->addItem(alianln);
                             }
                             else{
                                 line->put(x,y);
                             }

                         }
                         if(click)
                             line->change_color(MainColor);

                         if(move && line!=NULL){
                            line->change_razmer(movex-x,movey-y) ;

                         }
                     }
                    else{
                        line=NULL;
                    }


        }
    }

}

void Widget::deleteY(){
    ylist->circles=NULL;
    ylist->krugis=NULL;
    ylist->kvadrs=NULL;
    ylist->lines=NULL;
    ylist->pryms=NULL;
    ylist->tris=NULL;
}

void Widget::resizeEvent(QResizeEvent *event)
{
    timer->start(100);
    QWidget::resizeEvent(event);
}



void Widget::on_kist_clicked()
{
    deleteborder();
    click=false;
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
    deleteborder();
    click=false;
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
    deleteborder();
    click=false;
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
    deleteborder();
    click=false;
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
    deleteborder();
    click=false;
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
    deleteborder();
    click=false;
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
    deleteborder();
    click=false;
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
        if(click){
            QString name = namebut;
            name.indexOf(QString("_"));
            {}
        }
    }
}

void Widget::on_klick_clicked()
{
    deleteborder();
    krugi= false;
    kvadrati= false;
    prymougol= false;
    otrezki= false;
    treugol = false;
    ovali = false;
    kist=false;
    click = false;
    scene->kistfalse();
}

void Widget::on_deletebut_clicked()
{
   scene->clear();
}
