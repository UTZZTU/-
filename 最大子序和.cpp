#include<iostream>
#include<cstdio>
using namespace std;
int n,m,ans=0,s[300001],q[300001];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        s[i]=s[i-1]+x;
    }
    int hd=1,tl=1;
    for(int i=1;i<=n;i++)
    {
        if(i-q[hd]>m)
            hd++;
        ans=max(ans,s[i]-s[q[hd]]);
        while(hd<=tl&&s[q[tl]]>=s[i])
            tl--;
        tl++;
        q[tl]=i;
    }
    printf("%d\n",ans);
	return 0;
}