#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<string.h>
#include<queue>
using namespace std;
int mapp[500][500];
int vis[500],n;
bool dfs()
{
    queue<int>q;
    memset(vis,0,sizeof(vis));
    q.push(0);
    vis[0]=1;
    while(!q.empty())
    {
        int p=q.front();
        q.pop();
        for(int i=0; i<n; i++)
            if(mapp[p][i])
            {
                if(vis[i]==0)
                {
                    vis[i]=-vis[p];
                    q.push(i);
                }
                else if(vis[i]==vis[p])
                    return false;
            }
    }
    return true;
}
int main()
{
    while(~scanf("%d",&n)&&n)
    {
        int a,b;
        memset(mapp,0,sizeof(mapp));
        while(~scanf("%d%d",&a,&b)&&(a||b))
            mapp[a-1][b-1]=mapp[b-1][a-1]=1;
        printf(dfs()?"YES\n":"NO\n");
    }
    return 0;
}