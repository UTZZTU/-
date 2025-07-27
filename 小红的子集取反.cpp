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

int n,a[210],b[210],dp[40010],res,sum,f[210][110010];
bool judge()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=sum/2;j>=b[i];j--)
		{
			dp[j]=max(dp[j],dp[j-b[i]]+b[i]);
		}
	}
	return dp[sum/2]==sum/2;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		res+=a[i];
		sum+=abs(a[i]);
		b[i]=abs(a[i]);
	}
	if(sum&1)
	{
		pr(-1);
		return;
	}
	if(res==0)
	{
		pr(0);
		return;
	}
	if(!judge())
	{
		pr(-1);
		return;
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=100000;j++)
		{
			f[i][j]=0x3f3f3f3f;
		}
	}
	f[0][60000]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=20000;j<=100000;j++)
		{
			if(j-a[i]>=20000&&j-a[i]<=100000)
			{
				f[i][j]=min(f[i][j],f[i-1][j-a[i]]);
			}
			if(j+a[i]>=20000&&j+a[i]<=100000)
			{
				f[i][j]=min(f[i][j],f[i-1][j+a[i]]+1);
			}
		}
	}
	if(f[n][60000]==0x3f3f3f3f) pr(-1);
	else
	pr(f[n][60000]);
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