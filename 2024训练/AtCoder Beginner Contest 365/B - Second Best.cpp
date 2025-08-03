#include <bits/stdc++.h>
using namespace std;
int f[1100],n,g[1010];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>f[i];
		g[i]=f[i];
	}
	sort(f+1,f+1+n);
	for(int i=1;i<=n;i++)
	{
		if(g[i]==f[n-1])
		{
			cout<<i<<endl;
			return;
		}
	}
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