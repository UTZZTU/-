#include <stdio.h>
#include <string.h>
int main ()
{
	char s[100];
	int n,i,l;
	scanf("%d",&n);
	getchar();
	for(i=1;i<=n;i++)
	{
		gets(s);
		l=strlen(s);
		if(s[l-1]=='0'||s[l-1]=='2'||s[l-1]=='4'||s[l-1]=='6'||s[l-1]=='8')
		printf("even");
		else
		printf("odd");
		if(i!=n)
		printf("\n");
	}
	return 0;
}
