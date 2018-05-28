#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QResizeEvent>
#include <QColorDialog>
#include <QTemporaryFile>
#include <QShortcut>
#include <paintscene.h>
#include <circle.h>
#include <QPushButton>
#include <krugi.h>
#include <kvadr.h>
#include <prymougol.h>
#include <tri.h>
#include <line.h>
#include <mymy.h>
#include <QShortcut>

namespace Ui {
class Widget;
}

struct files{
    int name;
    QFile *file;
    files *next;
};



struct list {
        Figure *object;
        int name;
        list *next;
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
    Figure *my;
    buttons *headbut;
    QColor MainColor;
    int listname;
    QString namebut;

    list *flist;
    list *ylist;
    files *filehead;
    int filesname;
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
    void funclist(Figure *x);
    QShortcut *keyCtrlY;
    int maxfile;

    void proverca_click();
    void create_button(int x);
    void deleteY();
    void deleteall();
    void zapis();
    void zapis2(QTemporaryFile &f);
    void read(QString filename);
    void click_my_button();



private:
    /* Переопределяем событие изменения размера окна
     * для пересчёта размеров графической сцены
     * */
    void resizeEvent(QResizeEvent * event);

private slots:
    //void slotTimer();

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

    void slotz();
    void sloty();



    void on_pushButton_clicked();

    void on_save_clicked();

public slots:
    //void kists();
};
#endif // WIDGET_H
