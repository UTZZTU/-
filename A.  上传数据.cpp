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
#define int long long
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
int n,m,p[1010],w[1010],res1,h[1010],pp=1,qq=1;
struct node
{
	double s;
	int pos,dl;
	inline bool operator<(const node &x) const
	{
		if(s!=x.s) return s>x.s;
		else return dl<x.dl;
	}
};
priority_queue<node> q;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i]>>w[i];
		res1+=w[i];
		q.push({w[i]*1.0/p[i],i,p[i]});
		h[i]=w[i];
	}
	if(res1>m)
	{
		cout<<"Zip file size too big after extraction.Poor M!";
	}
	else
	{
		int sy=m-res1;
		while(sy--&&!q.empty())
		{
			auto u=q.top();
			q.pop();
			if(h[u.pos]>=p[u.pos]) continue;
			h[u.pos]++;
			if(h[u.pos]<p[u.pos])
			{
				q.push({h[u.pos]*1.0/p[u.pos],u.pos,p[u.pos]});
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(pp*p[i]>qq*h[i])
			{
				pp=h[i];
				qq=p[i];
			}
		}
		int gcds=__gcd(pp,qq);
		pp/=gcds,qq/=gcds;
		cout<<pp<<"/"<<qq<<endl;
		for(int i=1;i<=n;i++)
		{
			if(i!=1) cout<<" ";
			cout<<h[i];
		}
	}
}
signed main ()
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