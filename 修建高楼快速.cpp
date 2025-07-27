#include<bits/stdc++.h>
using namespace std;
int n,m,a[5000010],j,k,ans2,ans1,h[100000],i,b,ans;
int main()
{
    scanf("%d%d",&n,&m);
    for (k=1;k<=n;k++)
    {
        ans1=0;
        memset(a,0,sizeof(a));
        for (j=1;j<=m;j++)
    {
        scanf("%d",&h[j]);
        a[h[j]+5000]=j;
    }
    for (i=1;i<=m;i++)
        for (j=i+1;j<=m;j++)
        if (a[h[j]*2-h[i]+5000]>j) ans1++;
    if (ans1>ans){
        ans=ans1;
        ans2=k;
    }
    }
    printf("%d %d\n",ans2,ans);
}

