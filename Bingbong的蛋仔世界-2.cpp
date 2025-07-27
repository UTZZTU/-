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
int n,m,k,dx,dy,res,f[510][510],vis[510][510],dirx[4]={0,0,-1,1},diry[4]={-1,1,0,0};
int x,y;
//struct node
//{
//	int x,y,t;
//};
//void bfs()
//{
//	queue<node> q;
//	q.push({dx,dy,0});
//	while(!q.empty())
//	{
//		auto p=q.front();
//		q.pop();
//		if(vis[p.x][p.y]) continue;
//		vis[p.x][p.y]=1;
//		for(int i=0;i<4;i++)
//		{
//			int xx=p.x+dirx[i],yy=p.y+diry[i];
//			if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&!vis[xx][yy]&&p.t+1<=min((n+1)/2,(m+1)/2)&&xx>p.t&&xx<=n-p.t&&yy>p.t&&yy<=m-p.t)
//			{
//				q.push({xx,yy,p.t+1});
//			}
//		}
//	}	
//}
void solve()
{
	cin>>n>>m>>k;
	dx=n/2+1,dy=m/2+1;
	for(int i=1;i<=k;i++)
	{
		int flag=0;
		cin>>x>>y;
//		f[x][y]++;
		if(x==dx&&y==dy)
		{
			flag=1;
		}
		else if(x==dx)
		{
			flag=1;
		}
		else if(y==dy)
		{
			flag=1;
		}
		else if(x<dx&&y<dy)
		{
			int t=y-1;
			if(x+t>=dx) flag=1;
			t=x-1;
			if(y+t>=dy) flag=1;
		}
		else if(x<dx&&y>dy)
		{
			int t=x-1;
			if(y-t<=dy) flag=1;
			t=m-y;
			if(x+t>=dx) flag=1;
		}
		else if(x>dx&&y<dy)
		{
			int t=y-1;
			if(x-t<=dx) flag=1;
			t=n-x;
			if(y+t>=dy) flag=1;
		}
		else
		{
			int t=m-y;
			if(x-t<=dx) flag=1;
			t=n-x;
			if(y-t<=dy) flag=1;
		}
		res+=flag;
	}
//	bfs();
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=m;j++)
//		{
//			cout<<vis[i][j]<<" ";
//			if(vis[i][j])
//			{
//				res+=f[i][j];
//			}
//		}
//		cout<<endl;
//	}
	pr(res);
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