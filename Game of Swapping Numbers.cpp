#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005];
long long ans=0;
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
       scanf("%d",&a[i]);
    if(n==2)//特判断n==2,必须交换
    {
        while(k--)
        swap(a[1],a[2]);
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&b[i]);
        if(a[i]>b[i])swap(a[i],b[i]);//b[i]为相同下标较大值max（ai，bi），a[i]为相同下标较大值min（ai，bi）
        ans+=b[i]-a[i];//第一部分求和，不交换的贡献值
    }
    sort(a+1,a+1+n);//排序
    sort(b+1,b+1+n);
    for(int i=1;i<=k&&i<=n;i++)
    {  int t;
        t=2*(a[n+1-i]-b[i]);//取交换贡献最大的
        if(t>0)ans+=t;
        else break;//如果交换贡献小于0剩下都是无意义交换即可退出循环
    }
    cout<<ans;
}