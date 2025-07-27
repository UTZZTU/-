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

using ll = long long;
using u32 = unsigned int;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;
using f128 = __float128;

struct node
{
	int num,pos;
}s[N];

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

int n,a[310],b[310];
map<int,Mul> mp;
vector<PI> vec;
void add(int x,int y)
{
	int a=x,b=y;
	while(b!=x)
	{
		vec.pb({b-1,b});
		b--;
	}
	a++;
	while(a!=y)
	{
		vec.pb({a,a+1});
		a++;
	}
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
		mp[b[i]].is(i);
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==b[i]) continue;
		auto it=mp[a[i]].upper_bound(i);
		int pos=*it;
		add(i,pos);
		mp[b[i]].erase(mp[b[i]].lower_bound(i));
		mp[a[i]].erase(it);
		mp[b[i]].is(pos);
		mp[a[i]].is(i);
		swap(b[i],b[pos]);
	}
	cout<<vec.sz()<<endl;
	for(auto [x,y]:vec) cout<<x<<" "<<y<<endl;
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
/*
5
470138369 747764103 729004864 491957578 874531368
874531368 729004864 491957578 747764103 470138369
0
0
1
*/