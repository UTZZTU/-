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
ll n,a[100010],b[100010],sum;
void solve()
{
	sum=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	if(n%2==0||n==1)
	{
		if(n==1)
		{
			pr(0);
		}
		else
		{
			ll maxx=0;
			for(int i=1;i<n;i++)
			{
				maxx=max(maxx,a[i]-a[i+1]);
			}
			pr(maxx);
		}
		return;
	}
	if(a[n]<a[n-1])
	{
		pr(-1);
		return;
	}
	ll cnt=0;
	for(int i=n-1;i>=2;i-=2)
	{
		a[i]+=cnt*i;
		if(a[i]>a[i+1])
		{
			pr(-1);
			return;
		}
		ll jc=(a[i+1]-a[i])/i;
		a[i]+=jc*i;
		a[i-1]+=cnt*(i-1);
		a[i-1]+=jc*(i-1);
		if(a[i-1]>a[i])
		{
			pr(-1);
			return;
		}
		cnt+=jc;
	}
	for(int i=2;i<=n;i++)
	{
		if(a[i]>=a[i-1]) ;
		else
		{
			pr(-1);
			return;
		}
	}
	cnt=0;
//	for(int i=2;i<=n;i+=2)
//	{
//		if(i==2)
//		{
//			if(b[i-1]<=b[i]) ;
//			else
//			{
//				ll t=b[i-1]-b[i];
//				cnt=t;
//				b[i-1]+=cnt*(i-1);
//				b[i]+=cnt*i;
//			}
//		}
//		else
//		{
//			ll p=0;
//			if(b[i-2]<=b[i-1])
//			{
//				;
//			}
//			else
//			{
//				p=b[i-2]-b[i-1];
//				b[i-1]+=p*(i-1);
//				b[i]+=p*(i);
//				if(p>cnt) cnt=p;
//			}
//			ll t=0;
//			if(b[i-1]>b[i])
//			t=b[i-1]-b[i];
//			if(t+p>cnt) cnt=t+p;
//			b[i-1]+=t*(i-1);
//			b[i]+=t*i;
//		}
//		sum=max(sum,cnt);
//	}
	for(int i=1;i<n-1;i++)
	{
		sum=max(sum,b[i]-b[i+1]);
	}
	pr(sum);
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