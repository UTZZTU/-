#include<cmath>
#include<iostream>
using namespace std;
int ti,gan,zhi,t,j;
int main()
{
    cin>>ti>>gan>>zhi>>t;
    for(j=t+1;j<=21252;j++)//从当前所给天数开始枚举
        if((j-ti)%23==0)
        break;
    for(;j<=21252;j+=23)//找到体力高峰期的第一天后周期要保证接下来每一天都是体力高峰期，周期就变成了23.
        if((j-gan)%28==0)
        break;
    for(;j<=21252;j+=23*28)//找到体力和感情高峰期后要保证接下来每一天都是这两个的高峰期，则周期为二者乘积
        if((j-zhi)%33==0)//找到三者同时的那一天结束循环
        break;
    cout<<j-t;//输出距开始时间所经过的天数
    return 0;
}

