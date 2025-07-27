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
int n,x,y,f[200010],sum;
struct node
{
	int len;
	int flag;
	inline bool operator<(const node &x)const{
		if(flag!=x.flag)
		{
			return flag<x.flag;
		}
		else
		{
			if(flag==1)
			return len>x.len;
			else return len<x.len;
		}
	}
};
void solve()
{
	priority_queue<node> p;
	sum=0;
	cin>>n>>x>>y;
	for(int i=1;i<=x;i++) cin>>f[i];
	sort(f+1,f+1+x);
	sum=x-2;
	for(int i=2;i<=x;i++)
	{
		int xx=f[i]-f[i-1];
		if(xx==2) sum++;
		if(xx>2&&xx%2==0) p.push({xx,1});
		else p.push({xx,0});
	}
	int xx=f[1]+n-f[x];
	if(xx==2) sum++;
	if(xx>2&&xx%2==0) p.push({xx,1});
	else p.push({xx,0});
//	while(p.sz())
//	{
//		cout<<p.top().len<<" "<<p.top().flag<<endl;
//		p.pop();
//	}
	while(y>0)
	{
		if(p.empty()) break;
		node u=p.top();
//		cout<<u.len<<endl;
		p.pop();
		if(u.flag==1)
		{
			int v=u.len;
			v=v/2-1;
			int minn=min(v,y);
			sum+=2*minn;
			if(minn==v) sum++;
			y-=minn;
		}
		else
		{
			int v=u.len;
			if(v<=2) break;
			v=v/2;
			int minn=min(v,y);
			sum+=2*minn;
			y-=minn;
		}
	}
	cout<<sum<<endl;
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