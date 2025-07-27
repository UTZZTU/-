#include <bits/stdc++.h>
using namespace std;
int n,d[100010];
void solve()
{
	int res=0;
	cin>>n;
	for(int i=1;i<=n;i++) d[i]=0;
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		d[u]++;
		d[v]++;
	}
	for(int i=1;i<=n;i++)
	{
		if(d[i]==1) res++;
	}
	cout<<(res+1)/2<<endl;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}