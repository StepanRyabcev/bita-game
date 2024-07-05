#include "mainwindow.h"
#include "QThread.h"
#include "ui_mainwindow.h"
#include "ClickableLabel.h"
#include <QPropertyAnimation>
#include <QTimer>
//#include <QMediaPlayer>
//#include <QAudioOutput>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QCursor bitecurs = QCursor(QPixmap(":/cursor/resources/bite.png"));
    ui->graphicsView->setCursor(bitecurs);
    ui->label->setCursor(bitecurs);
    ui->ctafalklb->setCursor(bitecurs);
    ui->timer->setCursor(bitecurs);
    ui->ctafalklb->move(3000, 3000);
    srand(time(0));
    x = rand() % 500;
    y = rand() % 500;
    ui->label->move(y, y);
    QPixmap pixmap(":/teacher/resources/zubivich.png");
    QSize newSize(100, 75);
    ui->label->setPixmap(pixmap.scaled(newSize, Qt::KeepAspectRatio, Qt::SmoothTransformation));


    //battlemusic = new QMediaPlayer;
    //out = new QAudioOutput;
    //battlemusic->setAudioOutput(out);
    //battlemusic->setSource(QUrl("qrc:/music/resources/battle.mp3"));
    //out->setVolume(50);
    //battlemusic->play();

    QPropertyAnimation *animation = new QPropertyAnimation(ui->label, "geometry");
    animation->setDuration(1000);
    animation->setLoopCount(-1);
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, sinmove);
    if (hp == 3)
        timer->stop();
    timer->start(8);

    QTimer *timertt = new QTimer(this);
    tt = 60;
    connect(timertt, &QTimer::timeout, this, timechng);
    timertt->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_label_clicked()
{
    if (hp == 0)
    {
        QPixmap pixmap(":/teacher/resources/zubivich_blood1.png");
        QSize newSize(100, 75);
        ui->label->setPixmap(pixmap.scaled(newSize, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        hp = 1;
    }
    else
    {
        if (hp == 1)
        {
        QPixmap pixmap(":/teacher/resources/zubivich_blood2.png");
        QSize newSize(100, 75);
        ui->label->setPixmap(pixmap.scaled(newSize, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        hp = 2;
        }
        else
            if (hp == 2)
        {
            hp = 3;
            ui->label->~QLabel();
            ui->timer->~QLabel();
            ui->ctafalklb->move(250, 500);
            QPixmap pixmap1(":/catafalk/resources/catafalk.png");
            ui->ctafalklb->setPixmap(pixmap1);
            QPropertyAnimation *animationc = new QPropertyAnimation(ui->ctafalklb, "geometry");
            animationc->setDuration(1000);
            animationc->setLoopCount(1);
            //battlemusic->stop();
            //battlemusic->setSource(QUrl("qrc:/music/resources/catafalk.mp3"));
            //battlemusic->play();
            y = 250;
            x = 500;
            QTimer *timerc = new QTimer(this);
            connect(timerc, &QTimer::timeout, this, catafalkmove);
            if (hp == 3)
                timerc->stop();
            timerc->start(25);
        }
    }
}


void MainWindow::sinmove()
{
    if (hp != 3)
    {
       int curx, cury;
        curx = mapFromGlobal(QCursor::pos()).rx();
        cury = mapFromGlobal(QCursor::pos()).ry();
        if ((curx - prevx) < 0)
            direction = -1;
        if ((curx - prevx) > 0)
            direction = 1;
        if ((abs(ui->label->x() - curx) <= 200) or (abs(ui->label->y() - cury) <= 200))
        {
            x = ui->label->x() + direction;
            y = 100 + 100 * qSin(x / 20.0);
            if (y > 500)
                y = 0;
            if (x > 600)
            {
                x = 0;
            }
            if (x < 0)
                x = 600;
            ui->label->move(x, y);
        }
            prevx = curx;
            prevy = cury;
    }
}

void MainWindow::catafalkmove()
{
    x = x - 1;
    ui->ctafalklb->move(x, y);
}

void MainWindow::timechng()
{
    if ((tt >= 0) and (hp != 3))
        ui->timer->setText(QString::number(tt));
    tt = tt - 1;
    if ((tt == -1) and (hp != 3))
    {
        hp = 3;
        ui->label->~QLabel();
        ui->timer->setText("Время истекло");
        //battlemusic->stop();

    }
}

/*
 Умельшить картинку
 Увеличить обасть игры
 Добавить меню
 Добавить возможность рестарта
 Добавить сложность
*/
