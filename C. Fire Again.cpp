#include <bits/stdc++.h>
using namespace std;
const double Eps = 1e-8;
const double PI = atan(-1.0);
const int N = 1e6+5;
const int M = 1e6+5;

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

int n,m,maxx=-1,kk,px,py;
pair<int,int> p[15];
void solve()
{
	cin>>n>>m>>kk;
	for(int i=1;i<=kk;i++)
	{
		cin>>p[i].fi>>p[i].se;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int num=0x3f3f3f3f;
			for(int k=1;k<=kk;k++)
			{
				num=min(num,abs(p[k].fi-i)+abs(p[k].se-j));
			}
			if(num>maxx)
			{
				maxx=num;
				px=i,py=j;
			}
		}
	}
	cout<<px<<" "<<py<<endl;
}
int main ()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
//	cout.tie(0);
	int _=1;
//	cin>>_;
	while(_--)
	{
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}