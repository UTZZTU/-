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
	string name;
}S[N];

bool cmp(node x,node y)
{
	if(x.num!=y.num)
	return x.num>y.num;
	else return x.name<y.name;
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

string root,a="posted",b="commented",c="likes",name1,name2,u,v;
map<string,int> mp;
int cnt,n;
void solve()
{
	cin>>root;
	cin>>n;
	while(n--)
	{
		cin>>name1>>u;
		if(u==a)
		{
			cin>>u>>v;
			name2.cl();
			for(int i=0;i<v.sz()-2;i++)
			{
				name2+=v[i];
			}
			cin>>u;
			if(mp[name1]==0)
			{
				mp[name1]=++cnt;
				S[cnt].name=name1;
				S[cnt].num=15;
			}
			else
			{
				S[mp[name1]].num+=15;
			}
			if(mp[name2]==0)
			{
				mp[name2]=++cnt;
				S[cnt].name=name2;
				S[cnt].num=15;
			}
			else
			{
				S[mp[name2]].num+=15;
			}
			if(name1!=root&&name2!=root)
			{
				S[mp[name1]].num-=15;
				S[mp[name2]].num-=15;
			}
		}
		else if(u==b)
		{
			cin>>u>>v;
			name2.cl();
			for(int i=0;i<v.sz()-2;i++)
			{
				name2+=v[i];
			}
			cin>>u;
			if(mp[name1]==0)
			{
				mp[name1]=++cnt;
				S[cnt].name=name1;
				S[cnt].num=10;
			}
			else
			{
				S[mp[name1]].num+=10;
			}
			if(mp[name2]==0)
			{
				mp[name2]=++cnt;
				S[cnt].name=name2;
				S[cnt].num=10;
			}
			else
			{
				S[mp[name2]].num+=10;
			}
			if(name1!=root&&name2!=root)
			{
				S[mp[name1]].num-=10;
				S[mp[name2]].num-=10;
			}
		}
		else
		{
			cin>>v;
			name2.cl();
			for(int i=0;i<v.sz()-2;i++)
			{
				name2+=v[i];
			}
			cin>>u;
			if(mp[name1]==0)
			{
				mp[name1]=++cnt;
				S[cnt].name=name1;
				S[cnt].num=5;
			}
			else
			{
				S[mp[name1]].num+=5;
			}
			if(mp[name2]==0)
			{
				mp[name2]=++cnt;
				S[cnt].name=name2;
				S[cnt].num=5;
			}
			else
			{
				S[mp[name2]].num+=5;
			}
			if(name1!=root&&name2!=root)
			{
				S[mp[name1]].num-=5;
				S[mp[name2]].num-=5;
			}
		}
	}
	sort(S+1,S+1+cnt,cmp);
	for(int i=1;i<=cnt;i++)
	{
		if(S[i].name!=root) pr(S[i].name);
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