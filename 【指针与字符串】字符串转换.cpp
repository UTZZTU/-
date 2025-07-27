#include <stdio.h>
void fun(char *p)
{
	int i;
	for(i=0;p[i]!='\0';i++)
	{
		if(p[i]>='a'&&p[i]<='j')
		{
			p[i]-=49;
		}
	}
}
int main ()
{
	char s[100],*p;
	p=s;
	while(gets(s)!=NULL)
	{
		fun(p);
		puts(s);
	}
	return 0;
}
