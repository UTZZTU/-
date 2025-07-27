#include <bits/stdc++.h>
using namespace std;
int a[11][22];
int ans;
int main ()
{
	int k,n;
	cin>>k>>n;
	for(int i=1;i<=k;i++)
	{
		for(int j=1,u;j<=n;j++)
		{
			scanf("%d",&u);
			a[i][u]=j;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j)
			continue;
			int pd=0;
			for(int u=1;u<=k;u++)
			{
				if(a[u][i]>a[u][j])
				{
					pd=1;
					break;
				}
			}
			if(!pd)
			{
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}