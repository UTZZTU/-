#include <stdio.h>
#include <math.h>
int fun(int num)
{
	unsigned int i,half;
	if(num<=1)
	return 0;
	if(num==2||num==3)
	return 1;
	else if(num%6!=1&&num%6!=5)
	return 0;
	half=(unsigned int)sqrt(num);
	for(i=5;i<=half;i+=6)
	{
		if((num%i==0||num%(i+2)==0))
		return 0;
	}
	return 1;
}
int main ()
{
	int m,n,i,p,j,s,min,max;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		p=1;
		for(i=m;;i++)
		{	
		    if(fun(i))
		    {
		    	min=i;
		    	break;
			}
			if(i==n)
			{
				p=0;
				break;
			}
		}
		if(p!=0)
		{
			for(i=n;;i--)
		{
			if(fun(i))
			{
				max=i;
				break;
			}
		}
		}
		if(p==0)
		printf("No\n");
		else
		printf("%d %d\n",min,max);
	}
	return 0;
}
