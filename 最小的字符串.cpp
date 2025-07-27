#include <stdio.h>
#include <string.h>
int main ()
{
	int t,n;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%d",&n);
		char a[100],b[100]={'z'},ch;
		ch=getchar();
		for(int s=1;s<=n;s++)
		{
			gets(a);
			if(strcmp(b,a)>0)
			{
				b[0]=0;
				strcat(b,a);
			}
		}
		printf("%s",b);
		if(i!=t)
		printf("\n");
	}
	return 0;
}
