#include <bits/stdc++.h>
using namespace std;
int a[4],b[4],t;
bool compare(int x[],int y[])
{
	int win=0,lost=0;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(x[i]>y[j])
			win++;
			else if(x[i]<y[j])
			lost++;
		}
	}
	return win>lost;
}
bool check()
{
	for(int i=1;i<=10;i++)
	{
		for(int j=1;j<=10;j++)
		{
			for(int k=1;k<=10;k++)
			{
				for(int u=1;u<=10;u++)
				{
					int c[4]={i,j,k,u};
					if(compare(a,b)&&compare(b,c)&&compare(c,a))
					return true;
					if(compare(b,a)&&compare(a,c)&&compare(c,b))
					return true;
				}
			}
		}
	}
	return false;
}
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		for(int i=0;i<4;i++)
		scanf("%d",&a[i]);
		for(int i=0;i<4;i++)
		scanf("%d",&b[i]);
		if(check())
		puts("yes");
		else
		puts("no");
	}
	return 0;
}