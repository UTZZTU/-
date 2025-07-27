#include <bits/stdc++.h>
using namespace std;
const double Eps = 1e-8;
const double PI = atan(-1.0);
const int N = 2e5+5;
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

//cout<<fixed<<setprecision(x)

int n,q,pos,op,l,r;
string u,v[6]={"red","rde","erd","edr","dre","der"};
char c;
int tr[10][N];
int lowbit(int x)
{
	return x & -x;
}
void add(int x,int c,int p)
{
	for(int i=x;i<=n;i+=lowbit(i)) tr[p][i]+=c;
}
int sum(int x,int p)
{
	int res=0;
	for(int i=x;i;i-=lowbit(i)) res+=tr[p][i];
	return res;
}
void solve()
{
	cin>>n>>q;
	cin>>u;
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(u[j]!=v[i][j%3])
			{
				add(j+1,1,i);
			}
		}
	}
	while(q--)
	{
		cin>>op;
		if(op==1)
		{
			cin>>pos>>c;
			for(int i=0;i<6;i++)
			{
				if(u[pos-1]==v[i][(pos-1)%3])
				{
					add(pos,1,i);
				}
				if(c==v[i][(pos-1)%3])
				{
					add(pos,-1,i);
				}
			}
			u[pos-1]=c;
		}
		else
		{
			cin>>l>>r;
			int minn=0x3f3f3f3f;
			for(int i=0;i<6;i++)
			{
				minn=min(minn,sum(r,i)-sum(l-1,i));
			}
			pr(minn);
		}
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