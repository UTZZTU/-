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
int n,a[100010],m,vis[100010];
void solve()
{
	deque<int> q,p;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(i!=1)
		q.pb(i);
		vis[i]=1;
	}
	p.pb(a[1]);
	while(!p.empty())
	{
		int x=p.front();
		p.pop_front();
		int cnt=q.sz();
		while(cnt--)
		{
			int y=q.front();
			q.pop_front();
			if(gcd(x,a[y])>=2)
			{
				p.pb(a[y]);
			}
			else
			{
				q.pb(y);
			}
		}
	}
	m=q.sz();
	if(m==0)
	{
		printf("-1 -1\n");
	}
	else
	{
		while(!q.empty())
		{
			int x=q.front();
			vis[x]=2;
			q.pop_front();
		}
		cout<<n-m<<" "<<m<<endl;
		for(int i=1;i<=n;i++)
		{
			if(vis[i]==1)
			{
				printf("%d ",a[i]);
			}
		}
		putchar('\n');
		for(int i=1;i<=n;i++)
		{
			if(vis[i]==2)
			{
				printf("%d ",b[i]);
			}
		}
		putchar('\n');
	}
}
int main ()
{
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
//	IOS;
	int _=1;
	scanf("%d",&_);
	while(_--)
	{
		solve();
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}