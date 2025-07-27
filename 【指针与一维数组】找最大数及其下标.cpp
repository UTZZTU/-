#include <stdio.h>
int main ()
{
	int n,c[20],*p,max,s,*q;
	while(scanf("%d",&n)!=EOF)
	{
		max=-999999;
		if(n==0)
		break;
		else
		{
			p=&max;
			q=&s;
			for(int i=0;i<n;i++)
			{
				scanf("%d",&c[i]);
				if(c[i]>*p)
				{
					*p=c[i];
					*q=i;
				}
			}
			printf("%d %d\n",max,s);
		}
	}
	return 0;
}
