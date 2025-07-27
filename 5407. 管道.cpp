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

ll n,len;
pair<ll,ll> p[100010];
bool check(ll x)
{
	map<ll,ll> mp;
	for(int i=1;i<=n;i++)
	{
		if(x>=p[i].se)
		{
			ll l=max(1ll,p[i].fi-(x-p[i].se));
			ll r=min(len,p[i].fi+(x-p[i].se));
			mp[l]++;
			mp[r+1]--;
		}
	}
	ll sum=0;
	ll flag=0,final;
	for(auto [p,q]:mp)
	{
		sum+=q;
		if(flag==0)
		{
			if(p!=1) return false;
			flag=1;
		}
		if(p<=len&&sum==0) return false;
		final=p;
	}
	if(final!=len+1) return false;
	return true;
}
void solve()
{
	cin>>n>>len;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i].fi>>p[i].se;
	}
	ll l=1,r=2e9;
	while(l<r)
	{
		ll mid=l+r>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	pr(l);
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