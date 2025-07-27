#include <bits/stdc++.h>
using namespace std;
int a[1010][1010],n,h[1010],l[1010],maxx;
int main ()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
			h[i]+=a[i][j];
			l[j]+=a[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i][j])
			continue;
			maxx=max(maxx,h[i]+l[j]-a[i][j]);
		}
	}
	cout<<maxx;
	return 0;
}