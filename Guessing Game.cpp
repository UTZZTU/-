#include <stdio.h>
#include <cstring>
int main ()
{
	int n,max=10,min=0,sum;
	while(scanf("%d",&n)!=EOF)
	{
		sum=0;
		if(n==0)
		break;
		else
		{
		char str1[8];
		gets(str1);
		char str2[]="too high";
		sum=strcmp(str1,str2);
			if(sum==0)
			{
				if(n-1<max)
				max=n-1;
			}
			else
			{
				char str3[]="too low";
				sum=strcmp(str1,str3);
		if(sum==0)
		{
			if(n+1>min)
			min=n+1;
		}
		else
		{
			char str4[]="right on";
			sum=strcmp(str1,str4);
		if(sum==0)
		{
			if(min>max)
			printf("Stan is dishonest\n");
			else
			{
				if(n>=min&&n<=max)
				printf("Stan may be honest\n");
				else printf("Stan is dishonest\n");
			}
			max=10;
			min=0;
		}
	}
		}
	}
	}
	return 0;
}
