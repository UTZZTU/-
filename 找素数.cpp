#include <stdio.h>
int main ()
{
	int m,n;
	scanf("%d %d",&m,&n);
	if(m>=n)
	{
		for(int i=n;i<=m;i++)
		{
			int w=2;
			for(int a=2;a<i;a++)
			{
				if(i%a==0)
				break;
				else  w++;
			}
			if(w==i)
			printf("%d ",i);
		}
	}
	else
	{
		for(int i=m;i<=n;i++)
		{
			int w=2;
			for(int a=2;a<i;a++)
			{
				if(i%a==0)
				break;
				else  w++;
			}
			if(w==i)
			printf("%d ",i);
		}
	}
	return 0;
}
