#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,v[200010],k,f[200010],cnt,ans,pre[200010];
vector<ll> vec[200010];
priority_queue<ll> q;
void dfs(int x)
{
	if(pre[x]==x)
	f[x]=1;
	else
	f[x]=1+f[pre[x]];
	q.push(f[x]);
	for(int i=0;i<vec[x].size();i++)
	{
		dfs(vec[x][i]);
	}
	return;
}
int main ()
{
	scanf("%lld",&n);
	pre[1]=1;
	f[1]=1;
	for(int i=2;i<=n;i++)
	{
		scanf("%lld",&k);
		vec[k].push_back(i);
		pre[i]=k;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&v[i]);
	}
	sort(v+1,v+1+n);
	dfs(1);
	cnt=n;
	while(!q.empty())
	{
		ans+=q.top()*v[cnt];
		cnt--;
		q.pop();
	}
	cout<<ans;
	return 0;
}