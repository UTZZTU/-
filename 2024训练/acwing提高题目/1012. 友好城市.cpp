#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,f[5010];
pair<int,int> p[5010];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i].first>>p[i].second;
	}
	sort(p+1,p+1+n);
	for(int i=0;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(p[j].second>p[i].second) f[j]=max(f[j],f[i]+1);
		}
	}
	int maxx=0;
	for(int i=1;i<=n;i++)
	{
		maxx=max(maxx,f[i]);
	}
	cout<<maxx;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int _=1;
//	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}