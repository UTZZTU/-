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
int n,m,kk,minn=0x3f3f3f3f,pre[200010];
void solve()
{
	cin>>n>>m>>kk;
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(s[i][j]=='x') continue;
			int cnt=1;
			int k=j;
			while(k<m&&s[i][k]!='x')
			{
				if(s[i][k]=='.') pre[cnt]=1;
				else pre[cnt]=0;
				pre[cnt]+=pre[cnt-1];
				if(cnt>=kk)
				{
					minn=min(minn,pre[cnt]-pre[cnt-kk]);
				}
				k++;
				cnt++;
			}
			k--;
			j=k;
//			cout<<minn<<endl;
//			cout<<i<<" "<<j<<endl;
		}
	}
	for(int j=0;j<m;j++)
	{
		for(int i=0;i<n;i++)
		{
			if(s[i][j]=='x') continue;
			int cnt=1;
			int k=i;
			while(k<n&&s[k][j]!='x')
			{
				if(s[k][j]=='.') pre[cnt]=1;
				else pre[cnt]=0;
				pre[cnt]+=pre[cnt-1];
				if(cnt>=kk)
				{
					minn=min(minn,pre[cnt]-pre[cnt-kk]);
				}
				k++;
				cnt++;
			}
			k--;
			i=k;
//			cout<<minn<<endl;
//			cout<<i<<" "<<j<<endl;
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