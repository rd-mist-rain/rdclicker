#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "page2.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    Page2 *page2=new Page2;
    this ->close();
    page2->show();
}
