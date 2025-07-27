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
#define no cout<<"No"<<'\n'
#define yes cout<<"Yes"<<'\n'
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
int n,m,sum;
int sst[15],eed[15],cf[100010];
bool judge(VI vec)
{
	int flag=1;
//	for(int i=1;i<=n;i++) cf[i]=0;
	for(int i=0;i<vec.sz();i++)
	{
		cf[sst[vec[i]]]++;
		cf[eed[vec[i]]+1]--;
	}
	int res=0;
	for(int i=1;i<=n;i++)
	{
		res+=cf[i];
		if(res<2)
		{
			flag=0;
			break;
		}
	}
	for(int i=0;i<vec.sz();i++)
	{
		cf[sst[vec[i]]]--;
		cf[eed[vec[i]]+1]++;
	}
	return flag==1;
}
void dfs(int x,VI vec)
{
	if(x>m)
	{
		if(judge(vec)) sum++;
		return;
	}
	vec.pb(x);
	dfs(x+1,vec);
	vec.pop_back();
	dfs(x+1,vec);
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>sst[i]>>eed[i];
	}
	VI vec;
	dfs(1,vec);
	pr(sum);
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