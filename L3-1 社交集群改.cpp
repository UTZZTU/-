#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
int b[1005][1005];
int main ()
{
	int d[1005],n,i,j,k,e1[1005],max=0,w,sum,t[1005],m;
	memset(b,0,sizeof(b));
	memset(e1,0,sizeof(e1));
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		d[i]=i;
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d:",&w);
		for(j=1;j<=w;j++)
		{
			scanf("%d",&k);
			b[k][i]=1;
			if(i>e1[k])
			e1[k]=i;
			if(k>max)
			max=k;
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=max;j++)
		{
			if(b[j][i]==1)
			{
				for(w=1;w<=e1[j];w++)
				{
					if(b[j][w]==1)
					{
						d[w]=d[i];
					}
				}
			}
		}
	}
	sort(d+1,d+n+1);
	m=0;
	for(i=1;i<=n;i++)
	{
		sum=1;
		while(d[i+1]==d[i]&&i+1<=n)
		{
			sum++;
			i++;
		}
		t[m]=sum;
		m++;
	}
	sort(t,t+m);
	printf("%d\n",m);
	for(i=m-1;i>0;i--)
	printf("%d ",t[i]);
	printf("%d",t[i]);
	return 0;
}