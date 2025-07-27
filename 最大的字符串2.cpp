#include <stdio.h>
#include <string.h>
int main ()
{
	char s[100],w[100];
	int t,n,i,j;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%d",&n);
		gets(s);
		strcpy(w,s);
		for(j=1;j<=n;j++)
		{
			gets(s);
			if(strcmp(s,w)>0)
			strcpy(w,s);
		}
		printf("%s",w);
		if(i!=t)
		printf("\n");
	}
	return 0;
}
