#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define PII pair<int, int>
#define fast ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define PIII pair<int, PII>
#define x first
#define y second
const int N = 110;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};//方向
struct node
{
	int x, y, z;
};
int dist[N][N];
int f[110][110];
PII path[N][N];//记录僵尸路径 
bool vis[N][N];
vector<node> v;//记录僵尸 
int cnt[N][N];//记录走过的步数
vector<PII> p[4 * N];//记录每个僵尸的路线 
int num[4 * N];//僵尸人数 
map<PII, int> mp;
int now[N * 4];
int idx = 1;
int n, m, T;

int get(PII xx)
{
    if(mp[xx] == 0) mp[xx] = idx++ ;//因为前面判断就是用的等于0，所以下标要从1开始 
    return mp[xx];
}
///*
void dij(PII u)
{
	memset(dist, 0x3f, sizeof dist);
	priority_queue<PIII, vector<PIII>, greater<PIII>> q;
	
	dist[u.x][u.y] = 0;
	q.push({0, u});
	while(q.size())
	{
		auto t = q.top();
		q.pop();
		
		if(vis[t.y.x][t.y.y]) continue;
		
		vis[t.y.x][t.y.y] = 1;
		
		auto tt = t.y;
		for(int i=0; i<4; i++)
		{
			int xx = tt.x + dx[i];
			int yy = tt.y + dy[i];
			
			if(xx > n || xx < 1 || yy > m || yy < 1) continue;
			
			if(dist[xx][yy] > dist[tt.x][tt.y] + f[xx][yy])
			{
				dist[xx][yy] = dist[tt.x][tt.y] + f[xx][yy];
				cnt[xx][yy] = cnt[tt.x][tt.y] + 1;
				path[xx][yy] = tt;
				q.push({dist[xx][yy], {xx, yy}});
			}
			else if(dist[xx][yy] == dist[tt.x][tt.y] + f[xx][yy])
			{
				if(cnt[xx][yy] > cnt[tt.x][tt.y] + 1)
				{
					path[xx][yy] = tt;
					q.push({dist[xx][yy], {xx, yy}});
				}
			}
		}
	}
	
}
//*/
signed main()
{
	fast;
	cin >> n >> m >> T;
	PII start;
	for(int i=0; i<=n+1; i++)
	{
		for(int j=0; j<=m+1; j++)
		{
			cin >> f[i][j];
			if(i == 0 || j == 0 || i == n + 1 || j == m + 1)
			{
				if((i == 0 && j == 0) || (i == 0 && j == m+1) || (i == n+1 && j == 0) || (i == n+1 && j == m+1)) continue;
				else v.push_back({i, j, f[i][j]});
			} 
			
			if(f[i][j] < 0) start = {i, j};
		}
	}
//	/*
	dij(start);
//	/*
	for(auto i : v)
	{
		int id = get({i.x, i.y});
		num[id] = i.z;
		PII kk;
	    for(int j = 0 ; j < 4 ; j++) //由僵尸边上走到地图里面去
            if(i.x + dx[j] >= 1 && i.x + dx[j] <= n && i.y + dy[j] >= 1 && i.y + dy[j] <= m)
			{
                kk.x = i.x + dx[j] , kk.y = i.y  + dy[j];
                break ;
			}
			
		while(1)
		{
            p[id].push_back(kk);
            if(kk.x == start.x && kk.y == start.y) break;//找到大本营的位置了
            kk = path[kk.x][kk.y];
        }
    }
    
//    /*
    for(int t = 1; t <= T; t ++)
    {
//    	memcpy()
    	set<PII> s;
    	for(auto i : v)
    	{
    		int id = get({i.x, i.y});
    		
    		if(num[id] == 0) continue;
    		
    		int xx = p[id][now[id]].x;
    		int yy = p[id][now[id]].y;
    		
    		if(f[xx][yy] > 0 && (xx != start.x || yy != start.y)) s.insert({xx, yy});
    		else if(f[xx][yy] < 0 && (xx == start.x && yy == start.y)) s.insert({xx, yy});
		}
		
		for(auto i : v)
		{
			int id = get({i.x, i.y});
			
			if(num[id] == 0) continue;
			
            int xx = p[id][now[id]].x;
    		int yy = p[id][now[id]].y;
    		
    		if(s.count({xx, yy}) == 0) now[id] ++;//set中记录了哪些是炮台，所以不需要滚动数组优化 
    		else
    		{
    			if(f[xx][yy] > 0) f[xx][yy] --;//减到0就没了，不减了，根据输出来搞得 
    			else if(f[xx][yy] < 0) f[xx][yy]++;
    			num[id] --;
			}
			
		}
		
		if(f[start.x][start.y] == 0) break;
	}
//	*/
	 for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
        	cout << f[i][j];
            if(j < m) cout << " ";
            else cout << endl;
		}
            
    if(f[start.x][start.y] == 0) cout << "Game Over" << endl;
	return 0;
}
