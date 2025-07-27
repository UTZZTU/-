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

int q,op,x,y;
int l[500010],r[500010],cnt=1,idx=1,f[500010],n;
unordered_map<int,int> mp1,mp2;
void solve()
{
	for(int i=1;i<=500000;i++) l[i]=r[i]=i;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&f[i]);
		mp1[f[i]]=cnt;
		mp2[cnt]=f[i];
		cnt++;
		l[i]=max(1,i-1);
		r[i]=min(i+1,n);
	}
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d%d",&y,&x);
			int px,py;
			px=cnt;
			mp1[x]=cnt;
			mp2[cnt]=x;
			cnt++;
			py=mp1[y];
			if(r[py]==py)
			{
				l[px]=py;
				r[py]=px;
				r[px]=px;
			}
			else
			{
				int nx=r[py];
				r[py]=px;
				l[px]=py;
				r[px]=nx;
				l[nx]=px;
			}
		}
		else
		{
			scanf("%d",&x);
			int px=mp1[x];
			if(idx==px)
			{
				if(r[px]==px)
				{
					idx=-1;
				}
				else
				{
					int nx=r[px];
					r[px]=px;
					l[nx]=nx;
					idx=nx;
				}
			}
			else
			{
				if(r[px]!=px)
				{
					int nx=r[px];
					int prx=l[px];
					r[prx]=nx;
					l[nx]=prx;
				}
				else
				{
					int prx=l[px];
					r[prx]=prx;
				}
			}
		}
	}
	while(idx!=-1&&r[idx]!=idx)
	{
		printf("%d ",mp2[idx]);
		idx=r[idx];
	}
	if(idx!=-1)
	printf("%d ",mp2[idx]);
//	cout<<vec.sz()<<endl;
//	for(auto x:vec) cout<<x<<" ";
//	cout<<endl;
}
int main ()
{
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
//	IOS;
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