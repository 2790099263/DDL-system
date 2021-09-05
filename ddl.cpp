#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<fstream>
#include<ctime>
#include"litUI.h"
using namespace std;

const int MAXN=105;
const int MAXM=10005;
struct ti{
    int year,month,day;
    int hour,min,sec;
    bool jue;//是否定时通知；
};
struct node{    
    ti time;
    char s[MAXN];
    char bei[MAXN];
    int no;
    bool hasdone;  //是否已经做过了时间戳
    inline void clear(){
        time.year=time.month=time.day=0;
        return ;
    }
};
node cu[MAXM];
int tot;
//重载sort内部函数；
bool sort_in(node a,node b){
    if(a.time.year==b.time.year){
        if(a.time.month==b.time.month){
            if(a.time.day==b.time.day){
                if(a.time.hour==b.time.hour){
                    if(a.time.min==b.time.min){
                        return a.time.sec<b.time.sec;
                    }
                    else return a.time.min<b.time.min;
                }
                else return a.time.hour<b.time.hour;
            }
            else return a.time.day<b.time.day;

        }
        else return a.time.month<b.time.month;
    }
    else return a.time.year<b.time.year;
}
inline void read();
inline void sort_it();
inline void debug();
inline void insert();
inline void dele();
inline void swapp (node &a,node &b);
inline void wrout1();
inline void munu();
inline void cun();
/*
function cun had been updated;
2021/9/5
*/
inline void cun(){
    ofstream fout;
    fout.open("cun.txt");
    fout<<tot<<endl;
    for(int i=1;i<=tot;i++)
    {
        fout<<cu[i].no<<" "<<cu[i].time.year<<" "<<cu[i].time.month<<" "
        <<cu[i].time.day<<" "<<cu[i].time.hour<<" "<<cu[i].time.min
        <<" "<<cu[i].time.sec<<" "<<cu[i].time.jue<<" "<<cu[i].s<<" "<<cu[i].bei<<endl;
    }
    return ;
}

