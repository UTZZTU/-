#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int N = 55;
int n,m;
char g[N][N];
bool st[N][N];
int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
vector<PII> a,b;
void bfs(int x,int y,int k)
{
    queue<PII> q;
    if(!k)a.push_back({x,y});
    else b.push_back({x,y});
    q.push({x,y});
    st[x][y]=true;
    while(q.size())
    {
        PII t=q.front();
        q.pop();
        int sx=t.first,sy=t.second;
        for(int i=0;i<4;++i)
        {
            int nx=sx+dx[i],ny=sy+dy[i];
            if(nx>=0&&nx<n&&ny>=0&&ny<m&&g[nx][ny]=='X'&&!st[nx][ny])
            {
                q.push({nx,ny});
                if(!k)a.push_back({nx,ny});
                else b.push_back({nx,ny});
                st[nx][ny]=true;
            }
        }
    }
}
int get(int x1,int y1,int x2,int y2)
{
    return abs(x1-x2)+abs(y1-y2);
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;++i)cin>>g[i];
    int t=0;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            if(g[i][j]=='X'&&!st[i][j])
            {
                bfs(i,j,t);
                t=1;
            }
    int res=1e9;
    for(int i=0;i<a.size();++i)
        for(int j=0;j<b.size();++j)
        {
            res=min(res,get(a[i].first,a[i].second,b[j].first,b[j].second));
        }
    cout<<res-1<<endl;
    return 0;
}