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
ll a,b,minn,gcds;
void solve()
{
	cin>>a>>b;
	if(a==b)
	{
		cout<<0<<endl;
		return;
	}
	gcds=__gcd(a,b);
	minn=a*b/gcds;
	if(gcds==1)
	{
		for(ll i=2;;i++)
		{
			if(__gcd(i,a)==1&&__gcd(i,b)==1)
			{
				minn=min(minn,i*(a+b));
				break;
			}
		}
		minn=min(minn,2ll*a/__gcd(2ll,a)+2ll*b/__gcd(2ll,b));
		ll x=a,y=b;
		for(ll i=2;i*i<=x;i++)
		{
			if(x%i==0)
			{
				minn=min(minn,x+(i*y)/__gcd(i,y));
				minn=min(minn,x+(x/i*y)/__gcd(x/i,y));
			}
		}
		for(ll i=2;i*i<=y;i++)
		{
			if(y%i==0)
			{
				minn=min(minn,y+(i*x)/__gcd(i,x));
				minn=min(minn,y+(y/i*x)/__gcd(y/i,x));
			}
		}
		for(ll i=2ll*x;;i+=x)
		{
			ll sum=i+(i*y)/__gcd(i,y);
			if(sum>=minn) break;
			minn=min(minn,sum);
		}
		for(ll i=2ll*y;;i+=y)
		{
			ll sum=i+(i*x)/__gcd(i,x);
			if(sum>=minn) break;
			minn=min(minn,sum);
		}
	}
	else
	{
		minn=min(minn,a+b);
	}
	cout<<minn<<endl;
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