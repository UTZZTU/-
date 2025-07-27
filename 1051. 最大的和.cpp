#include <bits/stdc++.h>
using namespace std;
int t,n,f[50010],s,maxx,gg[50010],hh[50010];
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n;
		maxx=-0x3f3f3f3f;
		s=-0x3f3f3f3f;
		gg[0]=-0x3f3f3f3f;
		for(int i=1;i<=n;i++)
		{
			cin>>f[i];
			s=max(s,0)+f[i];
			gg[i]=max(gg[i-1],s);
		}
		hh[n+1]=-0x3f3f3f3f;
		s=-0x3f3f3f3f;
		for(int i=n;i>=1;i--)
		{
			s=max(s,0)+f[i];
			hh[i]=max(hh[i+1],s);
		}
		for(int i=1;i<n;i++)
		{
			maxx=max(maxx,gg[i]+hh[i+1]);
		}
		cout<<maxx<<endl;
	}
	return 0;
}