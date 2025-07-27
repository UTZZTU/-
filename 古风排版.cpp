#include <stdio.h>
#include <string.h>
int main ()
{
	char s[1005];
	int n,i,j,l,k;
	scanf("%d",&n);
	getchar();
	gets(s);
	l=strlen(s);
	k=l/n*n;
	for(i=k;i<k+n;i++)
	{
		for(j=i;j>=0;j-=n)
		{
			if(j>=l)
			printf(" ");
			else
			printf("%c",s[j]);
		}
		printf("\n");
	}
	return 0;
}