#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")

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
int h,w,n,r,c,e,pl[210][210],vis[210][210],f[210][210],sx,sy,tx,ty,dirx[4]={0,0,-1,1},diry[4]={-1,1,0,0},jl[210][210];
string s[210];
struct node
{
	int x,y,nl;
	map<PI,int> mp;
};
void bfs()
{
	queue<node> q;
	map<PI,int> p;
	q.push({sx,sy,0,p});
	while(!q.empty())
	{
		auto u=q.front();
		q.pop();
//		cout<<u.x<<" "<<u.y<<" "<<u.nl<<endl;
		vis[u.x][u.y]=1;
		if(u.x==tx&&u.y==ty) break;
		if(f[u.x][u.y]>u.nl&&u.mp[{u.x,u.y}]==0)
		{
			u.mp[{u.x,u.y}]==1;
			u.nl=f[u.x][u.y];
		}
		if(u.nl<=pl[u.x][u.y]||pl[u.x][u.y]>=h*w) continue;
		pl[u.x][u.y]=u.nl;
		jl[u.x][u.y]++;
		for(int i=0;i<4;i++)
		{
			int xx=dirx[i]+u.x,yy=diry[i]+u.y;
//			&&u.nl-1>=f[xx][yy]&&f[xx][yy]<h*w
			if(xx>=0&&xx<h&&yy>=0&&yy<w&&s[xx][yy]!='#'&&jl[xx][yy]<=50)
			{
				q.push({xx,yy,u.nl-1,u.mp});
			}
		}
	}
}
void solve()
{
	cin>>h>>w;
	for(int i=0;i<h;i++) cin>>s[i];
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			if(s[i][j]=='S') sx=i,sy=j;
			if(s[i][j]=='T') tx=i,ty=j;
		}
	}
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>r>>c>>e;
		f[r-1][c-1]=e;
	}
	bfs();
	if(vis[tx][ty]) yes;
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