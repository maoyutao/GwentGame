#ifndef UI_STANDARDDIALOG_H
#define UI_STANDARDDIALOG_H

#include <QDialog>
#include <QString>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QString str, bool haveText, QWidget *parent = 0);
    ~Dialog();
    QString content;
private slots:
    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::Dialog *ui;
};

#endif // UI_STANDARDDIALOG_H
