#include <stdio.h>
int fun(char *p)
{
	int i,sum=0;
	for(i=0;p[i]!='\0';i++)
	{
		if(p[i]=='a'||p[i]=='e'||p[i]=='i'||p[i]=='o'||p[i]=='u'||p[i]=='A'||p[i]=='E'||p[i]=='I'||p[i]=='O'||p[i]=='U')
		sum++;
	}
	return sum;
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
