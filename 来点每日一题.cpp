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
ll n,a[1010],dp[1010][6][2],maxxt,f[1010],pos,yy[1010][1010];
ll get_num(int l,int r)
{
	if(r<l||r-l+1<6) return 0ll;
	for(int i=l;i<=r;i++)
	{
		dp[i][1][0]=dp[i][2][0]=dp[i][3][0]=dp[i][4][0]=dp[i][5][0]=-1e18;
		dp[i][1][1]=dp[i][2][1]=dp[i][3][1]=dp[i][4][1]=dp[i][5][1]=1e18;
	}
	ll maxx=0;
	for(int i=l;i<=r;i++)
	{
		for(int j=i+1;j<=r;j++)
		{
			dp[j][1][0]=max(dp[j][1][0],dp[i][0][0]-a[j]);
			dp[j][1][1]=min(dp[j][1][1],dp[i][0][0]-a[j]);
		}
	}
	for(int i=l+1;i<=r;i++)
	{
		for(int j=i+1;j<=r;j++)
		{
			dp[j][2][0]=max(dp[j][2][0],dp[i][1][0]*a[j]);
			dp[j][2][1]=min(dp[j][2][1],dp[i][1][1]*a[j]);
		}
	}
	for(int i=l+2;i<=r;i++)
	{
		for(int j=i+1;j<=r;j++)
		{
			dp[j][3][0]=max(dp[j][3][0],dp[i][2][0]-a[j]);
			dp[j][3][1]=min(dp[j][3][1],dp[i][2][1]-a[j]);
		}
	}
	for(int i=l+3;i<=r;i++)
	{
		for(int j=i+1;j<=r;j++)
		{
			dp[j][4][0]=max(dp[j][4][0],dp[i][3][0]*a[j]);
			dp[j][4][0]=max(dp[j][4][0],dp[i][3][1]*a[j]);
		}
	}
	for(int i=l+4;i<=r;i++)
	{
		for(int j=i+1;j<=r;j++)
		{
			dp[j][5][0]=max(dp[j][5][0],dp[i][4][0]-a[j]);
		}
	}
	for(int i=l;i<=r;i++)
	{
		maxx=max(maxx,dp[i][5][0]);
	}
	yy[l][r]=maxx;
	return maxx;
}
/*
7
-10 -2 9 99 8 -2 -7

3785
*/
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		dp[i][0][0]=dp[i][0][1]=a[i];
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			f[j]=max(f[j],get_num(i+1,j)+f[i]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(i==n)
		{
			maxxt=max(maxxt,f[i]);
		}
		else
		{
			maxxt=max(maxxt,f[i]+yy[i+1][n]);
		}
//		cout<<f[i]<<" ";
	}
//	cout<<endl;
	pr(maxxt);
//	pr(pos);
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