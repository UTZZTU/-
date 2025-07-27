#include <stdio.h>
#include <string.h>
int main ()
{
	int a[10],y,n,i,x,sum=0,q,j;
	scanf("%d%d",&y,&n);
	for(i=0;;i++)
	{
		j=4;
		sum=0;
		memset(a,0,sizeof(a));
		q=y+i;
		while(j--)
		{
			a[q%10]=1;
			q/=10;
		}
		for(j=0;j<10;j++)
		sum+=a[j];
		if(sum==n)
		{
			printf("%d %04d",i,y+i);
			break;
		}
	}
	return 0;
}