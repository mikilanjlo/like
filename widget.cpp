#include "widget.h"
#include "circle.h"
#include "ui_widget.h"

Widget::Widget() :add(false), QWidget(0),
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
    scene->setSceneRect(0,0, ui->graphicsView->width(), ui->graphicsView->height() );
}

void Widget::addanything(){
    scene->proverka(x,y,add);
    if(add){
        Circle *alian= new Circle();
            alian->put(x,y);
            scene->addItem(alian);
    }
}

void Widget::resizeEvent(QResizeEvent *event)
{
    timer->start(100);
    QWidget::resizeEvent(event);
}
