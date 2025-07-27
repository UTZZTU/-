#include <stdio.h>
int main ()
{
	int m,n,c,max;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		max=0;
		if(m>n)
		{
			c=m;
			m=n;
			n=c;
		}
		for(int i=1;i<=m;i++)
		{
			if(m%i==0&&n%i==0)
			max=i;
		}
		printf("%d\n",max);
	}
	return 0;
}
