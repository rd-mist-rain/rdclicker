#include "page2.h"
#include "ui_page2.h"
#include "mainwindow.h"
#include "main.h"
#include <QString>
#include <QSettings>
#include <QDebug>
QString wait_time_s=QString::number(wait_time);
int itk[73]={162,163,164,165,27,9,20,8,160,161,13,38,40,37,39,48,49,50,51,52,53,54,55,56,57,
            65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,
            96,97,98,99,100,101,102,103,104,105,
            112,113,114,115,116,117,118,119,120,121,122,123};
Page2::Page2(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Page2)
{
    ui->setupUi(this);
    ui->lineEdit->setText(wait_time_s);
    ui->comboBox->setCurrentIndex(0);
    ui->comboBox_2->setCurrentIndex(1);
    ui->comboBox_4->setCurrentIndex(11);
    ui->comboBox_5->setCurrentIndex(12);
}

Page2::~Page2()
{
    delete ui;
}

void Page2::on_pushButton_clicked()
{
    MainWindow *mainwindow=new MainWindow;
    this ->close();
    mainwindow ->show();
}


void Page2::on_pushButton_3_clicked() //应用配置
{
    wait_time=ui->lineEdit->text().toInt();
    int i1=ui->comboBox->currentIndex();
    int i2=ui->comboBox_2->currentIndex();
    int i3=ui->comboBox_4->currentIndex();
    int i4=ui->comboBox_5->currentIndex();
    setting[2]=itk[i1];//lclick
    setting[3]=itk[i2];//rclick
    setting[0]=itk[i3];//up
    setting[1]=itk[i4];//down
    click=ui->comboBox_3->currentIndex();
}
void Page2::on_pushButton_5_clicked() //保存配置
{
    QSettings *settings=new QSettings(".\\settings.ini",QSettings::IniFormat);
    settings->beginGroup("clicks");
    settings->setValue("click",QString::number(ui->comboBox_3->currentIndex()));
    settings->endGroup();

    settings->beginGroup("waittime");
    settings->setValue("wait_time",ui->lineEdit->text());
    settings->endGroup();

    settings->beginGroup("lclick");
    settings->setValue("key_value",QString::number(itk[ui->comboBox->currentIndex()]));
    settings->setValue("index",QString::number(ui->comboBox->currentIndex()));
    settings->endGroup();

    settings->beginGroup("rclick");
    settings->setValue("key_value",QString::number(itk[ui->comboBox_2->currentIndex()]));
    settings->setValue("index",QString::number(ui->comboBox_2->currentIndex()));
    settings->endGroup();

    settings->beginGroup("up");
    settings->setValue("key_value",QString::number(itk[ui->comboBox_4->currentIndex()]));
    settings->setValue("index",QString::number(ui->comboBox_4->currentIndex()));
    settings->endGroup();

    settings->beginGroup("down");
    settings->setValue("key_value",QString::number(itk[ui->comboBox_5->currentIndex()]));
    settings->setValue("index",QString::number(ui->comboBox_5->currentIndex()));
    settings->endGroup();
    delete settings;
}


void Page2::on_pushButton_4_clicked() //读取配置
{
    QSettings *settings=new QSettings(".\\settings.ini",QSettings::IniFormat);
    wait_time_s=settings->value("waittime/wait_time").toString();
    ui->lineEdit->setText(wait_time_s);
    ui->comboBox->setCurrentIndex(settings->value("lclick/index").toInt());
    ui->comboBox_2->setCurrentIndex(settings->value("rclick/index").toInt());
    ui->comboBox_4->setCurrentIndex(settings->value("up/index").toInt());
    ui->comboBox_5->setCurrentIndex(settings->value("down/index").toInt());
    ui->comboBox_3->setCurrentIndex(settings->value("clicks/click").toInt());
    delete settings;
}

