#include <stdio.h>
int main ()
{
	int i,sum;
	char s[100],*p;
	gets(s);
	p=s;
	sum=0;
	for(i=0;s[i]!='\0';i++)
	{
		if(*p>='0'&&*p<='9')
		sum++;
		p++;
	}
	printf("%d",sum);
	return 0;
}
