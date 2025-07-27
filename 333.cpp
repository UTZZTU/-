#include <stdio.h>
void fun(char *p,char *q)
{
	int m=0;
	for(int i=0;p[i]!='\0';i++)
	{
		if(p[i]!='*')
		{
			q[m]=p[i];
			m++;
		}
	}
	q[m]='\0';
}
int main ()
{
	char c[100],*p,b[100],*q;
	gets(c);
	p=c;
	q=b;
	fun(p,q);
	printf("%s",b);
	return 0;
}
