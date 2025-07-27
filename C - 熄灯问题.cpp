#include <stdio.h>
int num[6][8];
int cs[6][8];
bool fun1()
{
	for(int i=2;i<=5;i++)
	{
		for(int j=1;j<=6;j++)
		{
			cs[i][j]=(cs[i-1][j]+cs[i-1][j-1]+cs[i-1][j+1]+cs[i-2][j]+num[i-1][j])%2;
		}
	}
	for(int j=1;j<=6;j++)
	{
		if(num[5][j]!=(cs[5][j-1]+cs[5][j+1]+cs[4][j]+cs[5][j])%2)
		return false;
	}
	return true;
}
void fun2()
{
	int c;
	for(c=1;c<=6;c++)
	{
		cs[1][c]=0;
	}
	while(!fun1())
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
	int i,j;
	for(j=0;j<=7;j++)
	{
		cs[0][j]=num[0][j]=0;
	}
	for(i=0;i<=5;i++)
	{
		cs[i][0]=cs[i][7]=num[i][0]=num[i][7]=0;
	}
	for(i=1;i<=5;i++)
	{
		for(j=1;j<=6;j++)
		{
			scanf("%d",&num[i][j]);
		}
	}
	fun2();
	for(i=1;i<=5;i++)
	{
		for(j=1;j<=5;j++)
		{
			printf("%d ",cs[i][j]);
		}
		printf("%d",cs[i][6]);
		if(i!=5)
		printf("\n");
	}
	return 0;
}
