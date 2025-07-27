#include <bits/stdc++.h>
using namespace std;
int n,f[200010],l[200010],r[200010];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>f[i];
		l[i]=min(l[i-1]+1,f[i]);
	}
	for(int i=n;i>=1;i--)
	{
		r[i]=min(r[i+1]+1,f[i]);
	}
	int maxx=0;
	for(int i=1;i<=n;i++)
	{
		maxx=max(maxx,min(l[i],r[i]));
	}
	cout<<maxx<<endl;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}