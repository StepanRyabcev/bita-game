#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include <QMediaPlayer>
//#include <QAudioOutput>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int x, y, hp = 0;

private slots:
    //void on_pushButton_clicked();

    //void on_graphicsView_customContextMenuRequested(const QPoint &pos);

    void on_label_clicked();

    void sinmove();

    void catafalkmove();

    void timechng();

    void on_btn_clicked();

    void on_easy_clicked();

    void on_normal_clicked();

    void on_hard_clicked();

private:
    Ui::MainWindow *ui;
    int tt, prevx = 0, prevy = 0, direction, counter = 0;
    //QMediaPlayer *battlemusic;
    //QAudioOutput *out;
    bool tocos = false;
    double speed = 1;
};
#endif // MAINWINDOW_H
