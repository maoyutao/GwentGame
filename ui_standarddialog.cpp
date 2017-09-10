#include "ui_standarddialog.h"
#include "ui_dialog.h"
#include <QDebug>

Dialog::Dialog(QString str, bool haveText, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->label->setText(str);
    if (!haveText)
    {
        ui->lineEdit->hide();
    }
    qDebug() << "dialog";
}

Dialog::~Dialog()
{
    delete ui;
    qDebug() << "delete dialog";
}

void Dialog::on_lineEdit_textChanged(const QString &arg1)
{
    content = arg1;
}
