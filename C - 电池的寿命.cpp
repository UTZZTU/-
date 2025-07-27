#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int main()
{
    int n,a[1005];
    while(scanf("%d",&n)!=EOF) //无限输入
    {
        int max=-1,sum=0;//max储存用时最长的那节电池，sum存储其他电池的用时总和
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i]; //求和
            if(max<a[i]) max=a[i]; //找出用时最长的那节电池
        }
        if((sum-max)<max)
        {
            printf("%.1f\n",(sum-max)*1.0); //保留一位小数输出
        }
        else
        {
            printf("%.1f\n",(sum-max-max)*1.0/2+max);//输出对应的结果
        }
    }
    return 0;//完美结束
} 
