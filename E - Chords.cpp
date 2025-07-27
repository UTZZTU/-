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
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
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

int n,x,y,f[200010];
pair<int,int> p[200010];
deque<int> q;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i].fi>>p[i].se;
		if(p[i].fi>p[i].se) swap(p[i].fi,p[i].se);
	}
	sort(p+1,p+1+n);
	int l=-1,r=-1;
	int flag=0,pre=-1;
	for(int i=1;i<=n;i++)
	{
		if(i==1)
		{
			pre=1;
			l=p[i].fi,r=p[i].se;
		}
		else
		{
			if(p[i].fi>r)
			{
				if(q.sz())
				{
					l=p[q.back()].first,r=p[q.back()].second;
					pre=q.back();
					q.pop_back();
					i--;
				}
				else
				{
					pre=i;
					l=p[i].fi,r=p[i].se;
				}
			}
			else
			{
				if(p[i].se>r)
				{
					flag=1;
					break;
				}
				else
				{
					q.push_back(pre);
					pre=i;
					l=p[i].first,r=p[i].second;
				}
			}
		}
	}
	if(flag) yes;
	else no;
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