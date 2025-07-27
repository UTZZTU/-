#include <stdio.h>
int main ()
{
	int s,i,x,n,e,sum=0;
	for(s=1;s<=9;s++)
	{
		for(i=0;i<=9;i++)
		{
			for(x=0;x<=9;x++)
			{
				for(n=1;n<=9;n++)
				{
					for(e=0;e<=9;e++)
					{
							if(3*(100*s+10*i+x)==2*(1010*n+100*i+e))
							sum++;
					}
				}
			}
		}
	}
	printf("%d",sum);
}
