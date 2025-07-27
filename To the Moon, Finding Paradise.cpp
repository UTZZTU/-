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
//using u32 = unsigned int;
//using u64 = unsigned long long;
//using i128 = __int128;
//using u128 = unsigned __int128;
//using f128 = __float128;

struct Node
{
	int num,pos;
}S[N];

bool Cmp(Node x,Node y)
{
	return x.num<y.num;
}

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

//cout<<fixed<<setprecision(x)
vector<PI> vec[100010];
ll n,m,s,t,c,v[100010],x,y,z,vis[200010];
bool bfs(int nul)
{
	for(int i=1;i<=n;i++) vis[i]=-1;
	priority_queue<PI> q;
	q.push({c-v[s],s});
	while(!q.empty())
	{
		auto p=q.top();
		q.pop();
		if(vis[p.se]>=0) continue;
		vis[p.se]=p.fi;
		for(int i=0;i<vec[p.se].sz();i++)
		{
			auto pp=vec[p.se][i];
			if(vis[pp.fi]==-1&&pp.se<=nul&&p.fi-v[pp.fi]>=0)
			{
				q.push({p.fi-v[pp.fi],pp.fi});
			}
		}
	}
	return vis[t]>=0;
}
void solve()
{
	cin>>n>>m>>s>>t>>c;
	for(int i=1;i<=n;i++) cin>>v[i];
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>z;
		vec[x].pb({y,z});
	}
	int l=1,r=1e9;
	while(l<r)
	{
		int mid=l+r>>1;
		if(bfs(mid)) r=mid;
		else l=mid+1;
	}
	pr(l);
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