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

__int128 w,m,k,lng;
ll a,b,c;
__int128 get_num(__int128 x)
{
	__int128 res=0;
	while(x)
	{
		x/=10;
		res++;
	}
	return res;
}
/*
10000000000000000 1 1
*/
__int128 ggt(__int128 x)
{
	__int128 res=1;
	while(x--)
	{
		res*=10;
	}
	return res;
}
void solve()
{
	cin>>a>>b>>c;
	w=a;
	m=b;
	k=c;
	while(1)
	{
		__int128 ws=get_num(m);
		__int128 num=ggt(ws)-m;
		if(w-ws*num*k>=0)
		{
			w-=ws*num*k;
			lng+=num;
			m=ggt(ws);
		}
		else
		{
			cout<<(ll)(w/(ws*k)+lng)<<endl;
			return;
		}
//		pr(w);
//		pr(m);
//		pr(ws);
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