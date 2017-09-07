#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <global.h>
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
    bool eventFilter(QObject *watched, QEvent *event) override;
private slots:
    void on_toEditCard_clicked();

    void on_returnToChoose_clicked();

    void on_cardSet_2_clicked();

    void on_cardSet_1_clicked();

    void on_newCardSet_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
