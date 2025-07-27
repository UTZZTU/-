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

int n,m,h[55],l[55],a,b,c,f[55][55],res;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>f[i][j];
			h[i]+=f[i][j];
			l[j]+=f[i][j];
		}
	}
	for(int i=1;i<=n;i++) h[i]+=h[i-1];
	for(int j=1;j<=m;j++) l[j]+=l[j-1];
	cin>>a>>b>>c;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(h[i]==a&&h[j]-h[i]==b&&h[n]-h[j]==c) res++;
			else if(h[i]==a&&h[j]-h[i]==c&&h[n]-h[j]==b) res++;
			else if(h[i]==b&&h[j]-h[i]==a&&h[n]-h[j]==c) res++;
			else if(h[i]==b&&h[j]-h[i]==c&&h[n]-h[j]==a) res++;
			else if(h[i]==c&&h[j]-h[i]==a&&h[n]-h[j]==b) res++;
			else if(h[i]==c&&h[j]-h[i]==b&&h[n]-h[j]==a) res++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=i+1;j<m;j++)
		{
			if(l[i]==a&&l[j]-l[i]==b&&l[m]-l[j]==c) res++;
			else if(l[i]==a&&l[j]-l[i]==c&&l[m]-l[j]==b) res++;
			else if(l[i]==b&&l[j]-l[i]==a&&l[m]-l[j]==c) res++;
			else if(l[i]==b&&l[j]-l[i]==c&&l[m]-l[j]==a) res++;
			else if(l[i]==c&&l[j]-l[i]==a&&l[m]-l[j]==b) res++;
			else if(l[i]==c&&l[j]-l[i]==b&&l[m]-l[j]==a) res++;
		}
	}
	pr(res);
}
int main ()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	IOS;
	int _=1;
//	cin>>_;
	while(_--)
	{
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}