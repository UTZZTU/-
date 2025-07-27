#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,u,v,f[100010],k,vis[100010],tt[100010],t[100010],cnt,num,flag,judge,res;
vector<ll> vec[100010];
void dfs(int x)
{
	if(f[x])
	flag=1;
	vis[x]=1;
	num++;
	for(int i=0;i<vec[x].size();i++)
	{
		if(vis[vec[x][i]])
		continue;
		dfs(vec[x][i]);
	}
	return;
}
int main ()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld",&u,&v);
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&f[i]);
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i])
		continue;
		num=0;
		flag=0;
		dfs(i);
		if(flag)
		judge++;
		tt[++cnt]=num;
		t[cnt]=flag;
	}
	if(judge>=2)
	cout<<0;
	else if(judge==1)
	{
		for(int i=1;i<=cnt;i++)
		{
			if(t[i])
			{
				cout<<tt[i]*tt[i];
				return 0;
			}
		}
	}
	else
	{
		for(int i=1;i<=cnt;i++)
		{
			res+=tt[i]*tt[i];
		}
		cout<<res;
	}
	return 0;
}