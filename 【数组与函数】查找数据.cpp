#include <stdio.h>
int fun(int *p1,int *p2,int *p3)
{
	for(int i=0;i<*p3;i++)
	{
		if(*p1==*p2)
		return 1;
		else p1++;
	}
	return 0;
}
int main ()
{
	int t,n,c[10],x,*p1,*p2,*p3;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%d",&n);
		for(int a=0;a<n;a++)
		{
			scanf("%d",&c[a]);
		}
		scanf("%d",&x);
		p1=c;
		p2=&x;
		p3=&n;
		if(fun(p1,p2,p3))
		{
			printf("find!");
		}
		else printf("no find!");
		if(i!=t)
		printf("\n");
	}
	return 0;
}
