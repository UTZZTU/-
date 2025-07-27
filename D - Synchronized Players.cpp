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

int n,px1=-1,py1=-1,px2=-1,py2=-1,vis[65][65][65][65],f[65][65][65][65],dirx[4]={0,0,-1,1},diry[4]={-1,1,0,0},minn=0x3f3f3f3f;
string s[65];
struct Node
{
	int a,b,c,d;
};
void bfs()
{
	queue<Node> q;
	q.push({px1,py1,px2,py2});
	while(!q.empty())
	{
		auto [a,b,c,d]=q.front();
		q.pop();
		if(vis[a][b][c][d]) continue;
		vis[a][b][c][d]=1;
		for(int i=0;i<4;i++)
		{
			int na=dirx[i]+a,nb=diry[i]+b;
			int nc=dirx[i]+c,nd=diry[i]+d;
			if(na>=0&&na<n&&nb>=0&&nb<n&&s[na][nb]!='#')
			{
				;
			}
			else
			{
				na=a;
				nb=b;
			}
			if(nc>=0&&nc<n&&nd>=0&&nd<n&&s[nc][nd]!='#')
			{
				;
			}
			else
			{
				nc=c;
				nd=d;
			}
			f[na][nb][nc][nd]=min(f[na][nb][nc][nd],f[a][b][c][d]+1);
			q.push({na,nb,nc,nd});
		}
	}
}
void solve()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(s[i][j]=='P')
			{
				if(px1==-1)
				{
					px1=i;
					py1=j;
				}
				else
				{
					px2=i;
					py2=j;
				}
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k1=0;k1<n;k1++)
			{
				for(int k2=0;k2<n;k2++)
				{
					f[i][j][k1][k2]=0x3f3f3f3f;
				}
			}
		}
	}
	f[px1][py1][px2][py2]=0;
	bfs();
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			minn=min(minn,f[i][j][i][j]);
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
//	cin>>_;
	while(_--)
	{
		solve();
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}