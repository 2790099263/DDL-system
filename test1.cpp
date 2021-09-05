/*
test1.cpp 2021.9.1 11：57 update
测试时间管理函数使用
*/
#include<bits/stdc++.h>
#include<ctime>
using namespace std;
int main()
{
    time_t now = time(0);
    tm  *ltm =localtime(&now);
    cout<<1900 + ltm->tm_year<<endl;
    cout<<1 + ltm->tm_mon<<endl;
    cout<< ltm -> tm_mday<<endl;
    cout<<ltm->tm_hour<<":"<<ltm -> tm_min<<":"<< ltm -> tm_sec<<endl;
    return 0;
}