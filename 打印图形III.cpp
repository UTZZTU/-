#include<stdio.h>
int main ()
{
	char s[100];
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	s[i]='A'+i;
	s[i]='\0';
	for(i=n;i>=1;i--)
	{
		for(j=i-1;j<=i+n-2;j++)
		{
			if(j>n-1)
			printf(" ");
			else
			printf("%c",s[j]);
		}
		j--;
		for(j;j>=i-1;j--)
		{
			if(j>n-1)
			printf(" ");
			else
			printf("%c",s[j]);
		}
		printf("\n");
	}
	i+=2;
	for(i;i<=n;i++)
	{
		for(j=i-1;j<=i+n-2;j++)
		{
			if(j>n-1)
			printf(" ");
			else
			printf("%c",s[j]);
		}
		j--;
		for(j;j>=i-1;j--)
		{
			if(j>n-1)
			printf(" ");
			else
			printf("%c",s[j]);
		}
		printf("\n");
	}
	return 0;
}