#include <bits/stdc++.h>
using namespace std;
const double Eps = 1e-8;
const double PI = atan(-1.0);
const int N = 1e6+5;
const int MOD = 1e9+7;

#define pb push_back
#define pf push_front
#define cl clear
#define fi first
#define se second
#define bg begin
#define ed end
#define sz size
#define fd find
#define is insert
#define PI pair<int,int>
#define PS pair<string,string>
#define Um unordered_map
#define Us unordered_set
#define Mul multiset<int>
#define VI vector<int>
#define VII vector< vector<int> > 
#define VS vector<string>
#define VN vector<node>
#define VP vector< pair<int,int> >
#define debug(x) cout<<"x"<<'\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0)
#define Mem(x) memset(x,0,sizeof x)
#define no cout<<"NO"<<'\n'
#define yes cout<<"YES"<<'\n'
#define pr(x) cout<<x<<'\n'

using ll = long long;
using u32 = unsigned int;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;
using f128 = __float128;



//bool cmp(node x,node y)
//{
//	return x.num<y.num;
//}

int qmi(int a,int b,int mod)
{
	int res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res;
}

int qmi(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1) res=res*a;
		b>>=1;
		a=a*a;
	}
	return res;
}

int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
struct node
{
	ll l,d,k,c,a;
};
struct Node
{
	ll t,pos,l,d,k;
	inline bool operator<(const Node &x)const
	{
		return t<x.t;
	}
};
vector<node> vec[200010];
priority_queue<Node> q;
ll n,m,f[200010],vis[200010];
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		f[i]=-1;
	}
	for(int i=1;i<=m;i++)
	{
		node u;
		int v;
		cin>>u.l>>u.d>>u.k>>u.c>>u.a;
		cin>>v;
		vec[v].emplace_back(u);
	}
	q.push({0,n,-1,-1,-1});
	while(!q.empty())
	{
		auto p=q.top();
		q.pop();
		if(vis[p.pos]) continue;
		vis[p.pos]=1;
		f[p.pos]=p.t;
		for(int i=0;i<vec[p.pos].sz();i++)
		{
			auto v=vec[p.pos][i];
			if(p.pos==n)
			{
				q.push({v.l+(v.k-1)*v.d,v.a,v.l,v.d,v.k});
			}
			else
			{
				if(p.t-v.c<v.l)
				{
					;
				}
				else
				{
					ll x=p.t-v.c-v.l;
					x=x/v.d;
					q.push({v.l+min(x,v.k-1)*v.d,v.a,v.l,v.d,v.k});
				}
			}
		}
	}
	for(int i=1;i<n;i++)
	{
		if(f[i]==-1)
		{
			cout<<"Unreachable"<<endl;
		}
		else cout<<f[i]<<endl;
	}
}
int main ()
{
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	IOS;
	int _=1;
//	cin>>_;
	while(_--)
	{
		solve();
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}