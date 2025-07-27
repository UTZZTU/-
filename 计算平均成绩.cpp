#include <stdio.h>
int main ()
{
	int t,n,sum,s;
	double w;
	int c[30];
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		sum=0;
		s=0;
		scanf("%d",&n);
		for(int a=0;a<n;a++)
		{
			scanf("%d",&c[a]);
			sum+=c[a];
		}
		w=sum*1.0/n;
		for(int a=0;a<n;a++)
		{
			if(c[a]>w)
			s++;
		}
		printf("%.2f %d",w,s);
		if(i!=t)
		printf("\n");
	}
	return 0;
}
