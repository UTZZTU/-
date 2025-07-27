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

int n,h,w,vis[15][15],flag,use[10];
PI p[10];
void dfs()
{
	if(flag) return;
	int posx=-1,posy=-1;
	for(int i=1;i<=h;i++)
	{
		for(int j=1;j<=w;j++)
		{
			if(!vis[i][j])
			{
				posx=i;
				posy=j;
				break;
			}
		}
		if(posx!=-1) break;
	}
	if(posx==-1&&posy==-1)
	{
		flag=1;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(use[i]==0)
		{
			int pp=1;
			for(int k1=posx;k1<=posx+p[i].fi-1;k1++)
			{
				for(int k2=posy;k2<=posy+p[i].se-1;k2++)
				{
					if(k1<=0||k1>=h+1||k2<=0||k2>=w+1||vis[k1][k2])
					{
						pp=0;
						break;
					}
				}
				if(!pp) break;
			}
			if(pp)
			{
				use[i]=1;
				for(int k1=posx;k1<=posx+p[i].fi-1;k1++)
				{
					for(int k2=posy;k2<=posy+p[i].se-1;k2++)
					{
						vis[k1][k2]=i;
					}
				}
				dfs();
				for(int k1=posx;k1<=posx+p[i].fi-1;k1++)
				{
					for(int k2=posy;k2<=posy+p[i].se-1;k2++)
					{
						vis[k1][k2]=0;
					}
				}
				use[i]=0;
			}
			pp=1;
			for(int k1=posx;k1<=posx+p[i].se-1;k1++)
			{
				for(int k2=posy;k2<=posy+p[i].fi-1;k2++)
				{
					if(k1<=0||k1>=h+1||k2<=0||k2>=w+1||vis[k1][k2])
					{
						pp=0;
						break;
					}
				}
				if(!pp) break;
			}
			if(pp)
			{
				use[i]=1;
				for(int k1=posx;k1<=posx+p[i].se-1;k1++)
				{
					for(int k2=posy;k2<=posy+p[i].fi-1;k2++)
					{
						vis[k1][k2]=i;
					}
				}
				dfs();
				for(int k1=posx;k1<=posx+p[i].se-1;k1++)
				{
					for(int k2=posy;k2<=posy+p[i].fi-1;k2++)
					{
						vis[k1][k2]=0;
					}
				}
				use[i]=0;
			}
		}
	}
}
void solve()
{
	cin>>n>>h>>w;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i].fi>>p[i].se;
	}
	dfs();
	if(flag) yes;
	else no;
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