#include <stdio.h>
#include <string.h>
void fun(char *p)
{
	int len,i,j,t;
	len=strlen(p);
	for(i=0;i<len-1;i++)
	{
		for(j=0;j<len-1-i;j++)
		{
			if(p[j]>p[j+1])
			{
				t=p[j+1];
				p[j+1]=p[j];
				p[j]=t;
			}
		}
	}
	
}
int main ()
{
	char s[100],*p;
	p=s;
	gets(s);
	fun(p);
	printf("%s",s);
	return 0;
}
