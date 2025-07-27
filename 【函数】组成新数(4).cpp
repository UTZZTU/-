#include <stdio.h>
int fun(int n)
{
	int c[100],i,t,js,sum;
	i=1,t=0,js=1,sum=0;
	while(n!=0)
	{
		if(i%2==1)
		{
			c[t]=n%10;
			t++;
		}
		n/=10;
		i++;
	}
	for(i=0;i<t;i++)
	{
		sum+=c[i]*js;
		js*=10;
	}
	return sum;
}
int main ()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
		break;
		else
		{
			printf("%d\n",fun(n));
		}
	}
	return 0;
}
