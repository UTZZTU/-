#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;
int main ()
{
	int n,i,j,k;
	char s[1010];
	scanf("%d",&n);
	getchar();
	scanf("%s",s);
	for(i=1;i<n;i++)
	{
		for(j=1;j<n;j++)
		{
			k=min(j,i);
			printf("%c",s[k-1]);
		}
		printf("%c",s[i-1]);
		for(j=n-1;j>=1;j--)
		{
			k=min(j,i);
			printf("%c",s[k-1]);
		}
		printf("\n");
	 } 
	 printf("%s",s);
	 for(i=n-2;i>=0;i--)
	 printf("%c",s[i]);
	 printf("\n");
	 for(i=n-1;i>=1;i--)
	{
		for(j=1;j<n;j++)
		{
			k=min(j,i);
			printf("%c",s[k-1]);
		}
		printf("%c",s[i-1]);
		for(j=n-1;j>=1;j--)
		{
			k=min(j,i);
			printf("%c",s[k-1]);
		}
		if(i!=1)
		printf("\n");
	 } 
}
