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

string s[200010];
int n,m,k,minn=0x3f3f3f3f;
int get_num(int x,int y)
{
	int res1=0x3f3f3f3f,num1=0,flag1=1;
	int res2=0x3f3f3f3f,num2=0,flag2=1;
	for(int i=x;i<=x+k-1;i++)
	{
		if(i>=n||s[i][y]=='x')
		{
			flag1=0;
			break;
		}
		if(s[i][y]=='.')
		{
			num1++;
		}
	}
	if(flag1) res1=num1;
	for(int i=y;i<=y+k-1;i++)
	{
		if(i>=m||s[x][i]=='x')
		{
			flag2=0;
			break;
		}
		if(s[x][i]=='.')
		{
			num2++;
		}
	}
	if(flag2) res2=num2;
	return min(res1,res2);
}
void solve()
{
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(s[i][j]=='o'||s[i][j]=='.')
			{
				int num=get_num(i,j);
				minn=min(minn,num);
			}
		}
	}
	if(minn==0x3f3f3f3f) cout<<-1<<endl;
	else cout<<minn<<endl;
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