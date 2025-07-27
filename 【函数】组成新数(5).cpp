#include <stdio.h>
int fun(int m,int n)
{
	int c;
	c=m/10*1000+n%10*100+m%10*10+n/10;
	return c;
}
int main ()
{
	int m,n;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		if(m==0&&n==0)
		break;
		else
		{
			printf("%d\n",fun(m,n));
		}
	}
	return 0;
}
