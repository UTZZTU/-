#include <stdio.h>
#include <string.h>
int main ()
{
	int t,n,l,len;
	scanf("%d",&t);
    for(int c=1;c<=t;c++)
	{
		len=1000;
		char a[100],b[100],ch;
		scanf("%d",&n);
		ch=getchar();
		for(int i=0;i<n;i++)
		{
         gets(a);
         l=strlen(a);
		if(l<=len)
		{
			strcpy(b,a);
			len=l;
		}
		}
        printf("%s",b);
		if(c!=t)
		printf("\n");
	}
	return 0;
}

