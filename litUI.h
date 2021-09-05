#ifndef _LITUI_H
#define _LITUI_H

#include <iostream>
#include <ctime>
using namespace std;

/*insert part begin*/
inline int insert_UI_year();
inline int insert_UI_month();
inline int insert_UI_day();
inline bool check_day(int day, int month, int year);
inline void insert_UI_s();
inline void insert_UI_bei();
inline void insert_had();
inline bool insert_UI_jud();
inline bool insert_UI_jud2();
inline int insert_gethour();
inline int insert_getmin();
inline int insert_getsec();

inline int insert_UI_year()
{
flag1:
    printf("请输入您选择的年份（四位年份，例如2021）：");
    int year;
    cin >> year;
    if (year <= 999 || year >= 10000)
    {
        printf("您输入的年份错误，请输入正确的年份，请再次输入年份\n");
        goto flag1;
    }
    return year;
}
inline int insert_UI_month()
{
flag2:
    printf("请输入您选择的月份（两位月份，例如01）：");
    int month;
    cin >> month;
    if (month <= 0 || month >= 13)
    {
        printf("您输入的月份错误，请输入正确的月份，请再次输入月份\n");
        goto flag2;
    }
    return month;
}
inline bool check_day(int day, int month, int year)
{
    if (day <= 0 || day > 31)
        return 0;
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        if (day > 31)
            return 0;
        else
            return 1;
    }
    else if (month == 2)
    {
        if (year % 4 == 0)
        {
            if (day > 29)
                return 0;
            else
                return 1;
        }
        else
        {
            if (day > 28)
                return 0;
            else
                return 1;
        }
    }
    else
    {
        if (day > 30)
            return 0;
        else
            return 1;
    }
}
inline int insert_UI_day(int month, int year)
{
flag3:
    printf("请输入您选择的日期（两位日期，例如30）：");
    int day;
    cin >> day;
    if (!check_day(day, month, year))
    {
        printf("您输入的日期错误，请输入日期的年份，请再次输入日期\n");
        goto flag3;
    }
    return day;
}
inline void insert_UI_s()
{
    printf("请输入您想要加入的事件（100字符以内，请不要加入空格）：\n");
    return;
}
inline void insert_UI_bei()
{
    printf("请输入您想备注的东西：\n");
    return;
}
inline void insert_had()
{
    printf("插入新的DDL成功，请进行接下来的操作\n");
    return;
}
inline bool insert_UI_jud()
{
    flag6:
    cout << "是否加入时间管理选项(y/n)" << endl;
    char ic;
    cin >> ic;
    if (ic == 'y')
    {
        return 1;
    }
    else if (ic == 'n')
    {
        return 0;
    }
    else
    {
        cout << "您输入的信息错误，请重新输入！" << endl;
        goto flag6;
    }
}
inline int insert_gethour()
{
    flag7:
    cout << "请输入时间中的小时：（24小时制）" << endl;
    int hour = 0;

    cin >> hour;
    if (hour > 24 || hour < 0)
    {
        cout << "您输入的小时数有误，请重新输入" << endl;
        goto flag7;
    }
    return hour;
}
inline int insert_getmin()
{
    flag8:
    cout << "请输入时间中的分钟：（60以内）" << endl;
    int min = 0;

    cin >> min;
    if (min > 60 || min < 0)
    {
        cout << "您输入的分钟数有误，请重新输入" << endl;
        goto flag8;
    }
    return min;
}
inline int insert_getsec()
{
    flag9:
    cout << "请输入时间中的秒：（60以内）" << endl;
    int sec = 0;

    cin >> sec;
    if (sec > 60 || sec < 0)
    {
        cout << "您输入的秒数有误，请重新输入" << endl;
        goto flag9;
    }
    return sec;
}
inline bool insert_UI_jud2()
{
    flag10:
    cout << "是否加入定时通知选项(y/n)" << endl;
    char se;
    cin >> se;
    if (se == 'y')
    {
        return 1;
    }
    else if (se == 'n')
    {
        return 0;
    }
    else
    {
        cout << "您输入的信息错误，请重新输入！" << endl;
        goto flag10;
    }
}
/*insert part end*/

/*dele part begin*/
inline void dele_init();
inline int dele_UI(int tot);

inline void dele_init()
{
    printf("请选择要删除的DDL\n");
    return;
}
inline int dele_UI(int tot)
{
flag4:
    printf("请选择要删除的DDL编号:");
    int noo = 0;
    scanf("%d", &noo);
    if (noo > tot || noo <= 0)
    {
        printf("您输入的DDL编号错误，请重新输入DDL编号\n");
        goto flag4;
    }
    return noo;
}
/*dele part end*/

/*wrout part begin*/
inline void wrout1_UI_init();

inline void wrout1_UI_init()
{
    printf("以下是所有有效DDL的标号：\n");
}
/*wrout part end*/

/*munu part begin*/
//***
/*munu part start*/

/*
get time function 
*/
inline int get_year()
{
    time_t now=time(0);
    tm *ltm =localtime(&now);
    return 1900+ltm->tm_year;
}
inline int get_mon()
{
    time_t now= time(0);
    tm *ltm=localtime(&now);
    return ltm->tm_mon;
}
inline int get_day()
{
    time_t now= time(0);
    tm *ltm=localtime(&now);
    return ltm->tm_mday;
}
inline int get_hour()
{
    time_t now= time(0);
    tm *ltm=localtime(&now);
    return ltm->tm_hour;
}
inline int get_min()
{
    time_t now= time(0);
    tm *ltm=localtime(&now);
    return ltm->tm_min;
}
inline int get_sec()
{
    time_t now= time(0);
    tm *ltm=localtime(&now);
    return ltm->tm_sec;
}
/*
 1 means has past
 0 means has not past
*/
inline bool past_mark(int year,int mon,int day,int hour,int min,int sec)
{
    int ds_year=get_year,
        ds_mon=get_mon,
        ds_day=get_day,
        ds_hour=get_hour,
        ds_min=get_min,
        ds_sec=get_sec;
    // if()
}
#endif