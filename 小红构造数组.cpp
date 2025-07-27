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
#define int long long

using ll = long long;
using u32 = unsigned int;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;
using f128 = __float128;

int x,cnt,maxx,fcnt;
map<int,int> mp;
pair<int,int> p[110];
void solve()
{
	cin>>x;
	if(x==1)
	{
		cout<<-1;
		return;
	}
	for(int i=2;i*i<=x;i++)
	{
		if(x%i==0)
		{
			while(x%i==0)
			{
				x/=i;
				mp[i]++;
				cnt++;
			}
		}
	}
	if(x>1)
	{
		mp[x]++;
		cnt++;
	}
	for(auto [u,v]:mp)
	{
		p[++fcnt]={v,u};
		maxx=max(maxx,(ll)v);
	}
	if(maxx>(cnt+1)/2)
	{
		cout<<-1;
		return;
	}
	cout<<cnt<<endl;
	priority_queue<pair<int,int>> q;
	for(int i=1;i<=fcnt;i++)
	{
		q.push(p[i]);
	}
	while(q.sz()>=2)
	{
		auto xx=q.top();
		q.pop();
		auto yy=q.top();
		q.pop();
		cout<<xx.se<<" "<<yy.se<<" ";
		xx.fi--;
		yy.fi--;
		if(xx.fi) q.push(xx);
		if(yy.fi) q.push(yy);
	}
	if(!q.empty()) cout<<q.top().se;
}
signed main ()
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