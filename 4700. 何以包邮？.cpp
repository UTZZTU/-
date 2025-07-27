#include <bits/stdc++.h>
using namespace std;
int n,x,f[300010],a[35],maxx;
int main ()
{
	cin>>n>>x;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxx+=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=maxx;j>=a[i];j--)
		f[j]=max(f[j],f[j-a[i]]+a[i]);
	}
	for(int i=1;i<=maxx;i++)
	{
		if(i==f[i]&&f[i]>=x)
		{
			cout<<f[i];
			return 0;
		}
	}
	return 0;
}