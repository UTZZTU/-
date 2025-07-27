#include<bits/stdc++.h>
using namespace std;
int n,xx[110], yy[110];
int X=100,Y=100;                  //中心点(X,Y)，从它出发
bool vis[210][210];
bool bfs(int x,int y){             //从(x,y)出发，把可以到达的点全部打上标记
    vis[x][y] = true;              //把当前点标记为已达
    queue<pair<int,int>>q;
    q.push({x,y});
    while(q.size())    {
        auto t = q.front();
        q.pop();
        if(vis[X-1][Y] && vis[X+1][Y] && vis[X][Y-1] && vis[X][Y+1])  return true;
        for(int i=1;i<=n;i++)  {     //遍历n个方向
            int nx = t.first+xx[i], ny = t.second+yy[i];
            if(nx < 1 || nx > 200 || ny < 1 || ny > 200)  continue;  //判断越界
            if(vis[nx][ny])  continue;    //已经走过，不用再走
            vis[nx][ny] = true;
            q.push({nx,ny});
        }
    }
    return false;
}
int main(){
    int T; cin>>T;
    while(T--){
        cin>>n;
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++)      cin>>xx[i]>>yy[i];
        if(bfs(X,Y)) cout<<"Yes\n";
        else         cout<<"No\n";

    }
    return 0;
}

