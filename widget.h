#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QResizeEvent>
#include <QColorDialog>
#include <QShortcut>
#include <paintscene.h>
#include <circle.h>
#include <QPushButton>
#include <krugi.h>
#include <kvadr.h>
#include <prymougol.h>
#include <tri.h>
#include <line.h>

namespace Ui {
class Widget;
}

struct listcircle {
        int name;
        Circle *object;
        listcircle* next; //Ссылка на следущий элемент списка
};

struct listkrugi {
        Krugi *object;
        int name;
        int x_x;
        int y_y;
        listkrugi* next; //Ссылка на следущий элемент списка
};

struct listkvadr {
        Kvadr *object;
        int name;
        int x_x;
        int y_y;
        listkvadr* next; //Ссылка на следущий элемент списка
};

struct listline {
        Line *object;
        int name;
        int x_x;
        int y_y;
        listline* next; //Ссылка на следущий элемент списка
};

struct listprym {
        Prymougol *object;
        int name;
        int x_x;
        int y_y;
        listprym* next; //Ссылка на следущий элемент списка
};

struct listtri {
        Tri *object;
        int name;
        int x_x;
        int y_y;
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

struct buttons{
    QPushButton *but;
    buttons *next;
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
    QPushButton *but;
    Circle *krug;
    Krugi *krugs;
    Kvadr *kvadr;
    Prymougol *pr;
    Tri *tre;
    Line *line;
    buttons *headbut;
    QColor MainColor;
    int Circlename;
    int Kruginame;
    int Kvadrname;
    int Linename;
    int Prymname;
    int Triname;
    QString namebut;
   /* listcircle fcircles;
    listkrugi fkrugis;
    listkvadr fkvadrs;
    listline flines;
    listprym fpryms;
    listtri ftris;*/
    list *flist;
    list *ylist;
    bool kist;

    bool krugi;

    bool ovali;

    bool kvadrati;

    bool prymougol;

    bool otrezki;

    bool treugol;
    bool click;

private:
    Ui::Widget *ui;
    QTimer *timer;      /* Определяем таймер для подготовки актуальных размеров

                         * графической сцены
                         * */
    QTimer *timer1;
    paintScene *scene;  // Объявляем кастомную графическую сцену
    int butcount;
    QShortcut *keyCtrlZ;
    void funccircle(Circle *x);
    void funckrugi(Krugi *x);
    void funckvadr(Kvadr *x);
    void funcline(Line *x);
    void functri(Tri *x);
    void funcprym(Prymougol *x);
    void proverca_click();
    void create_button(QString s,int x);
    void deleteY();
    void deleteborder();



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

    void on_deletebut_clicked();
    void click_my_button();
    void nazad();

public slots:
    //void kists();
};
#endif // WIDGET_H
