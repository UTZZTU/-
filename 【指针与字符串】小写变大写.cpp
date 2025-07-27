#include <stdio.h>
void fun(char *p,char *q)
{
	int i;
	for(i=0;p[i]!='\0';i++)
	{
		if(p[i]>='a'&&p[i]<='z')
		q[i]=p[i]-32;
		else q[i]=p[i];
	}
	q[i]='\0';
}
int main ()
{
	char s[1000],*p,w[1000],*q;
	while(gets(s)!=NULL)
	{
		p=s;
		q=w;
		fun(p,q);
		printf("%s\n",w);
	}
	return 0;
}
