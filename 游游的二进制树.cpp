#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s[1010][1010],u;
ll n,l,r,res,x,y,vis[1010];
vector<ll> vec[1010];
struct node
{
	vector<char> v;
	ll pos;
};
ll sum(vector<char> v)
{
	ll k=1,num=0;
	for(ll i=v.size()-1;i>=0;i--)
	{
		if(v[i]=='1')
		{
			num+=k;
		}
		k*=2;
		if(num>r) break;
	}
	if(num>=l&&num<=r) return (ll)1;
	else return (ll)0;
}
void bfs(int num)
{
	vector<char> vv;
	queue<node> q;
	vv.push_back(u[num-1]);
	q.push({vv,num});
	while(!q.empty())
	{
		node t=q.front();
		q.pop();
		if(vis[t.pos]) continue;
		vis[t.pos]=1;
		if(t.v.size()>1)
		{
			res+=sum(t.v);
		}
		for(int i=0;i<vec[t.pos].size();i++)
		{
			t.v.push_back(u[vec[t.pos][i]-1]);
			q.push({t.v,vec[t.pos][i]});
			t.v.pop_back();
		}
	}
}
int main ()
{
	scanf("%d%d%d",&n,&l,&r);
	getchar();
	cin>>u;
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		vec[x].push_back(y);
		vec[y].push_back(x);
	}
	for(int i=1;i<=n;i++)
	{
		bfs(i);
		memset(vis,0,sizeof(vis));
	}
	cout<<res;
	return 0;
}