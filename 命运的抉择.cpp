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
int n,a[100010],sum,fa[100010];
int find(int x)
{
	while(x!=fa[x]) x=fa[x]=fa[fa[x]];
	return x;
}
void solve()
{
	unordered_map<int,int> mp;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		fa[i]=i;
	}
	for(int i=1;i<=n;i++)
	{
		int num=a[i];
		for(int j=2;j*j<=num;j++)
		{
			if(num%j==0)
			{
				if(mp[j]!=0)
				{
					int x=mp[j];
					int eu=find(x),ev=find(i);
					if(eu!=ev)
					{
						fa[ev]=eu;
					}
				}
				while(num%j==0)
				{
					num/=j;
				}
				mp[j]=i;
			}
		}
		if(num>1)
		{
			if(mp[num]!=0)
			{
				int x=mp[num];
				int eu=find(x),ev=find(i);
				if(eu!=ev)
				{
					fa[ev]=eu;
				}
			}
			mp[num]=i;
		}
	}
	VI vec1,vec2;
	int eu=find(1);
	for(int i=1;i<=n;i++)
	{
		int ev=find(i);
		if(eu==ev)
		{
			vec1.pb(a[i]);
		}
		else vec2.pb(a[i]);
	}
	if(vec1.sz()==0||vec2.sz()==0)
	{
		cout<<-1<<" "<<-1<<endl;
		return;
	}
	cout<<vec1.sz()<<" "<<vec2.sz()<<endl;
	for(auto x:vec1)
	{
		cout<<x<<" ";
	}
	cout<<endl;
	for(auto x:vec2)
	{
		cout<<x<<" ";
	}
	cout<<endl;
}
int main ()
{
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
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