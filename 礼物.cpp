#include<stdio.h>
#include <string.h>
int main ()
{
	long long sum,a[1010],b[1010];
	int n,m,i,x,y,v,j;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&v);
		a[x]+=v;
		b[y]+=v;
	}
	sum=0;
	for(i=1;i<=n;i++)
	{
		if(a[i]>sum)
			sum=a[i];
		if(b[i]>sum)
		sum=b[i];
	}
	printf("%lld",sum);
	return 0;
 } 
