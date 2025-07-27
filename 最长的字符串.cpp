#include <stdio.h>
#include <string.h>
int main ()
{
	int t,n;
	scanf("%d",&t);
    for(int c=1;c<=t;c++)
	{
		char a[100],b[100];
		scanf("%d",&n);
		gets(a);
		strcpy(b,a);
		for(int i=0;i<n;i++)
		{
         gets(a);
		if(strlen(b)<strlen(a))
		strcpy(b,a);
		}
        printf("%s",b);
		if(c!=t)
		printf("\n");
	}
	return 0;
}

