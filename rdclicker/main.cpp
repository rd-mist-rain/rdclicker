#include "mainwindow.h"
#include <windows.h>
#include <thread>
#include <QApplication>
#include "main.h"
using namespace std;
int wait_time=50000;    //等待时间
int setting[]={38,40,162,163};//按键数组
bool lpress=0; //是否应处于左键点击状态
bool rpress=0; //是否应处于右键点击状态
bool upress=0; //是否应处于滚轮上滚状态
bool dpress=0; //是否应处于滚轮下滚状态
int click=0; //长按

void waitkeys()
{
    while(true)
    {
        this_thread::sleep_for(chrono::microseconds(1000));
        if(GetAsyncKeyState(setting[0])) //上键
        {
            upress=!upress;
            this_thread::sleep_for(chrono::microseconds(100000));
            if(click==0)
                upress=!upress;
        }
        if(GetAsyncKeyState(setting[1])) //下键
        {
            dpress=!dpress;
            this_thread::sleep_for(chrono::microseconds(100000));
            if(click==0)
                dpress=!dpress;
        }
    }
}

void waitctrl()
{
    while(true)
    {
        this_thread::sleep_for(chrono::microseconds(1000));
        if(GetAsyncKeyState(setting[2])) //左Ctrl键
        {
            lpress=!lpress;
            this_thread::sleep_for(chrono::microseconds(100000));
            if(click==0)
                lpress=!lpress;
        }
        if(GetAsyncKeyState(setting[3])) //右Ctrl键
        {
            rpress=!rpress;
            this_thread::sleep_for(chrono::microseconds(100000));
            if(click==0)
                rpress=!rpress;
        }
    }
}
void oclicks()
{
    while(true)
    {
        this_thread::sleep_for(chrono::microseconds(wait_time));
        if(upress)
        {
            mouse_event(MOUSEEVENTF_WHEEL, 0, 0, 120, 0); //执行滚轮上滚操作
        }
        if(dpress)
        {
            mouse_event(MOUSEEVENTF_WHEEL, 0, 0, -120, 0); //执行滚轮下滚操作
        }
    }
}
void cclicks()
{
    while(true)
    {
        this_thread::sleep_for(chrono::microseconds(wait_time));
        if(lpress)
        {
            mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0 ); //执行点击操作
        }
        if(rpress)
        {
            mouse_event(MOUSEEVENTF_RIGHTDOWN | MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0 ); //执行点击操作
        }
    }
}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    thread hearc(waitctrl);
    thread hearo(waitkeys);
    hearc.detach();
    hearo.detach();
    thread cc(cclicks);
    thread oc(oclicks);
    cc.detach();
    oc.detach();
    return a.exec();
}
