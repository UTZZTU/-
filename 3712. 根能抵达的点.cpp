#include <bits/stdc++.h>
using namespace std;
struct node
{
	int v,w;
};
vector<node> e[20010];
int t,n,y,u,v,w,visit[20010],l,r,ans;
void dfs(int p,int l)
{
	visit[p]=1;
	ans++;
	for(int i=0;i<e[p].size();i++)
	{
		int to=e[p][i].v,len=e[p][i].w;
		if(visit[to]||len<l)
		continue;
		dfs(to,l);
	}
}
bool check(int x)
{
	ans=0;
	memset(visit,0,sizeof(visit));
	dfs(0,x);
	return ans<=y;
}
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		r=0x3f3f3f3f,l=0;
		scanf("%d %d",&n,&y);
		for(int i=1;i<n;i++)
		{
			scanf("%d %d %d",&u,&v,&w);
			e[u].push_back({v,w});
			e[v].push_back({u,w});
		}
		while(l<r)
		{
			int mid=(l+r)/2;
			if(check(mid))
			r=mid;
			else
			l=mid+1;
		}
		cout<<l<<endl;
		for(int i=0;i<n;i++)
		e[i].clear();
	}
	return 0;
}