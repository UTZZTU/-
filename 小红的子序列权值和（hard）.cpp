#include <bits/stdc++.h>
using namespace std;
const double Eps = 1e-8;
const double PI = atan(-1.0);
const int N = 1e6+5;
const long long MOD = 1000000007;

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

ll qmi(ll a,ll b,ll mod)
{
	ll res=1;
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

ll n,a[100010],n1,n2,n3;
ll s1,s2,s3,pre[100010];
void init()
{
	s1=qmi(2ll,n1,MOD);
	for(ll i=0;i<=n2;i++)
	{
		s2=(s2+(i+1)*pre[n2]%MOD*qmi(pre[n2-i],MOD-2,MOD)%MOD*qmi(pre[i],MOD-2,MOD)%MOD)%MOD;
	}
	for(ll i=0;i<=n3;i++)
	{
		s3=(s3+(i+1)*pre[n3]%MOD*qmi(pre[n3-i],MOD-2,MOD)%MOD*qmi(pre[i],MOD-2,MOD)%MOD)%MOD;
	}
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==1) n1++;
		else if(a[i]==2) n2++;
		else n3++;
	}
	pre[1]=1;
    pre[0]=1;
	for(ll i=2;i<=100000;i++)
	{
		pre[i]=(pre[i-1]*i)%MOD;
	}
	init();
	pr((((s1*s2)%MOD*s3)%MOD-1+MOD)%MOD);
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