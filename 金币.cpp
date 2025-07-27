#include <stdio.h>
int main ()
{
	long long n,day=0;
	int i,j,pd=0;
	scanf("%lld",&n);
    for(i=1;;i++)
	{
		if(n>i*7)
		{
			n-=i*7;
			day+=7;
		}
		else
		{
			for(j=1;j<=7;j++)
			{
				n-=i;
				day+=1;
				if(n<=0)
				{
					pd=1;
					break;
				}
			}
		}
		if(pd==1)
		break;
	 } 
	 printf("%lld",day);
	 return 0;
}
