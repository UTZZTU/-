#include <stdio.h>
#include <string.h>
int main ()
{
	int n,l,i;
	char w,s[10010];
	scanf("%d %c",&n,&w);
	getchar();
	gets(s);
	l=strlen(s);
	if(n>=l)
	{
		for(i=1;i<=n-l;i++)
		printf("%c",w);
		printf("%s",s);
	}
	else
	{
		for(i=l-n;i<l;i++)
		printf("%c",s[i]);
	}
	return 0;
}