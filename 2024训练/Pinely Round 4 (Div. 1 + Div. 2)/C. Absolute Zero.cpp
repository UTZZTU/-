#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,f[1010],temp[1010];
void dfs(int level,vector<int> vec)
{
	
	int minn=100,maxx=0;
	for(int i=1;i<=n;i++)
	{
		minn=min(minn,f[i]);
		maxx=max(maxx,f[i]);
		temp[i]=f[i];
	}
	if(minn==maxx&&minn==0)
	{
		for(auto c:vec)
		{
			cout<<c<<" ";
		}
		cout<<endl;
		return;
	}
	if(level>=20) return;
	for(int i=minn==0?1:minn;i<=maxx;i++)
	{
		for(int j=1;j<=n;j++)
		{
			f[j]=abs(f[j]-i);
		}
		vec.push_back(i);
		dfs(level+1,vec);
		vec.pop_back();
		for(int j=1;j<=n;j++)
		{
			f[j]=temp[j];
		}
	}
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>f[i];
	}
	vector<int> vec;
	dfs(1,vec);
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int _=1;
	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}