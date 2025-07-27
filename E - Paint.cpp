#include <bits/stdc++.h>
using namespace std;
const double Eps = 1e-8;
const double PI = atan(-1.0);
const int N = 1e6+5;
const int MOD = 1e9+7;
#define int long long
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

//using ll = long long;
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
struct node
{
	int fi,se;
};
bool cmp(node x,node y)
{
	return x.se<y.se;
}
int h,w,m,fa1[200010],fa2[200010],op,a,x,cf[200010];
node p1[200010],p2[200010];
map<int,int> mp;
//int find1(int x)
//{
//	while(fa1[x]!=x)
//	{
//		x=fa1[x]=fa1[fa1[x]];
//	}
//	return fa1[x];
//}
//int find2(int x)
//{
//	while(fa2[x]!=x)
//	{
//		x=fa2[x]=fa2[fa2[x]];
//	}
//	return fa2[x];
//}
int find(int x)
{
	if(x<p2[1].se) return 0;
	if(x>=p2[w].se) return w;
	int l=1,r=w;
	while(l<r)
	{
		int mid=(l+r+1)>>1;
		if(p2[mid].se<=x) l=mid;
		else r=mid-1;
	}
	return l;
}
void solve()
{
	cin>>h>>w>>m;
	for(int i=1;i<=h;i++)
	{
		p1[i]={0,0};
	}
	for(int i=1;i<=w;i++)
	{
		p2[i]={0,0};
	}
	for(int i=1;i<=m;i++)
	{
		cin>>op>>a>>x;
		if(op==1)
		{
			p1[a]={x,i};
		}
		else
		{
			p2[a]={x,i};
		}
	}
	sort(p2+1,p2+1+w,cmp);
//	for(int i=1;i<=h;i++)
//	{
//		cout<<p1[i].fi<<" "<<p1[i].se<<endl;
//	}
//	for(int i=1;i<=w;i++)
//	{
//		cout<<p2[i].fi<<" "<<p2[i].se<<endl;
//	}
	for(int i=1;i<=h;i++)
	{
//		cout<<p1[i].se<<endl;
		int pos=find(p1[i].se);
		if(pos>0) mp[p1[i].fi]+=pos;
		if(pos+1<=w) cf[pos+1]+=1;
//		cout<<pos<<endl;
	}
	int num=0;
	for(int i=1;i<=w;i++)
	{
		num+=cf[i];
		if(num>0) mp[p2[i].fi]+=num;
	}
	cout<<mp.sz()<<endl;
	for(auto [u,v]:mp)
	{
		cout<<u<<" "<<v<<endl;
	}
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