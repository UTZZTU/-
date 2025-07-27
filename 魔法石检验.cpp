#include <stdio.h>
#include <math.h>
int num[16][16];
int cs[16][16];
int n;
bool fun1()
{
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cs[i][j]=(cs[i-1][j]+cs[i-1][j-1]+cs[i-1][j+1]+cs[i-2][j]+num[i-1][j])%2;
		}
	}
	for(int j=1;j<=n;j++)
	{
		if(num[n][j]!=(cs[n][j-1]+cs[n][j+1]+cs[n-1][j]+cs[n][j])%2)
		return false;
	}
	return true;
}
void fun2()
{
	int c;
	for(c=1;c<=n;c++)
	{
		cs[1][c]=0;
	}
	while(fun1()==false&&cs[1][n+1]==0)
	{
		cs[1][1]++;
		c=1;
		while(cs[1][c]>1)
		{
			cs[1][c]=0;
			c++;
			cs[1][c]++;
		}
	}
}
int main ()
{
	int i,j,sum=0;
	char s[20];
	scanf("%d",&n);
	getchar();
	for(j=0;j<=n+1;j++)
	{
		cs[0][j]=num[0][j]=0;
	}
	for(i=0;i<=n;i++)
	{
		cs[i][0]=cs[i][n+1]=num[i][0]=num[i][n+1]=0;
	}
	for(i=1;i<=n;i++)
	{
		gets(s);
		for(j=0;s[j]!='\0';j++)
		{
			if(s[j]=='w')
			num[i][j+1]=1;
			else num[i][j+1]=0;
		}
	}
	fun2();
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(cs[i][j]==1)
				sum+=cs[i][j];
			}
		}
		if(cs[1][n+1]==1)
	    printf("inf");
		else printf("%d",sum);
	return 0;
}
