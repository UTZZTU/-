#include <bits/stdc++.h>
using namespace std;
int t,n,m[1010][1010],f[1010];
bool judge()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j) continue;
			if(m[i][j]!=(f[i]|f[j])) return false;
		}
	}
	return true;
}
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			f[i]=0;
			for(int j=1;j<=n;j++)
			{
				scanf("%d",&m[i][j]);
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=29;j++)
			{
				int flag=1;
				for(int k=1;k<=n;k++)
				{
					if(k==i) continue;
					if((m[i][k] >> j)&1)
					{
						;
					}
					else 
					{
						flag=0;
						break;
					}
				}
				if(flag) f[i]+=(int)pow(2,j);
			}
//			printf("%d\n",f[i]);
		}
		if(judge())
		{
			puts("YES");
			for(int i=1;i<=n;i++)
			{
				printf("%d ",f[i]);
			}
			printf("\n");
		}
		else puts("NO");
	}
	return 0;
}