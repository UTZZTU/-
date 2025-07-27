#include <stdio.h>
int main ()
{
	int a,b,n,sum=0,s;
	scanf("%d %d %d",&a,&b,&n);
	s=b;
	if(n==b)
	{
		printf("1");
	}
	else 
	{
	while(1)
	{
		sum++;
		if(s+b-a>=n)
		{
			sum+=2;
			break;
		}
		else 
		{
		s=s+b-a;
		sum++;
	    }
	}
	printf("%d",sum);
}
return 0;
}
