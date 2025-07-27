#include <stdio.h>
#include <string.h>
char s1[100010][20];
int main ()
{
	int n,m,a[100010],i,j;
	memset(a,0,sizeof(a));
	char s[20];
	scanf("%d",&n);
	getchar();
	for(i=0;i<n;i++)
	{
		scanf("%s",s1[i]);
	}
	scanf("%d",&m);
	getchar();
	for(i=0;i<m;i++)
	{
		scanf("%s",s);
		for(j=0;j<n;j++)
		{
			if(strcmp(s,s1[j])==0)
			{
				a[j]++;
				break;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		if(a[i]!=0)
		printf("%s\n",s1[i]);
	}
	return 0;
}
