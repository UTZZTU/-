#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define int long long
int n,m,k,minn=0x3f3f3f3f3f3f3f3f;
struct node
{
	int u,v,w;
}s[100];
void dfs(int pos,map<int,int> mp,int res,int cnt)
{
	if(cnt==n-1)
	{
		minn=min(minn,res%k);
		return;
	}
	if(pos>m) return;
	int u=s[pos].u,v=s[pos].v;
	int eu=u,ev=v;
	while(mp[eu]!=eu)
	{
		eu=mp[eu];
	}
	while(mp[ev]!=ev)
	{
		ev=mp[ev];
	}
	if(eu!=ev)
	{
		mp[eu]=ev;
		dfs(pos+1,mp,(res+s[pos].w)%k,cnt+1);
		mp[eu]=eu;
	}
	dfs(pos+1,mp,res,cnt);
}
signed main ()
{
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&s[i].u,&s[i].v,&s[i].w);
	}
	map<int,int> mp;
	for(int i=1;i<=n;i++)
	{
		mp[i]=i;
	}
	dfs(1,mp,0,0);
	printf("%lld\n",minn);
	return 0;
}