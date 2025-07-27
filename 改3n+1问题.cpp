#include <stdio.h>
int main ()
{
	int n;
scanf("%d",&n);
for(int i=1;i<=n;i++)
{
	int sum=0;
int x1,y1,x2,y2;
scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
for(int a=1;a<=100000000;a++)
{
	if(x1==x2&&y1==y2)
	{
	break;
}
else 
{
	if(x1<x2)
	{
		if(y1-y2>0)
		{
			if(x1+y1-y2==x2)
			{
			sum=sum+y1-y2;
			break;
		}
		else 
		{
			sum=sum+y1+1;
			y1=x1+y1+1;
			x1=0;
		}
	}
	else
	{
		sum=sum+y1+1;
			y1=x1+y1+1;
			x1=0;
	}
	}
	else if(x1>=x2)
	{
		sum=sum+y1+1;
			y1=x1+y1+1;
			x1=0;
	}
}
}
printf("Case %d: %d\n",i,sum);
}
	return 0;
 } 
