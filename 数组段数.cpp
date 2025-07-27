#include <bits/stdc++.h>
using namespace std;
int n,m,f[200010],pre[200010];
int l,r;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>f[i];
		if(i==1)
		{
			pre[i]=1;
		}
		else
		{
			if(f[i]==f[i-1]) pre[i]=pre[i-1];
			else pre[i]=pre[i-1]+1;
		}
	}
	while(m--)
	{
		cin>>l>>r;
		if(pre[l]==pre[l-1]) cout<<pre[r]-pre[l-1]+1<<endl;
		else
		cout<<pre[r]-pre[l-1]<<endl;
	}
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