#include <stdio.h>
int fun(char *p)
{
	int i,num=0,s=0;
	for(i=0;p[i]!='\0';i++)
	{
		if(p[i]==' ')
		s=0;
		else if(s==0)
		{
			s=1;
			num++;
		}
	}
	return num;
}
int main ()
{
	int t;
	char s[100],*p;
	scanf("%d",&t);
	getchar();
	for(int i=1;i<=t;i++)
	{
		gets(s);
		p=s;
		printf("%d",fun(p));
		if(i!=t)
		printf("\n");
	}
	return 0;
}
