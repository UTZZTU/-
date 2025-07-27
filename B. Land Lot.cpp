#include <bits/stdc++.h>
using namespace std;
const double Eps = 1e-8;
const double PI = atan(-1.0);

#define pb push_back
#define pf push_front
#define cl clear
#define fi first
#define se second
#define bg begin
#define ed end
#define sz size
#define fd find
#define PI pair<int,int>
#define Um unordered_map
#define Mul multiset
#define VI vector<int>
#define VII vector< vector<int> > 
#define VS vector<string>
#define VN vector<node>
#define VP vector< pair<int,int> >
#define debug(x) cout<<"x"<<endl
#define IOS ios::sync_with_stdio(false);cin.tie(0)
#define Mem(x) memset(x,0,sizeof x)

using ll = long long;
using u32 = unsigned int;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;
using f128 = __float128;

int f[110][110],a,b,n,m,minn=0x3f3f3f3f;
int get_num(int x,int y,int xx,int yy)
{
	int sum=0;
	for(int i=x-xx+1;i<=x;i++)
	{
		for(int j=y-yy+1;j<=y;j++)
		{
			sum+=f[i][j];
		}
	}
	return sum;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>f[i][j];
		}
	}
	cin>>a>>b;
	for(int i=a;i<=n;i++)
	{
		for(int j=b;j<=m;j++)
		{
			minn=min(minn,get_num(i,j,a,b));
		}
	}
	for(int i=b;i<=n;i++)
	{
		for(int j=a;j<=m;j++)
		{
			minn=min(minn,get_num(i,j,b,a));
		}
	}
	cout<<minn<<endl;
}
int main ()
{
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
//	cout.tie(0);
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