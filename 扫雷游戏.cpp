#include<stdio.h>
#include <string.h>
int main ()
{
	char s[105][105],q[105];
	int a[105][105];
	memset(a,0,sizeof(a));
	int n,m,i,j;
	scanf("%d%d",&n,&m);
	getchar();
	for(i=1;i<=n;i++)
	{
		scanf("%s",q);
		for(j=0;q[j]!='\0';j++)
		{
			s[i][j+1]=q[j];
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(s[i][j]=='*')
			a[i][j]=-1;
			else
			{
				if(s[i-1][j]=='*')
				a[i][j]++;
				if(s[i+1][j]=='*')
				a[i][j]++;
				if(s[i][j-1]=='*')
				a[i][j]++;
				if(s[i][j+1]=='*')
				a[i][j]++;
				if(s[i-1][j-1]=='*')
				a[i][j]++;
				if(s[i+1][j+1]=='*')
				a[i][j]++;
				if(s[i+1][j-1]=='*')
				a[i][j]++;
				if(s[i-1][j+1]=='*')
				a[i][j]++;
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(a[i][j]==-1)
			printf("*");
			else
			printf("%d",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}