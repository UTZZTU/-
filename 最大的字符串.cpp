#include <stdio.h>
#include <string.h>
int main ()
{
	int t,n;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%d",&n);
		char a[100],b[100];
		gets(a);
		strcpy(b,a);
		for(int s=1;s<=n;s++)
		{
			gets(a);
			if(strcmp(a,b)>0)
			{
				strcpy(b,a);
			}
		}
		printf("%s",b);
		if(i!=t)
		printf("\n");
	}
	return 0;
}
