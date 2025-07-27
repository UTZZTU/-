#include <stdio.h>
void fun(int *p,int w)
{
	int i,j,t;
	for(i=0;i<w;i++)
	{
		for(j=0;j<w-i;j++)
		{
			if(p[j]<p[j+1])
			{
				t=p[j];
				p[j]=p[j+1];
				p[j+1]=t;
			}
		}
	}
}
int main ()
{
	int c[30],i,*p;
	int n,s,t;
	while(scanf("%d%d%d",&n,&s,&t)!=EOF)
	{
		p=c;
		for(i=0;i<n;i++)
		{
			scanf("%d",&c[i]);
		}
		p+=s-1;
		fun(p,t-s);
		for(i=0;i<n-1;i++)
		{
			printf("%d ",c[i]);
		}
		printf("%d",c[n-1]);
		printf("\n");
	}
	return 0;
}
