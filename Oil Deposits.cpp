#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int sum,n,m;
int k;
char map[105][105];
int dx[10]={-1,1,0,0,-1,1,-1,1};
int dy[10]={0,0,-1,1,-1,-1,1,1};
void dfs(int x,int y)
{
    if(x<0||x>=n||y<0||y>=m) return ;
    if(map[x][y]=='@')
    {
        map[x][y]='*';
        for(int i=0;i<8;i++)
        {
            dfs(x+dx[i],y+dy[i]);
           // map[x][y]='@';
        }
    }
}
 
 
int main(void)
{
   // freopen("H.txt","r",stdin);
   // int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(m==0||n==0) break;
        for(int i=0;i<n;i++)
        {
          //  getchar();
            for(int j=0;j<m;j++)
            {
                cin>>map[i][j];
            }
        }/*
        for(int i=0;i<n;i++)
        {
           // getchar();
            for(int j=0;j<=m;j++)
            {
                printf("%c",map[i][j]);
            }
            printf("\n");
        }*/
        sum=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(map[i][j]=='@')
                {
                    sum++;
                    dfs(i,j);
                }
            }
        }
        printf("%d\n",sum);
 
    }
 
    return 0;
}