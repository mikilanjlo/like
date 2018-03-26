#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QResizeEvent>

#include <paintscene.h>
#include <circle.h>
#include <krugi.h>
#include <kvadr.h>
#include <prymougol.h>

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
    bool add,move;
    Circle *krug;
    Krugi *krugs;
    Kvadr *kvadr;
    Prymougol *pr;
    bool kist;

    bool krugi;

    bool ovali;

    bool kvadrati;

    bool prymougol;

    bool otrezki;

    bool treugol;

private:
    Ui::Widget *ui;
    QTimer *timer;      /* Определяем таймер для подготовки актуальных размеров

                         * графической сцены
                         * */
    QTimer *timer1;
    paintScene *scene;  // Объявляем кастомную графическую сцену


private:
    /* Переопределяем событие изменения размера окна
     * для пересчёта размеров графической сцены
     * */
    void resizeEvent(QResizeEvent * event);

private slots:
    void slotTimer();

    void on_kist_clicked();

    void on_krug_clicked();

    void on_elipse_clicked();

    void on_kvadrat_clicked();

    void on_prymougolnic_pressed();

public slots:
    //void kists();
};
#endif // WIDGET_H
