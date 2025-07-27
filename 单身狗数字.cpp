#include <stdio.h>
int main ()
{
	int n,i,w=0;
	scanf("%d",&n);
	if(n>=1&&n<=9)
	{
		for(i=1;i<=n;i++)
		if(i==1)
		w++;
	}
	else if (n>=10&&n<=99)
	{
		for(i=10;i<=n;i++)
		{
			if(i/10==1)
			w++;
			if(i%10==1)
			w++;
		}
		w+=1;
	}
	else if(n>=100&&n<=999)
	{
		for( i=100;i<=n;i++)
		{
			if(i/100==1)
			w++;
			if(i%100/10==1)
			w++;
			if(i%10==1)
			w++;
		}
		w+=20;
	}
	else if(n>=1000&&n<=9999)
	{
		for(i=1000;i<=n;i++)
		{
			if(i/1000==1)
			w++;
			if(i%1000/100==1)
			w++;
			if(i%100/10==1)
			w++;
			if(i%10==1)
			w++;
		}
		w+=300;
	}
	else if(n==10000)
	w=w+4001;
	printf("%d",w);
	return 0;
}

