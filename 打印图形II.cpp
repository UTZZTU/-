#include <stdio.h>
int main ()
{
	int n,i;
	scanf("%d",&n);
	char s[300];
	for(i=0;i<n;i++)
	{
		s[i]=s[2*(n-1)-i]='A'+i;
	}
	s[2*n-1]='\0';
	for(i=0;i<n-1;i++)
	{
		printf("%s\n",s);
		s[i]=s[2*(n-1)-i]=' ';
	}
	printf("%s\n",s);
	for(i=n-2;i>=0;i--)
	{
		s[i]=s[2*(n-1)-i]='A'+i;
		printf("%s\n",s);
	}
	return 0;
}