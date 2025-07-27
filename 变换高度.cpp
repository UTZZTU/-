#include <stdio.h>
#include <string.h>
int main ()
{
	int a[200010],n,k,i,j,x,max=0,min=99999999,sum,s=0;
	memset(a,0,sizeof(a));
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		a[x]++;
		if(x>max)
		max=x;
		if(x<min)
		min=x;
	}
	for(i=max;i>min;i--)
	{
		a[i-1]+=a[i];
	}
	for(i=max;i>min;i--)
	{
		sum=0;
		sum+=a[i];
		while(sum<=k&&i>min)
		{
			i--;
			sum+=a[i];
		}
		sum-=a[i];
		i++;
		s++;
	}
	printf("%d",s);
	return 0;
}
