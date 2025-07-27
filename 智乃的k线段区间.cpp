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
#define int long long
using ll = long long;
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
priority_queue<int,vector<int>,greater<int>> pq;
map<int,vector<int>> mp;
int n,m,k,res,x,y,flag,pre=-1;
void solve()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y;
		mp[y].pb(x);
	}
	for(auto it=mp.bg();it!=mp.ed();it++)
	{
		x=it->first;
		vector<int> vec=it->second;
		if(flag)
		{
			if(pq.sz()>=k)
			res+=(x-pre-1)*pq.top();
		}
		else
		{
			flag=1;
		}
		if(pq.sz()<k)
		{
			for(auto c:vec)
			{
				pq.push(c);
			}
		}
		else
		{
			for(auto c:vec)
			{
				if(c>=pq.top())
				pq.push(c);
//				pq.pop();
			}
		}
		if(pq.sz()<k) continue;
		while(pq.sz()>k) pq.pop();
		res+=pq.top();
		pre=x;
//		it++;
//		cout<<x<<" "<<res<<" "<<pq.top()<<endl<<" "<<pq.sz()<<endl;
//		if(it==mp.ed())
//		{
//			res+=(m-x)*pq.top();
//		}
	}
	if(pq.sz()>=k)
	res+=(m-x)*pq.top();
	pr(res);
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