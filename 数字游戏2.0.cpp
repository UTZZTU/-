#include<stdio.h>
int main ()
{
	int t,a,i,sum,js;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		sum=0;
		js=0;
		scanf("%d",&a);
		sum+=1;
		js++;
		while(sum<a)
		{
			if(sum*3<=a)
			{
				sum*=3;
				js++;
			}
			else if(sum*2<=a)
			{
				sum*=2;
				js++;
			}
			else if(sum+1<=a)
			{
				sum++;
				js++;
			}
		}
		printf("%d",js);
		if(i!=t)
		printf("\n");
	}
	return 0;
 } 
