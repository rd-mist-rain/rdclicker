#include <iostream>
#include <windows.h>
#include <thread>
#include <fstream>
#include <string>
using namespace std;
int wait_time = 1000; //等待时间
int setting[]={18,38,40,162,163,27,32};//按键数组
void read()
{
    ifstream inFile("settings.txt"); // 打开名为settings.txt的文件
    string line;
    int i = 0;
    while(getline(inFile, line)) //逐行读取文件内容
    { 
        setting[i]=stoi(line); //将字符串转换为十进制整数
        i++;
    }
    inFile.close(); //关闭文件
}
void waitkeys()
{
    while(true)
    {
        if(GetAsyncKeyState(setting[0])) //Alt键
        {
            cin >> wait_time; //获取等待时间,单位为微秒
            clog << "waiting time was set to " << wait_time << " microseconds" << endl;
        }
        if(GetAsyncKeyState(setting[1])) //上键
        {
            mouse_event(MOUSEEVENTF_WHEEL, 0, 0, 120, 0); //执行滚轮上滚操作
        }
        if(GetAsyncKeyState(setting[2])) //下键
        {
            mouse_event(MOUSEEVENTF_WHEEL, 0, 0, -120, 0); //执行滚轮下滚操作
        }
        this_thread::sleep_for(chrono::microseconds(wait_time));   
    }
    
}
void waitctrl()
{
    while(true)
    {
        if(GetAsyncKeyState(setting[3])) //左Ctrl键
        {
            mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0 ); //执行点击操作
        }
        if(GetAsyncKeyState(setting[4])) //右Ctrl键
        {
            mouse_event(MOUSEEVENTF_RIGHTDOWN | MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0 ); //执行点击操作
        }
        this_thread::sleep_for(chrono::microseconds(wait_time));   
    }
}
int main()
{   
    read(); //读取配置文件
    thread hearc(waitctrl);
    thread hearo(waitkeys);
    hearc.detach();
    hearo.detach();
    while(true)
    {
        if(GetAsyncKeyState(setting[5])) //Esc键
        {
            break;
        }
        if(GetAsyncKeyState(setting[6])) //空格键
        {
            system("pause");//暂停程序并等待回到控制台时任意一个键被按下
        }
    }
    return 0;
}