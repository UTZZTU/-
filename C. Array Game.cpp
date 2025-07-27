#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,f[100010];
void solve()
{
	cin>>n>>k;
	f[n+1]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>f[i];
	}
	if(k>=3)
	{
		cout<<0<<endl;
		return;
	}
	if(k==1)
	{
		sort(f+1,f+1+n);
		int minn=f[1];
		for(int i=2;i<=n;i++)
		{
			minn=min(minn,f[i]-f[i-1]);
		}
		cout<<minn<<endl;
	}
	else
	{
		sort(f+1,f+1+n);
		int minn=f[1];
		for(int i=2;i<=n;i++)
		{
			int x=f[i]-f[i-1];
			minn=min(minn,x);
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				int x=f[j]-f[i];
				int pos=lower_bound(f+1,f+1+n,x)-f;
				minn=min(minn,abs(f[pos]-x));
				minn=min(minn,abs(f[pos-1]-x));
			}
		}
		cout<<minn<<endl;
		return;
	}
}
signed main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}