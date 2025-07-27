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
#define debug(x) cout<<"x"<<endl
#define IOS ios::sync_with_stdio(false);cin.tie(0)
#define Mem(x) memset(x,0,sizeof x)
#define no cout<<"NO"<<endl
#define yes cout<<"YES"<<endl
#define pr(x) cout<<x<<endl
#define int long long

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

int n,ans[N],tr[N],a[N],m,b[N];
int lowbit(int x)
{
    return x & -x;
}
void add(int x,int c)
{
    for(int i=x;i<=n;i+=lowbit(i)) tr[i]+=c;
}
int sum(int x)
{
    int res=0;
    for(int i=x;i;i-=lowbit(i)) res+=tr[i];
    return res;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		add(i,a[i]);
		add(i+1,-a[i]);
	}
	for(int i=1;i<=m;i++)
	{
		cin>>b[i];
		b[i]++;
		int cnt=sum(b[i]);
		add(b[i],-cnt);
		add(b[i]+1,cnt);
		if(cnt+b[i]<=n)
		{
			if(cnt==0)
			{
				;
			}
			else
			{
				add(b[i]+1,1);
				add(b[i]+cnt+1,-1);
			}
		}
		else
		{
			if(b[i]==n)
			{
				;
			}
			else
			{
				add(b[i]+1,1);
				add(n+1,-1);
				cnt-=(n-b[i]);
			}
			int cs=cnt/n;
			add(1,cs);
			add(n+1,-cs);
			cnt-=cs*n;
			if(cnt)
			{
				add(1,1);
				add(cnt+1,-1);
			}
		}
	}
	for(int i=1;i<=n;i++) cout<<sum(i)<<" ";
}
signed main ()
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