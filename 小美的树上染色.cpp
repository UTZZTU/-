#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[100010],vis[100010],u,v,s;
vector<int> vec[100010];
bool judge(int x,int y)
{
	ll p=floor(sqrt(a[x]*a[y]));
	return p*p==a[x]*a[y];
}
//bool check(int x)
//{
//	ll p=floor(sqrt(a[x]));
//	return p*p==a[x];
//}
//struct node
//{
//	int u,v,w;
//}e[100010];
//bool cmp(node x,node y)
//{
//	return x.w<y.w;
//}
int dfs(int u,int p)
{
	int res=0;
	for(int i=0;i<vec[u].size();i++)
	{
		if(vec[u][i]==p) continue;
		int t=dfs(vec[u][i],u);
		if(!vis[u]&&!vis[vec[u][i]]&&judge(u,vec[u][i]))
		{
			vis[u]=vis[vec[u][i]]=1;
			res+=2;
		}
		res+=t;
	}
	return res;
}
int main ()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<n;i++)
	{
		scanf("%lld%lld",&u,&v);
//		e[i].u=u,e[i].v=v,e[i].w=0;
//		if(check(u)) e[i].w++;
//		if(check(v)) e[i].w++;
		vec[u].push_back(v);
		vec[v].push_back(u);
//		cnt[u]++,cnt[v]++;
	}
//	for(int i=1;i<=n;i++)
//	{
//		if(cnt[i]==1)
//		{
//			s=i;
//			break;
//		}
//	}
//	sort(e+1,e+n,cmp);
//	for(int i=1;i<n;i++)
//	{
//		u=e[i].u,v=e[i].v;
//		if(!vis[u]&&!vis[v]&&judge(u,v))
//		{
//			vis[u]=vis[v]=1;
//			res+=2;
//		}
//	}
	cout<<dfs(1,0);
//	cout<<res;
	return 0;
}
/*
5
3 3 3 3 3
2 3
1 2
3 4
3 5
*/