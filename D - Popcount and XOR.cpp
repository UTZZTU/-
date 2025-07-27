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
ll a,b,c,f[60],num;
ll get_num(ll x)
{
	ll res=0;
	while(x)
	{
		if(x&1ll) res++;
		x/=2ll;
	}
	return res;
}
void solve()
{
	memset(f,0,sizeof f);
	cin>>a>>b>>c;
	ll x=0ll,y=0ll;
	ll p=get_num(c);
	if(p>a+b||(a+b-p)&1ll||p<abs(a-b))
	{
		pr(-1);
	}
	else
	{
		ll q=(a+b-p)/2ll;
		num=a-q;
		for(ll i=0;i<60;i++)
		{
			if((c>>i)&1ll)
			{
//				cout<<i<<endl;
				if(num>0)
				{
					num--;
					x|=(1ll<<i);
				}
				else
				{
					y|=(1ll<<i);
				}
//				cout<<x<<" "<<y<<endl;
			}
			else
			{
				f[i]=1;
			}
		}
		num=q;
		if(num>0)
		{
			for(ll i=0;i<60;i++)
			{
				if(f[i]==1)
				{
					num--;
					x|=(1ll<<i);
					y|=(1ll<<i);
				}
				if(num<=0) break;
			}
		}
		if(num>0||(x^y)!=c||x>(ll)pow(2ll,60ll)||y>(ll)pow(2ll,60ll)) pr(-1);
		else cout<<x<<" "<<y<<endl;
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