#include <bits/stdc++.h>
using namespace std;
int n,m,k,f[1010],r,c,res;
void solve()
{
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		f[i]=-1;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>r>>c;
		if(f[r]==-1)
		{
			f[r]=c;
		}
		else
		{
			f[r]=min(f[r],c);
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(f[i]!=-1)
		{
			res+=f[i];
		}
	}
	cout<<min(res,k);
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