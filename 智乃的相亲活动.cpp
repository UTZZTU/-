#include <bits/stdc++.h>
using namespace std;
const double Eps = 1e-8;
const double PI = atan(-1.0);
const int N = 1e5+5;
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
#define debug(x) cout<<"x"<<endl
#define IOS ios::sync_with_stdio(false);cin.tie(0)
#define Mem(x) memset(x,0,sizeof x)
#define no cout<<"NO"<<endl
#define yes cout<<"YES"<<endl
#define pr(x) cout<<x<<endl

using ll = long long;
using u32 = unsigned int;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;
using f128 = __float128;

struct node
{
	int num,pos;
}S[N];

bool cmp(node x,node y)
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

int n,m,k,u,v;
double s1[100010],s2[100010],sum1,sum2;
VI vec1[100010];
VI vec2[100010];
void solve()
{
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++)
	{
		cin>>u>>v;
		vec1[u].emplace_back(v);
		vec2[v].emplace_back(u);
	}
	for(int i=1;i<=n;i++)
	{
		double pp=1.0;
		for(auto x:vec1[i])
		{
			int num=vec2[x].sz();
			double pt=(num-1)*1.0/num;
			pp*=pt;
		}
		pp=1.0-pp;
		s1[i]=pp;
	}
	for(int i=1;i<=m;i++)
	{
		double pp=1.0;
		for(auto x:vec2[i])
		{
			int num=vec1[x].sz();
			double pt=(num-1)*1.0/num;
			pp*=pt;
		}
		pp=1.0-pp;
		s2[i]=pp;
	}
	for(int i=1;i<=n;i++) sum1+=s1[i];
	for(int i=1;i<=m;i++) sum2+=s2[i];
	pr("float");
	cout<<setprecision(8)<<sum1<<" "<<sum2<<endl;
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