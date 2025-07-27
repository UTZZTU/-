#include <stdio.h>
int main ()
{
	int t;
	char a[100],b[100],ch;
	scanf("%d",&t);
	ch=getchar();
	for(int i=1;i<=t;i++)
	{
		gets(a);
		gets(b);
		printf("%s%s",a,b);
		if(i!=t)
		printf("\n");
	}
	return 0;
}
