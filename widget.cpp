#include "widget.h"
#include "circle.h"
#include "krugi.h"
#include "ui_widget.h"
#include <QtGui>
#include <QFileDialog>

Widget::Widget() :add(false),move(false), QWidget(0),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    scene = new paintScene();       // Инициализируем графическую сцену
    ui->graphicsView->setScene(scene);  // Устанавливаем графическую сцену

    timer = new QTimer();       // Инициализируем таймер
    //connect(timer, &QTimer::timeout, this, &Widget::slotTimer);
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
    my = NULL;

    flist = NULL;

    listname = 0;
    headbut=NULL;
    MainColor=Qt::white;
    ui->kraska->setStyleSheet("background-color: "+MainColor.name());
    keyCtrlZ = new QShortcut(this);   // Инициализируем объект
        keyCtrlZ->setKey(Qt::CTRL + Qt::Key_Z);    // Устанавливаем код клавиши
        // цепляем обработчик нажатия клавиши
        connect(keyCtrlZ, SIGNAL(activated()), this, SLOT(slotz()));
    filehead = NULL;
    filesname=0;
    maxfile=0;
    zapis();


    keyCtrlY = new QShortcut(this);   // Инициализируем объект
        keyCtrlY->setKey(Qt::CTRL + Qt::Key_Y);    // Устанавливаем код клавиши
        // цепляем обработчик нажатия клавиши
        connect(keyCtrlY, SIGNAL(activated()), this, SLOT(sloty()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::slotz(){
    if(filesname - 1 >= 0){
        read(QString("temp") + QString::number(filesname-1) + QString(".nick"));
        filesname--;
    }
}

void Widget::sloty(){
    if(filesname  <= maxfile){
        read(QString("temp") + QString::number(filesname+1) + QString(".nick"));
        filesname++;
    }
}

void Widget::click_my_button(){
    QStringList lst = namebut.split("_");
    QString str = lst.at(1);
    int count = str.toInt();


            list *y = new list;
            y = flist;
            while(y->name != count){
              y = y->next;
            }
            my = y->object;

        //tre->clickresult(2);
    click = true;
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

void Widget::create_button( int x){
    QString s = QString("Object");
    QPushButton *button = new QPushButton(s+QString("_")+QString::number(x), ui->scrollAreaWidgetContents);

      // устанавливаем размер и положение кнопки
      button->setGeometry(QRect(QPoint(0, 50*(listname)),
      QSize(150, 50)));
      if(50*(listname)>=ui->scrollAreaWidgetContents->height()){
        ui->scrollAreaWidgetContents->resize(ui->scrollAreaWidgetContents->width(),50*(listname+1));
      }
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

void Widget::addanything(){
    proverca_click();
        scene->proverka(x,y,add);
        scene->proverka2(movex,movey,move);

        if(add||move){
           if(add){
               bool creates = false;
               if(!click){
                   if(ovali){

                       my = new Circle;

                   }
                   if(krugi){
                       my = new Krugi;
                  }
                   if(kvadrati){
                       my = new Kvadr;
                  }
                   if(otrezki){
                       my = new Line;
                  }
                   if(prymougol){
                       my = new Prymougol;
                  }
                   if(treugol){
                       my = new Tri;
                  }

                   if(my != NULL){
                        funclist(my);
                        my->draw(scene);
                   }
               }
               if(my != NULL)
                   creates = true;
               if(creates){

                   my->put(x,y);
                   //my->change_razmer(0,0) ;
                   my->change_color(MainColor);
                    zapis();
               }
           }
           else{
               if(move && my!=NULL){
                  my->change_razmer(movex-x,movey-y) ;
               }
               else{

                   if(!click){
                    //zapis();
                    my = NULL;

                   }
               }
           }

        }

}

void Widget::resizeEvent(QResizeEvent *event)
{
    timer->start(100);
    QWidget::resizeEvent(event);
}

void Widget::funclist(Figure *x){
    // Включение в список нового компонента
        list* y = new list();
        list* c = new list();
        c->object = x;
        c->next = NULL;
        c->name = listname;
        create_button(listname);
        listname++;
        if (flist == NULL){
            flist = c;
        }
        else{
            y = flist;
            while( y->next != NULL){
                y = y->next;
            }
            y->next = c;
        }
}

void Widget::on_kist_clicked()
{

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

    /*krugi= false;
    kvadrati= false;
    prymougol= false;
    otrezki= false;
    treugol = false;
    ovali = false;
    kist=false;
    click = false;
    scene->kistfalse();*/
}

void Widget::on_deletebut_clicked()
{
  deleteall();
}

void Widget::zapis(){
    files *f = new files;
    f->next = NULL;
    f->name = filesname;
    QFile *filefile = new QFile;
    f->file = filefile;


    files *f2 = new files;
    if(filehead == NULL){


        filehead = f;
        filehead->file->setFileName(QString("temp") + QString::number(f->name) + QString(".nick"));
        if(f->file->open(QIODevice::WriteOnly)){

        }
        filehead->file->close();

    }
    else{
        f2 = filehead;
        while( f2->next != NULL){
            f2 = f2->next;

        }
        f2->next = f;
        f2->next->file->setFileName(QString("temp") + QString::number(f->name) + QString(".nick"));

        if (f2->next->file->open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QTextStream writeStream(f2->next->file);
            list *c = new list;
            c = flist;
            while(c != NULL){

            //writeStream << c->object->zapis() + "\n";
            c = c->next;
             }
            f2->next->file->close();

        }

    filesname++;
    maxfile=filesname;
     }
}

void Widget::deleteall(){

    list *c = new list;
    while(flist != NULL){
        c = flist;
        flist = flist->next;
        //c->object->~Myobject();
        listname--;
        delete c;
    }
    buttons *b = new buttons;
    while(headbut != NULL){
        b = headbut;
        headbut = headbut->next;
        b->but->deleteLater();
        delete b;
    }
    scene->clear();
}

void Widget::read(QString filename){
    QFile *file = new QFile(filename);
    deleteall();
    if ((file->exists())&&(file->open(QIODevice::ReadOnly)))
    {
        QString str="";
        QString str2="";
            while(!file->atEnd())
            {
                /*str=file->readLine();
                QStringList lst = str.split("_");
                str = lst.at(0);
                //Myobject *alians= new Myobject(str.toInt(),scene);
                //funclist(alians);
                str = lst.at(1);
                str2 = lst.at(2);
                alians->put(str.toInt(),str2.toInt());
                str = lst.at(3);
                str2 = lst.at(4);
                alians->change_razmer(str.toInt(),str2.toInt()) ;
                str =lst.at(5);
                QColor *colo = new QColor(str);
                alians->change_color(*colo);*/
            }
            file->close();
    }
}

void Widget::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                QString::fromUtf8("Открыть файл"),
                                QDir::currentPath(),
                                "Images (*.nick);;All files (*.*)");
    read(fileName);

}

void Widget::on_save_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                                QString::fromUtf8("Сохранить файл"),
                                QDir::currentPath(),
                                "Images (*.nick);;All files (*.*)");
    QFile *file = new QFile(fileName);

    if (file->open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream writeStream(file);
        list *c = new list;
        c = flist;
        while(c != NULL){

        //writeStream << c->object->zapis() + "\n";
        c = c->next;
         }
        file->close();

    }
}
