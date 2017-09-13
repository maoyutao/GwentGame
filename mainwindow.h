#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "player.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    // 按任意键或点击鼠标 主页面进入下一页
    bool eventFilter(QObject *watched, QEvent *event) override;

private slots:
    void on_toEditCard_clicked();
    void on_returnToChoose_clicked();
    void on_toPlay_clicked();

private:
    Ui::MainWindow *ui;
    Player * mPlayer;
};

#endif // MAINWINDOW_H
