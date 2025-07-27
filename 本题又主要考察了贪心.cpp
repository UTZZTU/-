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
	return x.num>y.num;
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

int n,m;
int a[15],minn=0x3f3f3f3f,pm[15];
pair<int,int> p[20];
void dfs(int level, VI vec)
{
	if(level>m)
	{
		for(int i=1;i<=n;i++)
		{
			S[i].pos=i;
			S[i].num=a[i];
		}
		for(int i=1;i<=m;i++)
		{
			if(vec[i]==1)
			{
				S[p[i].fi].num+=3;
			}
			else if(vec[i]==2)
			{
				S[p[i].se].num+=3;
			}
			else 
			{
				S[p[i].fi].num+=1;
				S[p[i].se].num+=1;
			}
		}
		sort(S+1,S+1+n,cmp);
		int cnt=1;
		for(int i=1;i<=n;i++)
		{
			int j=i+1;
			while(j<=n&&S[j].num==S[i].num) j++;
			j--;
			for(int k=i;k<=j;k++)
			{
				pm[S[k].pos]=cnt;
			}
			cnt+=(j-i+1);
			i=j;
		}
		minn=min(minn,pm[1]);
		return;
	}
	vec.pb(1);
	dfs(level+1,vec);
	vec.pop_back();
	vec.pb(2);
	dfs(level+1,vec);
	vec.pop_back();
	vec.pb(3);
	dfs(level+1,vec);
}
void solve()
{
	minn=0x3f3f3f3f;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++)
	{
		cin>>p[i].fi>>p[i].se;
	}
	VI vec;
	vec.pb(-1);
	dfs(1,vec);
	pr(minn);
}
int main ()
{
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	IOS;
	int _=1;
	cin>>_;
	while(_--)
	{
		solve();
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}