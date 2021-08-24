#ifndef _LITUI_H
#define _LITUI_H

#include<iostream>
using namespace std;

/*insert part begin*/
inline int insert_UI_year();
inline int insert_UI_month();
inline int insert_UI_day();
inline bool check_day(int day,int month,int year);
inline void insert_UI_s();
inline void insert_UI_bei();
inline void insert_had();

inline int insert_UI_year(){
    flag1:
    printf("请输入您选择的年份（四位年份，例如2021）：");
    int year;
    cin>>year;
    if(year<=999||year>=10000){
        printf("您输入的年份错误，请输入正确的年份，请再次输入年份\n");
        goto flag1;
    }
    return year;
}
inline int insert_UI_month(){
    flag2:
    printf("请输入您选择的月份（两位月份，例如01）：");
    int month;
    cin>>month;
    if(month<=0||month>=13){
        printf("您输入的月份错误，请输入正确的月份，请再次输入月份\n");
        goto flag2;
    }
    return month;
}
inline bool check_day(int day,int month,int year){
    if(day<=0||day>31)return 0;
    if(month==1||month==3||month==5||month==7||month==8||month==10||month==12){
        if(day>31)return 0;
        else return 1;
    }
    else if(month==2){
        if(year%4==0){
            if(day>29)return 0;
            else return 1;
        }
        else{
            if(day>28)return 0;
            else return 1;
        }
    }
    else{
        if(day>30)return 0;
        else return 1;
    }
}
inline int insert_UI_day(int month,int year){
    flag3:
    printf("请输入您选择的年份（两位日期，例如30）：");
    int day;
    cin>>day;
    if(!check_day(day,month,year)){
        printf("您输入的日期错误，请输入日期的年份，请再次输入日期\n");
        goto flag3;
    }
    return day;
}
inline void insert_UI_s(){
    printf("请输入您想要加入的事件（100字符以内，请不要加入空格）：\n");
    return ;
}
inline void insert_UI_bei(){
    printf("请输入您想备注的东西：\n");
    return ;
}
inline void insert_had(){
    printf("插入新的DDL成功，请进行接下来的操作\n");
    return ;
}
/*insert part end*/



/*dele part begin*/
inline void dele_init();
inline int  dele_UI(int tot);

inline void dele_init(){
    printf("请选择要删除的DDL\n");
    return ;
}
inline int dele_UI(int tot){
    flag4:
    printf("请选择要删除的DDL编号:");
    int noo=0;
    scanf("%d",&noo);
    if(noo>tot||noo<=0){
        printf("您输入的DDL编号错误，请重新输入DDL编号\n");
        goto flag4;
    }
    return noo;
}
/*dele part end*/

/*wrout part begin*/
inline void wrout1_UI_init();

inline void wrout1_UI_init(){
    printf("以下是所有有效DDL的标号：\n");
}
/*wrout part end*/

/*munu part begin*/
//***
/*munu part start*/
#endif