/*
swap didn't need to update 2021/9/5
*/
inline void swapp(node &a,node &b){
    node c;
    c=a;a=b;b=c;
    // c.time=a.time;c.s=a.s;c.no=a.no;c.bei=a.bei;
    // a.time=b.time;a.s=b.s;a.no=b.no;a.bei=b.bei;
    // b.time=c.time;b.s=c.s;b.no=c.no;b.bei=c.bei;
    return ;

}
/*
function read have been updated 2021/9/5 20:00
need time mark 2021/9/5 20:53
*/
inline void read(){
    ifstream fin;
    fin.open("cun.txt");
    fin>>tot;
    // if(tot==0)init();
    for(int i=1;i<=tot;i++){
        fin>>cu[i].no;
        fin>>cu[i].time.year>>cu[i].time.month>>cu[i].time.day;
        fin>>cu[i].time.hour>>cu[i].time.min>>cu[i].time.sec;
        fin>>cu[i].time.jue;
        fin>>cu[i].s;
        fin>>cu[i].bei;
    }
    sort_it();
}
//按照时间线排序；
inline void sort_it(){
    sort(cu+1,cu+tot+1,sort_in);
    for(int i=1;i<=tot;i++){
        cu[i].no=i;
    }
    return ;
}
inline void debug(){
    for(int i=1;i<=tot;i++)
    {
        printf("%d / %d / %d / %d / %d / %d"
                        ,cu[i].time.year
                        ,cu[i].time.month
                        ,cu[i].time.day
                        ,cu[i].time.hour
                        ,cu[i].time.min
                        ,cu[i].time.sec);
        cout<<"事件: "<<cu[i].s<<"  "<<"备注："<<cu[i].bei<<endl;
        if(cu[i].time.jue==0)printf("未在通知队列中\n");
        else printf("已在通知队列中\n");
        
    }
    printf("debug函数结束！\n\n");
}
/*
insert function update at 2021.9.1 11:55
更新了时分秒和定时推送
*/
inline void insert(){
    int li_year=0,li_month=0,li_day=0;
    li_year=insert_UI_year();
    li_month=insert_UI_month();
    li_day=insert_UI_day(li_month,li_year);
    tot++;
    cu[tot].time.year=li_year;
    cu[tot].time.month=li_month;
    cu[tot].time.day=li_day;
    cu[tot].no=tot;
    int jud_ic=insert_UI_jud();
    if(jud_ic==1){ //是否输入时分秒；
        cu[tot].time.hour=insert_gethour();
        cu[tot].time.min=insert_getmin();
        cu[tot].time.sec=insert_getsec();
        int jud_is=insert_UI_jud2(); //是否开启定时推送；
        if(jud_is==1){
            cu[tot].time.jue=1;
        }
        else cu[tot].time.jue=0;
    }
    else {
        cu[tot].time.hour=-1;
        cu[tot].time.min=-1;
        cu[tot].time.sec=-1;
        cu[tot].time.jue=0;
    }
    insert_UI_s();
    cin>>cu[tot].s;
    insert_UI_bei();
    cin>>cu[tot].bei;
    sort_it();
    insert_had();
    cun();
}
/*
delete system has not been updated;
*/
inline void dele()
{
    dele_init();
    for(int i=1;i<=tot;i++)
    {
        printf("    >  No: %d   %d / %d / %d / %d / %d / %d\n"
                                            ,cu[i].no
                                            ,cu[i].time.year
                                            ,cu[i].time.month
                                            ,cu[i].time.day
                                            ,cu[i].time.hour
                                            ,cu[i].time.min
                                            ,cu[i].time.sec);
        cout<<"        事项： "<<cu[i].s<<endl;
        cout<<"        备注： "<<cu[i].bei<<endl;
        cout<<endl;
    }
    int noo=dele_UI(tot);
    printf("noo : %d\n",noo);
    swapp(cu[noo],cu[tot]);
    debug();
    cu[tot].clear();
    tot--;
    sort_it();
    cun();
    return ;
}
/*
wrout1 need to update;
*/
inline void wrout1(){
    wrout1_UI_init();
    for(int i=1;i<=tot;i++)
    {
        printf("    >  No: %d   %d / %d / %d / %d / %d / %d\n"
                                            ,cu[i].no
                                            ,cu[i].time.year
                                            ,cu[i].time.month
                                            ,cu[i].time.day
                                            ,cu[i].time.hour
                                            ,cu[i].time.min
                                            ,cu[i].time.sec);
        cout<<"        事项： "<<cu[i].s<<endl;
        cout<<"        备注： "<<cu[i].bei<<endl;
        cout<<endl;
    }
    int l=0,r=0;
    printf("请输入需要导出的编号区间：\n");
    printf("请输入DDL左端点：");scanf("%d",&l);printf("\n");
    printf("请输入DDL右端点：");scanf("%d",&r);printf("\n");
    printf("正在导出..\n");
    ofstream fout;
    fout.open("test.txt");
    for(int i=l;i<=r;i++)
    {
        fout<<">  项目编号 NO："<<cu[i].no<<" 时间： "<<
        cu[i].time.year<<"-"<<cu[i].time.month<<"-"<<cu[i].time.day
        <<"-"<<cu[i].time.hour<<"-"<<cu[i].time.min<<"-"<<cu[i].time.sec<<endl;
        fout<<"        事项： "<<cu[i].s<<endl;
        fout<<"        备注： "<<cu[i].bei<<endl;
        fout<<endl;
    }
    fout<<"请注意以上事件的DDL！！"<<endl;
    system("python3 main.py");
}
inline void munu()
{
    flag5:
    printf("请选择需要进行的操作编号\n  1.insert\n  2.delete\n  3.write out\n   4.debug\n   5.exit\n");
    int y=0;
    scanf("%d",&y);
    // printf("y %d\n",y);
    if(y>5){
        printf("您输入的编号错误，请重新输入\n");
        goto flag5;
    }
    if(y==1)
    {
        insert();
        goto flag5;
    }
    if(y==2)
    {
        dele();
        goto flag5;
    }
    if(y==3)
    {
        wrout1();
        goto flag5;
    }
    if(y==4)
    {
        debug();
        goto flag5;
    }
    if(y==5)
    {
        exit(0);
    }
}
int main(){
    read();
    // debug();
    munu();
    return 0;
}