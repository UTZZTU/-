#include <stdio.h>
#include <string.h>
int main ()
{
	char s[105];
	int n,m,p,i,j,a[26];
    scanf("%d%d%d",&n,&m,&p);
	getchar();
	memset(a,0,sizeof(a));
	for(i=1;i<=n;i++)
	{
		gets(s);
		for(j=0;j<m;j++)
		{
			a[s[j]-'A']+=1;
		}
	}
	for(i=1;i<=p;i++)
	{
		gets(s);
		for(j=0;s[j]!='\0';j++)
		{
			a[s[j]-'A']-=1;
		}
	}
	for(i=0;i<26;i++)
	{
		for(j=0;j<a[i];j++)
		{
			printf("%c",i+'A');
		}
}
	return 0;
 } 
