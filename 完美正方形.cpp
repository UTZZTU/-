#include<cstdio>
#include<cstring>
#include<cctype>
#include<string>
#include<set>
#include<iostream>
#include<stack>
#include<cmath>
#include<queue>
#include<vector>
#include<algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define mod 10000007
#define debug() puts("whatthefuck!!!")
#define N 1111111
#define M 1000000
#define ll longlong
using namespace std;
int a[19]= {2,5,9,11,16,17,19,21,22,24,26,30,31,33,35,36,41,50, 52};
int map[154][154];
int vis[100];
void fill(int x,int y,int n,int num)
{
    for(int i=x; i<x+n; i++)
        for(int j=y; j<y+n; j++)
            map[i][j]=num;
}
int solve()
{
    for(int i=0; i<154; i++)
        for(int j=0; j<154; j++)
            if(!map[i][j])
                return 0;
    return 1;
}
int judge(int x,int y,int n)
{
    if(x+n>154||y+n>154)
        return 0;
    for(int i=x; i<n+x; i++)
        for(int j=y; j<n+y; j++)
            if(map[i][j])
                return 0;
    return 1;
}
int dfs(int x,int y)
{
    if(solve())
        return 1;
    else
    {
        int flag=1;
        for(int i=0; i<154&&flag; i++)
            for(int j=0; j<154&&flag; j++)
                if(!map[i][j])
                    x=i,y=j,flag=0;
        for(int k=0; k<19; k++)
        {
            if(judge(x,y,a[k]))
            {
                if(!vis[k])
                {
                    fill(x,y,a[k],a[k]);
                    vis[k]=1;
                    if(dfs(x,y+a[k]))
                        return 1;
                    fill(x,y,a[k],0);
                    vis[k]=0;
                }
            }
            else
                break;
        }
    }
    return 0;
}
int main()
{
    mem(map,0);
    mem(vis,0);
    fill(0,0,47,47);
    fill(0,47,46,46);
    fill(0,93,61,61);
    dfs(0,0);
    int ans=0;
    for(int i=0; i<154; i++)
    {
        if(map[153][i]!=ans)
        {
            printf("%d ",map[153][i]);
            ans=map[153][i];
        }
    }
    return 0;
}
