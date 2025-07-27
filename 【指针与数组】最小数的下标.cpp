#include <stdio.h>
int fun(int *p,int n)
{
	int min,t;
	min=9999999;
	for(int i=0;i<n;i++)
	{
		if(p[i]<min)
		{
			min=p[i];
			t=i;
		}
	}
	return t;
}
int main ()
{
	int n,c[100],*p;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d",&c[i]);
		}
		p=c;
		printf("%d\n",fun(p,n));
	}
	return 0;
}
