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

//int m,p;
struct Node
{
    int l,r;
    int v;
}tr[N * 4];
void push_up(int u)
{
    tr[u].v=min(tr[u << 1].v,tr[u << 1 | 1].v);
}
void build(int u,int l,int r)
{
    tr[u]={l,r};
    if(l==r)
    {
    	tr[u].v=0x3f3f3f3f;
    	return;
	}
    int mid = l + r >> 1;
    build(u<<1,l,mid),build(u << 1 | 1, mid+1, r);
    push_up(u);
}
int query(int u,int l,int r)
{
    if(tr[u].l>=l&&tr[u].r<=r) return tr[u].v;

        int mid = tr[u].l + tr[u].r >> 1;
        int v=0x3f3f3f3f;
        if (l<=mid) v=query(u<<1, l,r);
        if(r>mid) v=min(v, query(u<<1|1,l,r));
        return v;
}
void modify(int u,int x,int v)
{
    if(tr[u].l==x&&tr[u].r==x) tr[u].v=v;
    else
    {
        int mid = tr[u].l+tr[u].r>>1;
        if(x<=mid) modify(u<<1, x,v);
        else if(x>mid) modify(u<<1|1,x,v);
        push_up(u);
    }
}
int n,dp[200010],f[200010],pre[200010];
void solve()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&f[i]);
		pre[i]=-1;
	}
	for(int i=n;i>=1;i--)
	{
		int x=f[i];
		if(pre[x]==-1)
		{
			dp[i]=1;
		}
		else
		{
			int pos=pre[x];
			int minn=query(1,i+1,pos);
			dp[i]=minn+1;
		}
		modify(1,i,dp[i]);
		pre[x]=i;
	}
	printf("%d\n",dp[1]);
}
int main ()
{
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	build(1,1,200000);
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