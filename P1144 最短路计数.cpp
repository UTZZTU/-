#include <bits/stdc++.h>
using namespace std;
const int maxn=1000000+1,MOD=100003;
int dep[maxn],cnt[maxn];
bool visit[maxn];
vector<int> G[maxn];
int main ()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	queue<int> q;
	dep[1]=0;
	visit[1]=1;
	cnt[1]=1;
	q.push(1);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int i=0;i<G[x].size();i++)
		{
			int v=G[x][i];
			if(!visit[v])
			{
				visit[v]=1;
				dep[v]=dep[x]+1;
				q.push(v);
			}
			if(dep[v]==dep[x]+1)
			{
				cnt[v]=(cnt[v]+cnt[x])%MOD;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d\n",cnt[i]);
	}
	return 0;
}