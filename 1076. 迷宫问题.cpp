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
int n,dirx[4]={0,-1,0,1},diry[4]={-1,0,1,0};
PI p[1010][1010];
int s[1010][1010];
void bfs(int x,int y)
{
	queue<PI> q;
	q.push({x,y});
	p[x][y]={0,0};
	while(!q.empty())
	{
		auto pt=q.front();
		q.pop();
		for(int i=0;i<4;i++)
		{
			int xx=dirx[i]+pt.fi,yy=diry[i]+pt.se;
			if(xx<0||xx>=n||yy<0||yy>=n) continue;
			if(s[xx][yy]==0&&p[xx][yy].fi==-1)
			{
				p[xx][yy]=pt;
				q.push({xx,yy});
			}
		}
	}
}
void solve()
{
	memset(p,-1,sizeof p);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>s[i][j];
		}
	}
	bfs(n-1,n-1);
	PI pp={0,0};
	cout<<pp.fi<<" "<<pp.se<<endl;
	if(n==0) return;
	while(1)
	{
		pp=p[pp.fi][pp.se];
		cout<<pp.fi<<" "<<pp.se<<endl;
		if(pp.fi==n-1&&pp.se==n-1) break;
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