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

int n,m,dist[1010][1010][4],sx,sy,tx,ty,dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
string s[1010];
struct node
{
	int x,y,pos,cnt;
};
void bfs()
{
	queue<node> q;
	for(int i=0;i<4;i++)
	{
		q.push({sx,sy,i,0});
		dist[sx][sy][i]=0;
	}
	while(!q.empty())
	{
		auto p=q.front();
		q.pop();
//		cout<<p.x<<" "<<p.y<<" "<<p.pos<<" "<<p.cnt<<endl;
//		if(dist[p.x][p.y][p.pos]!=-1) continue;
//		dist[p.x][p.y][p.pos]=p.cnt;
		if(s[p.x][p.y]=='.'||s[p.x][p.y]=='S'||s[p.x][p.y]=='T')
		{
			int xx=dx[p.pos]+p.x,yy=dy[p.pos]+p.y;
			if(xx>=0&&xx<n&&yy>=0&&yy<m&&(dist[xx][yy][p.pos]==-1||dist[xx][yy][p.pos]>p.cnt+1)&&s[xx][yy]!='#')
			{
				dist[xx][yy][p.pos]=p.cnt+1;
				q.push({xx,yy,p.pos,p.cnt+1});
			}
		}
		else
		{
			for(int i=0;i<4;i++)
			{
				if(i==p.pos||(i+p.pos)&1)
				{
					int xx=dx[i]+p.x,yy=dy[i]+p.y;
					if(xx>=0&&xx<n&&yy>=0&&yy<m&&(dist[xx][yy][i]==-1||dist[xx][yy][i]>p.cnt+1)&&s[xx][yy]!='#')
					{
						dist[xx][yy][i]=p.cnt+1;
						q.push({xx,yy,i,p.cnt+1});
					}
				}
			}
		}
		
	}
}
void solve()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(s[i][j]=='S') sx=i,sy=j;
			else if(s[i][j]=='T') tx=i,ty=j;
			for(int k=0;k<4;k++)
			{
				dist[i][j][k]=-1;
			}
		}
	}
	bfs();
	int minn=0x3f3f3f3f;
	for(int i=0;i<4;i++)
	{
		if(dist[tx][ty][i]!=-1)
		{
			minn=min(minn,dist[tx][ty][i]);
		}
	}
	if(minn==0x3f3f3f3f) pr(-1);
	else pr(minn);
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