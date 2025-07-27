#include <stdio.h>
void fun(int *p,int s,int t)
{
	int i,j,q;
	p=p+s;
	for(i=0;i<t-s;i++)
	{
		for(j=0;j<t-i-s;j++)
		{
			if(p[j]>p[j+1])
			{
				q=p[j];
				p[j]=p[j+1];
				p[j+1]=q;
			}
		}
	}
}
int main ()
{
	int n,s,t,i,c[100],*p;
	p=c;
	while(scanf("%d%d%d",&n,&s,&t)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&c[i]);
		}
		fun(p,s,t);
		for(i=0;i<n-1;i++)
		{
			printf("%d ",c[i]);
		}
		printf("%d",c[n-1]);
		printf("\n");
	}
	return 0;
}
