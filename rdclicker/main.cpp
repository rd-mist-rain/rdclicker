#include "mainwindow.h"
#include <windows.h>
#include <thread>
#include <QApplication>
#include <atomic>
#include "main.h"

using namespace std;

int wait_time = 50000;    // 等待时间
int setting[] = {38, 40, 162, 163}; // 按键数组
atomic<bool> lpress{false}; // 是否应处于左键点击状态
atomic<bool> rpress{false}; // 是否应处于右键点击状态
atomic<bool> upress{false}; // 是否应处于滚轮上滚状态
atomic<bool> dpress{false}; // 是否应处于滚轮下滚状态
int click = 0; // 长按
atomic<bool> running{true}; // 运行标志

void waitkeys()
{
    while (running)
    {
        this_thread::sleep_for(chrono::microseconds(1000));
        if (GetAsyncKeyState(setting[0])) // 上键
        {
            upress = !upress.load();
            this_thread::sleep_for(chrono::microseconds(100000));
            if (click == 0)
                upress = !upress.load();
        }
        if (GetAsyncKeyState(setting[1])) // 下键
        {
            dpress = !dpress.load();
            this_thread::sleep_for(chrono::microseconds(100000));
            if (click == 0)
                dpress = !dpress.load();
        }
    }
}

void waitctrl()
{
    while (running)
    {
        this_thread::sleep_for(chrono::microseconds(1000));
        if (GetAsyncKeyState(setting[2])) // 左Ctrl键
        {
            lpress = !lpress.load();
            this_thread::sleep_for(chrono::microseconds(100000));
            if (click == 0)
                lpress = !lpress.load();
        }
        if (GetAsyncKeyState(setting[3])) // 右Ctrl键
        {
            rpress = !rpress.load();
            this_thread::sleep_for(chrono::microseconds(100000));
            if (click == 0)
                rpress = !rpress.load();
        }
    }
}

void oclicks()
{
    while (running)
    {
        this_thread::sleep_for(chrono::microseconds(wait_time));
        if (upress.load())
        {
            mouse_event(MOUSEEVENTF_WHEEL, 0, 0, 120, 0); // 执行滚轮上滚操作
        }
        if (dpress.load())
        {
            mouse_event(MOUSEEVENTF_WHEEL, 0, 0, -120, 0); // 执行滚轮下滚操作
        }
    }
}

void cclicks()
{
    while (running)
    {
        this_thread::sleep_for(chrono::microseconds(wait_time));
        if (lpress.load())
        {
            mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0); // 执行点击操作
        }
        if (rpress.load())
        {
            mouse_event(MOUSEEVENTF_RIGHTDOWN | MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0); // 执行点击操作
        }
    }
}

void stopThreads()
{
    running = false;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    thread hearc(waitctrl);
    thread hearo(waitkeys);
    thread cc(cclicks);
    thread oc(oclicks);

    QObject::connect(&a, &QApplication::aboutToQuit, stopThreads);


    hearc.detach();
    hearo.detach();
    cc.detach();
    oc.detach();

    return a.exec();
}
