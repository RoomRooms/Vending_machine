#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    void ChangeMoney(int n);
    void Button(int n);
    int money{0};

private slots:
    void on_pb10_clicked();

    void on_pb50_clicked();

    void on_pb100_clicked();

    void on_pb500_clicked();

    void on_pbC_clicked();

    void on_pbT_clicked();

    void on_pbCoke_clicked();

    void on_pbR_clicked();

    void on_pbRe_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
