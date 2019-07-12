#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pbC->setEnabled(false);
    ui->pbT->setEnabled(false);
    ui->pbCoke->setEnabled(false);
    ui->pbRe->setEnabled(false);

}

Widget::~Widget()
{
    delete ui;
}
void Widget::ChangeMoney(int n){
    money+=n;
    ui ->lcdNumber ->display(QString::number(money));
}
void Widget::Button(int n){
    if(n>=200){
        ui->pbRe->setEnabled(true);
        ui->pbC->setEnabled(true);
        ui->pbT->setEnabled(true);
        ui->pbCoke->setEnabled(true);
    }else if(n>=150){
        ui->pbRe->setEnabled(true);
        ui->pbC->setEnabled(true);
        ui->pbT->setEnabled(true);
        ui->pbCoke->setEnabled(false);
    }else if(n>=100){
        ui->pbRe->setEnabled(true);
        ui->pbC->setEnabled(true);
        ui->pbT->setEnabled(false);
        ui->pbCoke->setEnabled(false);
    }else if(n>0){
        ui->pbRe->setEnabled(true);
        ui->pbC->setEnabled(false);
        ui->pbT->setEnabled(false);
        ui->pbCoke->setEnabled(false);
    }else {
        ui->pbRe->setEnabled(false);
        ui->pbC->setEnabled(false);
        ui->pbT->setEnabled(false);
        ui->pbCoke->setEnabled(false);
    }
}
void Widget::on_pb10_clicked()
{
    ChangeMoney(10);
    Button(money);
}

void Widget::on_pb50_clicked()
{
    ChangeMoney(50);
    Button(money);
}

void Widget::on_pb100_clicked()
{
    ChangeMoney(100);
    Button(money);
}

void Widget::on_pb500_clicked()
{
    ChangeMoney(500);
    Button(money);
}

void Widget::on_pbC_clicked()
{
    ChangeMoney(-100);
    Button(money);
}

void Widget::on_pbT_clicked()
{
    ChangeMoney(-150);
    Button(money);
}

void Widget::on_pbCoke_clicked()
{
    ChangeMoney(-200);
    Button(money);
}

void Widget::on_pbRe_clicked()
{
    QMessageBox msg;
    msg.information(nullptr,"Return",QString("Return Money : %1").arg(money));
    ChangeMoney(-money);
    Button(money);
}
