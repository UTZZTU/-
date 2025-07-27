#include <stdio.h>
int fun(char s[],char w)
{
	int i,sum=0;
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]==w)
		sum++;
	}
	return sum;
}
int main ()
{
	int t,i;
	char s[1000],w;
	scanf("%d%*c",&t);
	for(i=1;i<=t;i++)
	{
		gets(s);
		scanf("%c%*c",&w);
		printf("%d\n",fun(s,w));
	}
	return 0;
}
