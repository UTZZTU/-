#include <stdio.h>
#include <iostream>
using namespace std;
int main ()
{
	int x,n,sum=0,i;
	scanf("%d%d",&x,&n);
	if(n>7-x)
	{
		if(x<=5)
		{
			sum+=(5-x+1)*250;
		}
		n-=7-x+1;
		sum+=n/7*5*250;
		sum+=250*min(n%7,5);
	}
	else
	{
		for(i=1;i<=n;i++)
		{
			if(x<=5)
			sum+=250;
			x++;
			if(x>7)
			x=1;
		}
	}
	printf("%d",sum);
	return 0;
}