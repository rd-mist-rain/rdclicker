#ifndef PAGE2_H
#define PAGE2_H

#include <QWidget>

namespace Ui {
class Page2;
}

class Page2 : public QWidget
{
    Q_OBJECT

public:
    explicit Page2(QWidget *parent = nullptr);
    ~Page2();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Page2 *ui;
};

#endif // PAGE2_H
