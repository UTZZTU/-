//7-4 猛犸不上Ban
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int N = 510, INF = 0x3f3f3f3f, M = 1e5 + 10;

int n, m, s, t;
int G[N][N];
bool st[N][N];
bool vis[N], st1[N];
int dist[N], pre[N], dist1[N];
int ans1 = INF, ans2 = INF;

void dijkstra(int x)
{
	memset(dist1, 0x3f, sizeof dist1);
	memset(st1, 0, sizeof st1);
	dist1[s] = 0;
	
	while(true)
	{
		int t = -1;
		for(int i = 1; i <= n; i++)
			if(!st1[i] && (t == -1 || dist1[t] > dist1[i]))
				t = i;
		
		if(t == -1 || t == x)
			break;
		
		st1[t] = true;
		for(int i = 1; i <= n; i++)
		{
			if(st[i][t])
				continue;
			
			if(dist1[i] > dist1[t] + G[t][i])
				{
					dist1[i] = dist1[t] + G[t][i];

				}
		}
	}
}

int main()
{
	memset(G, 0x3f, sizeof G);
	memset(pre, -1, sizeof pre);
	memset(dist, 0x3f, sizeof dist);
	
	scanf("%d %d %d %d", &n, &m, &s, &t);
	for(int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		G[a][b] = G[b][a] = min(G[a][b], c);
	}
	
	dist[s] = 0;
	while(true)
	{
		int t = -1;
		for(int i = 1; i <= n; i++)
			if(!st1[i] && (t == -1 || dist[t] > dist[i]))
			t = i;
		
		if(t == -1)
			break;
		
		st1[t] = true;
		for(int i = 1; i <= n; i++)
		{
			if(dist[i] > dist[t] + G[t][i])
			{
				dist[i] = dist[t] + G[t][i];
				pre[i] = t;
			}
		}
	}
	
//	for(int i = 1; i <= n; i++)
//		cout << i << ' ' << dist[i] << ' ' << pre[i] << endl;
	
	for(int i = 1; i <= n; i++)
	{
		if(i == s)
			continue;
		
		for (int x = pre[i], y = i; x != -1 ; y = pre[y], x = pre[x]) {
			st[x][y] = st[y][x] = true;
//			cout << x << ' ' << y << endl;
		}
		
		dijkstra(i);
		
//		cout << i << ' ' << dist[i] << ' ' << dist1[i] << endl;
		ans1 = min(ans1, dist[i] + dist1[i]);
		
		for (int x = pre[i], y = i; x != -1 ; y = pre[y], x = pre[x]) {
			st[x][y] = st[y][x] = false;
		}
	}
	
	if(ans1 == INF)
		printf("-1");
	else
		printf("%d", ans1);
	
	printf(" ");
	
	ans2 = dist[t];
	if(ans2 == INF)
		printf("-1");
	else
		printf("%d", ans2);
	
	puts("");
	ans1 < ans2 ? puts("Win!") : puts("Lose!");
	return 0;
}

