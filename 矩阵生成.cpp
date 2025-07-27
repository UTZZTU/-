#include <bits/stdc++.h>
using namespace std;
int f[50][50],dx,dy,m;
int main ()
{
	cin>>m;
	dx=1;
	dy=m/2+1;
	f[dx][dy]=1;
	for(int i=2;i<=m*m;i++)
	{
		if(dx==1&&dy!=m)
		{
			dx=m;
			dy++;
		}
		else if(dy==m&&dx!=1)
		{
			dy=1;
			dx--;
		}
		else if(dx==1&&dy==m)
		{
			dx++;
		}
		else
		{
			if(!f[dx-1][dy+1])
			dx--,dy++;
			else
			dx++;
		}
		f[dx][dy]=i;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			printf("%d",f[i][j]);
			if(j==m)
			cout<<endl;
			else
			cout<<" ";
		}
	}
	return 0;
}