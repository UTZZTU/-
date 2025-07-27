#include <stdio.h>
#include <string.h>
void fun(char *p,char *q)
{
	strcpy(q,p);
}
int main ()
{
	int t;
	char s[1000],*p,b[1000],*q;
	scanf("%d",&t);
	getchar();
	for(int i=1;i<=t;i++)
	{
		gets(s);
		p=s;
		q=b;
		fun(p,q);
		printf("%s",b);
		if(i!=t)
		printf("\n");
	}
	return 0;
}
