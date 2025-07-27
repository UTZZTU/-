#include <bits/stdc++.h>
using namespace std;
int n,k,m,f[55],judge,tt[1010];
int main ()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&f[i]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int k1=j+1;k1<=n;k1++)
			{
				for(int k2=k1+1;k2<=n;k2++)
				{
					if((f[i]+f[j]+f[k1]+f[k2])%4==0)
					tt[(f[i]+f[j]+f[k1]+f[k2])/4]++;
				}
			}
		}
	}
	while(k--)
	{
		int judge=0;
		scanf("%d",&m);
		while(m--)
		{
			scanf("%d",&n);
			if(!tt[n]) judge++;
		}
		if(!judge) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}