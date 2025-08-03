#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> vec[200010];
int n,a[200010],p;
int dfs(int x)
{
	if(vec[x].empty()) return a[x];
	int minn=0x3f3f3f3f;
	for(auto c:vec[x])
	{
		minn=min(minn,dfs(c));
	}
	if(x==1)
	{
		return minn+a[x];
	}
	if(minn>=a[x])
	{
		return (minn+a[x])/2;
	}
	else
	{
		return minn;
	}
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		vec[i].clear();
	}
	for(int i=2;i<=n;i++)
	{
		cin>>p;
		vec[p].push_back(i);
	}
	cout<<max(dfs(1),a[1])<<endl;
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