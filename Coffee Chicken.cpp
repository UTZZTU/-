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
string u=" COFFEE",v=" CHICKEN",w;
ll n,k,pre[5010],pos;
ll p=100000000000000ll;
void init()
{
	pre[1]=u.sz()-1;
	pre[2]=v.sz()-1;
	pos=3;
	for(pos;pos<=100;pos++)
	{
		pre[pos]=pre[pos-1]+pre[pos-2];
		if(pre[pos]>p) break;
	}
//	pr(pos);
}
void dfs(ll x,ll pp,ll l)
{
	if(x==1)
	{
		for(int i=pp;i<min(pp+l,pre[1]+1);i++) w+=u[i];
		return;
	}
	else if(x==2)
	{
		for(int i=pp;i<min(pp+l,pre[2]+1);i++) w+=v[i];
		return;
	}
	else
	{
		if(pp+l-1<=pre[x-2])
		{
			dfs(x-2,pp,l);
		}
		else if(pre[x-2]<pp)
		{
			dfs(x-1,pp-pre[x-2],l);
		}
		else
		{
			ll len=pre[x-2]-pp+1;
			dfs(x-2,pp,len);
			dfs(x-1,1,l-len);
		}
	}
}
void solve()
{
	w.cl();
	cin>>n>>k;
	if(n>=pos)
	{
		while(n>=pos)
		{
			n-=2;
		}
		while(pre[n-2]>=k+9) n-=2;
		dfs(n,k,10ll);
		cout<<w<<endl;
	}
	else
	{
		if(pre[n]>=k+9)
		{
			while(n>=pos)
			{
				n-=2;
			}
			while(pre[n-2]>=k+9) n-=2;
			dfs(n,k,10ll);
			cout<<w<<endl;
		}
		else
		{
			while(n>=pos)
			{
				n-=2;
			}
			while(pre[n-2]>=k+9) n-=2;
			dfs(n,k,10ll);
			cout<<w<<endl;
		}
	}
}
int main ()
{
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
    init();
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