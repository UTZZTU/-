#include <stdio.h>
int main ()
{
	int a1[5],a2[5],b1[2],b2[2],sum1=0,sum2=0,i,j;
	for(i=0;i<5;i++)
	scanf("%d",&a1[i]);
	for(i=0;i<2;i++)
	scanf("%d",&b1[i]);
	for(i=0;i<5;i++)
	scanf("%d",&a2[i]);
	for(i=0;i<2;i++)
	scanf("%d",&b2[i]);
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(a1[i]==a2[j])
			{
				sum1++;
				break;
			}
		}
	}
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			if(b1[i]==b2[j])
			{
				sum2++;
				break;
			}
		}
	}
	if(sum1==5&&sum2==2)
	{
		printf("5000000");
	}
	else if(sum1==5&&sum2==1)
	{
		printf("250000");
	}
	else if(sum1==5||sum1==4&&sum2==2)
	{
		printf("3000");
	}
	else if(sum1==4&&sum2==1||sum1==3&&sum2==2)
	{
		printf("200");
	}
	else if(sum1==4||sum1==3&&sum2==1||sum1==2&&sum2==2)
	{
		printf("10");
	}
	else if(sum1==3||sum1==1&&sum2==2||sum1==2&&sum2==1||sum2==2)
	{
		printf("5");
	}
	else
	printf("0");
	return 0;
}
