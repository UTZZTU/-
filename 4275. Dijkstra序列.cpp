#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
const int INF = 0x3f3f3f3f;
int n,m,g[N][N],dist[N],vis[N];
int q[N];
bool dijkstra()
{
	memset(dist,0x3f,sizeof(dist));
	memset(vis,0,sizeof(vis));
	dist[q[0]]=0;
	for(int i=0;i<n;i++)
	{
		int t=q[i];
		for(int j=1;j<=n;j++)
		if(!vis[j]&&dist[j]<dist[t])
		return false;
		vis[t]=1;
		for(int j=1;j<=n;j++)
		dist[j]=min(dist[j],dist[t]+g[t][j]);
	}
	return true;
}
int main ()
{
	memset(g,0x3f,sizeof(g));
	scanf("%d %d",&n,&m);
	while(m--)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		g[a][b]=g[b][a]=c;
	}
	int k;
	cin>>k;
	while(k--)
	{
		for(int i=0;i<n;i++)
		scanf("%d",&q[i]);
		if(dijkstra())
		puts("Yes");
		else
		puts("No");
	}
	return 0;
}