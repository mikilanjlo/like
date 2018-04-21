#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QResizeEvent>
#include <QColorDialog>
#include <paintscene.h>
#include <circle.h>
#include <krugi.h>
#include <kvadr.h>
#include <prymougol.h>
#include <tri.h>
#include <line.h>

namespace Ui {
class Widget;
}

struct listcircle {
        Circle *object;
        listcircle* next; //Ссылка на следущий элемент списка
};

struct listkrugi {
        Krugi *object;
        listkrugi* next; //Ссылка на следущий элемент списка
};

struct listkvadr {
        Kvadr *object;
        listkvadr* next; //Ссылка на следущий элемент списка
};

struct listline {
        Line *object;
        listline* next; //Ссылка на следущий элемент списка
};

struct listprym {
        Prymougol *object;
        listprym* next; //Ссылка на следущий элемент списка
};

struct listtri {
        Tri *object;
        listtri* next; //Ссылка на следущий элемент списка
};

struct list {
        listcircle *circles;
        listkrugi *krugis;
        listkvadr *kvadrs;
        listline *lines;
        listprym *pryms;
        listtri *tris;
};

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
    Tri *tre;
    Line *line;
    QColor MainColor;
   /* listcircle fcircles;
    listkrugi fkrugis;
    listkvadr fkvadrs;
    listline flines;
    listprym fpryms;
    listtri ftris;*/
    list *flist;
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
    void funccircle(Circle *x);
    void funckrugi(Krugi *x);
    void funckvadr(Kvadr *x);
    void funcline(Line *x);
    void functri(Tri *x);
    void funcprym(Prymougol *x);
    void proverca_click();


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

    void on_treugolnik_clicked();

    void on_otrezok_clicked();

    void on_kraska_clicked();

    void on_klick_clicked();

public slots:
    //void kists();
};
#endif // WIDGET_H
