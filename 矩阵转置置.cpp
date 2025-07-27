#include <bits/stdc++.h>
using namespace std;
int n,f[110][110];
int main ()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&f[i][j]);
		}
	}
	for(int i=n;i>=1;i--)
	{
		for(int j=n;j>=1;j--)
		{
			printf("%d ",f[i][j]);
		}
		printf("\n");
	}
	return 0;
}