#include <stdio.h>
#include <string.h>
int main ()
{
	int i,n,m,len;
	char s[110],*p,w[110];
	gets(s);
	p=s;
	len=strlen(s);
	m=0;
	scanf("%d",&n);
	for(i=0;s[i]!='\0';i++)
	{
		if(i==n)
		{
			w[len-1]=*p;
		}
		else
		{
			w[m]=*p;
			m++;
		}
		p++;
	}
	w[len]='\0';
	printf("%s",w);
	return 0;
}
