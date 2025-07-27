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
#define no cout<<"No"<<'\n'
#define yes cout<<"Yes"<<'\n'
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
int n,m,x,dp[100010],vis[100010],pos1,pos2,pos3,pos4,cnt,dirx[4]={0,0,-1,1},diry[4]={-1,1,0,0};
string s[100010];
struct Node
{
	int pos;
	int num;
	inline bool operator<(const Node &x)const
	{
		return num>x.num;
	}
};
void solve()
{
	priority_queue<Node> p;
	cnt=0;
	cin>>n>>m>>x;
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(s[i][j]=='S')
			{
				pos1=i,pos2=j;
			}
			else if(s[i][j]=='T')
			{
				pos3=i,pos4=j;
			}
			dp[cnt]=0x3f3f3f3f;
			vis[cnt++]=0;
		}
	}
	p.push({pos1*m+pos2,0});
	while(!p.empty())
	{
		auto q=p.top();
		p.pop();
		if(vis[q.pos]) continue;
		vis[q.pos]=1;
		dp[q.pos]=q.num;
		int dx=q.pos/m,dy=q.pos%m;
		for(int i=0;i<4;i++)
		{
			int xx=dx+dirx[i],yy=dy+diry[i];
			if(xx>=0&&xx<n&&yy>=0&&yy<m&&!vis[xx*m+yy])
			{
				if(s[xx][yy]=='T')
				p.push({xx*m+yy,q.num});
				else p.push({xx*m+yy,q.num+(s[xx][yy]-'0')});
			}
		}
	}
	int pos=pos3*m+pos4;
	if(dp[pos]<x) yes;
	else no;
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