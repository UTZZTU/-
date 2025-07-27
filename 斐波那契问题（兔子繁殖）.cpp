#include <stdio.h>
int main ()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==1)
	printf("1\n");
	else if(n==2)
	printf("1\n");
	else 
	{
		int a=1,b=1,c;
		for(int i=3;i<=n;i++)
		{
			c=a+b;
			a=b;
			b=c;
		}
		printf("%d\n",c);
	}
	}
	return 0;
}
