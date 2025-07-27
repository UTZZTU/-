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
VI vec[100010];
int a[100010],b[100010],n,vis[100010],k,flag=1;
char u[100010];
string s;
int dfs1(int x)
{
//	vis[x]=1;
	int num=0;
	if(s[x]=='R')
	{
		num++;
		for(int i=0;i<vec[x].sz();i++)
		{
			int j=vec[x][i];
			num+=dfs1(j);
		}
		int pp=0;
		for(int i=0;i<=num;i++)
		{
			if((i+(num-i)*2)%3==0)
			{
				a[x]=i,b[x]=num-i;
				pp=1;
				break;
			}
		}
		if(!pp)
		{
			flag=0;
		}
		return 0;
	}
	else
	{
		num++;
		for(int i=0;i<vec[x].sz();i++)
		{
			int j=vec[x][i];
			num+=dfs1(j);
		}
		a[x]=num;
		return num;
	}
}
void dfs2(int x,int pre)
{
	if(a[pre]>0)
	{
		a[pre]--;
		u[x]='1';
	}
	else if(b[pre]>0)
	{
		b[pre]--;
		u[x]='2';
	}
	for(int i=0;i<vec[x].sz();i++)
	{
		int j=vec[x][i];
		if(s[j]!='R')
		{
			dfs2(j,pre);
		}
	}
}
void solve()
{
	cin>>n;
	cin>>s;
	s=" "+s;
	for(int i=2;i<=n;i++)
	{
		cin>>k;
		vec[k].pb(i);
	}
	int x=dfs1(1);
	if(!flag)
	{
		pr(-1);
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			u[i]='0';
		}
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='R')
			{
				dfs2(i,i);
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(u[i]=='0') u[i]='1';
			cout<<u[i];
		}
		cout<<endl;
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