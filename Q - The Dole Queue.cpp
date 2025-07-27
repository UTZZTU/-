#include <iostream>
#include <stdio.h>
#include <string.h>
int peo[30],n;
int go(int post,int d,int step)
{
    int cnt=0;
    while(cnt!=step)
    {
        post=(post+d+n)%n;
        if(peo[post]!=0)
            cnt++;
    }
    return post;
}
int main()
{
    int k,m;
    while(scanf("%d%d%d",&n,&k,&m)&&n&&k&&m)
    {
        memset(peo,0,sizeof(peo));
        int p1=n-1,p2=0,left=n;
        for(int i=0;i<n;i++)
            peo[i]=i+1;
        while(left)
        {
            p1=go(p1,1,k);
            p2=go(p2,-1,m);
            left--;
            printf("%3d",peo[p1]);
            if(p1!=p2)
            {
                printf("%3d",peo[p2]);
                left--;
            }
            if(left)
            {
                printf(",");
            }
            peo[p1]=peo[p2]=0;
        }
        printf("\n");
    }
}
