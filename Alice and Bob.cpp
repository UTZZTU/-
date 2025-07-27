#include<iostream>
#include<stdio.h>
using namespace std;
bool f[5001][5001];
int main()
{    
    for(int i=0;i<=5000;i++)//自小到大枚举i，j
    for(int j=0;j<=5000;j++)
    {
        if(f[i][j]==0)//对于每种必败态进行拓展
        {//f[i][j]与f[j][i]是等价的
            for(int k=1;k+i<=5000;k++)for(int s=0;s*k+j<=5000;s++)f[i+k][j+s*k]=1;
            for(int k=1;k+j<=5000;k++)for(int s=0;s*k+i<=5000;s++)f[i+s*k][j+k]=1;
        }
    }
    int t,n,m;
    cin>>t;
    while(t--)
    {
       scanf("%d%d",&n,&m);
        if(f[n][m]==0)
        {
            puts("Bob");
        }
        else 
            puts("Alice");
     }
    return 0;
}