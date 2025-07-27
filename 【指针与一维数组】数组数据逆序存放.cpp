#include <stdio.h>
int main ()
{
	int n,c[20],*p1,*p2,m;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
		break;
		else
		{
			for(int i=0;i<n;i++)
			{
				scanf("%d",&c[i]);
			}
			p1=c;
			p2=c+n-1;
			for(int a=0;a<n/2;a++)
			{
				m=*p1;
				*p1=*p2;
				*p2=m;
				p1++;
				p2--;
			}
			for(int i=0;i<n-1;i++)
			{
				printf("%d ",c[i]);
			}
			printf("%d",c[n-1]);
			printf("\n");
		}
	}
	return 0;
}
