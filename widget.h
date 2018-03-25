#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QResizeEvent>

#include <paintscene.h>
#include <circle.h>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget();
    ~Widget();
    void addanything();
    float x,y,movex,movey;
    bool add,move,ob;
    Circle *krug;
    bool kist,krugi,ovali,kvadrati,prymougol,otrezki,treugol;

private:
    Ui::Widget *ui;
    QTimer *timer;      /* Определяем таймер для подготовки актуальных размеров

                         * графической сцены
                         * */
    QTimer *timer1;
    paintScene *scene;  // Объявляем кастомную графическую сцену
    void on_kist_clicked();

private:
    /* Переопределяем событие изменения размера окна
     * для пересчёта размеров графической сцены
     * */
    void resizeEvent(QResizeEvent * event);

private slots:
    void slotTimer();

public slots:
    //void kists();
};
#endif // WIDGET_H
