#include <bits/stdc++.h>
using namespace std;
int g[210][210],n,m,k,a[210],b[210];
int main ()
{
	scanf("%d %d",&n,&m);
	for(int i=1,u,v;i<=m;i++)
	{
		scanf("%d %d",&u,&v);
		g[u][v]=g[v][u]=1;
	}
	scanf("%d",&k);
	for(int i=1,l;i<=k;i++)
	{
		memset(b,0,sizeof(b));
		int pd1=0,pd2=0,zx=-1;
		scanf("%d",&l);
		for(int j=1;j<=l;j++)
		{
			scanf("%d",&a[j]);
			b[a[j]]=1;
		}
		for(int j=1;j<l;j++)
		{
			for(int k=j+1;k<=l;k++)
			{
				if(!g[a[j]][a[k]])
				{
					pd1=1;
					break;
				}
			}
		}
		if(pd1)
		printf("Area %d needs help.\n",i);
		else
		{
			for(int j=1;j<=n;j++)
			{
				int sum=0;
				if(b[j])
				continue;
				for(int k=1;k<=l;k++)
				{
					if(g[j][a[k]]||g[a[k]][j])
					sum++;
					else
					break;
				}
				if(sum==l)
				{
					zx=j;
					pd2=1;
					break;
				}
			}
			if(pd2)
			printf("Area %d may invite more people, such as %d.\n",i,zx);
			else
			printf("Area %d is OK.\n",i);
		}
	}
	return 0;
}