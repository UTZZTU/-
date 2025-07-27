#include <stdio.h>
struct p
{
	int xb;
	char s[10];
}x[100];
int main ()
{
	int n,i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d %s",&x[i].xb,x[i].s);
	}
	for(i=1;i<=n/2;i++)
	{
		for(j=n;j>n/2;j--)
		{
			if(x[j].xb!=x[i].xb&&x[j].xb!=-1)
			{
				printf("%s %s\n",x[i].s,x[j].s);
				x[j].xb=-1;
				break;
			}
		}
	}
	return 0;
}