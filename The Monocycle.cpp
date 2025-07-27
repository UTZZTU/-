/*
* @Author: SamsonHo
* @Date:   2018-10-09-09.28
* @URL:https://vjudge.net/problem/UVA-10047
* @Note:
*/
#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
const int MAXN = 30+10;
char a[MAXN][MAXN];
int n,m,book[MAXN][MAXN][4][5];
int dirx[] = {-1,0,1,0};
int diry[] = {0,1,0,-1};
struct node
{
    int x,y,dir,color;
    node(int x = 0, int y = 0, int dir = 0, int color = 0):x(x),y(y),dir(dir),color(color) {}
};
queue<node> que;
 
int bfs()
{
    int sx,sy,ex,ey;
    memset(book,-1,sizeof book);
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            if(a[i][j] == 'S')
                sx = i,sy = j;
            else if(a[i][j] == 'T')
                ex = i,ey = j;
        }
    }
    while(!que.empty())   que.pop();
    book[sx][sy][0][0] = 0;
    que.push(node(sx,sy,0,0));
    node top;
    int cur,nx,ny,col;
    while(!que.empty())
    {
        top = que.front();
        que.pop();
        if(top.x == ex && top.y == ey && top.color == 0) //走到终点并且状态符合
            return book[top.x][top.y][top.dir][top.color];
        cur = book[top.x][top.y][top.dir][top.color];
        nx = dirx[top.dir]+top.x,ny = diry[top.dir]+top.y,col = (top.color+1)%5;
        //按当前方向前进一步
        if(book[nx][ny][top.dir][col] == -1 && a[nx][ny] != '#' && nx>0 && nx<=n && ny>0 && ny<=m)
        {
            que.push(node(nx,ny,top.dir,col));
            book[nx][ny][top.dir][col] = cur+1;
        }
 
        if(book[top.x][top.y][(top.dir+1)%4][top.color] == -1)//右转
        {
            book[top.x][top.y][(top.dir+1)%4][top.color] = cur+1;
            que.push(node(top.x,top.y,(top.dir+1)%4,top.color));
        }
        if(book[top.x][top.y][(top.dir+3)%4][top.color] == -1)//左转  需要注意不要减成负数，所以是+3
        {
            book[top.x][top.y][(top.dir+3)%4][top.color] = cur+1;
            que.push(node(top.x,top.y,(top.dir+3)%4,top.color));
        }
 
    }
    return -1;
}
int main(void)
{
    int kase = 0;
    while(~scanf("%d%d",&n,&m) && n+m)
    {
        for(int i = 1; i <= n; ++i)
            scanf("%s",a[i]+1);
        int ans = bfs();
        if(kase)    puts("");
        printf("Case #%d\n",++kase);
        if(ans == -1)
            puts("destination not reachable");
        else
            printf("minimum time = %d sec\n",ans);
    }
}