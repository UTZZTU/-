#include <stdio.h>
#include <string.h>
int main ()
{
	int i,j,a[26],max=0;
	memset(a,0,sizeof(a));
	char s;
	for(i=1;i<=4;i++)
	{
		while(scanf("%c",&s)!=EOF)
		{
			if(s=='\n')
			break;
			else
			{
			if(s>='A'&&s<='Z')
			{
				a[s-'A']++;
			}
			}
		}
	}
	for(i=0;i<=25;i++)
	if(a[i]>max)
	max=a[i];
	for(i=max;i>=1;i--)
	{
		for(j=0;j<=25;j++)
		{
			if(a[j]>=i)
			{
				printf("*");
			}
			else
			printf(" ");
			if(j!=25)
			printf(" ");
		}
		printf("\n");
	}
	for(i=0;i<=24;i++)
	printf("%c ",i+'A');
	printf("%c",i+'A');
	return 0;
}
