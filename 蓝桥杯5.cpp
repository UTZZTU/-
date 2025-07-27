#include <bits/stdc++.h>
using namespace std;
int a[110][110],f[110][110],minn=10000;
int main ()
{
	a[1][1]=1;
	f[1][1]=1;
	for(int i=1;i<=100;i++)
	{
		for(int j=1;j<=100;j++)
		{
			if(a[i][j])
			continue;
			if(j==1)
			a[i][j]=a[i-1][j]+1;
			else
			a[i][j]=a[i][j-1]+2;
			f[i][j]=f[i-1][j]+f[i][j-1]-f[i-1][j-1]+a[i][j];
		}
	}
	for(int i=1;i<=100;i++)
	{
		for(int j=1;j<=100;j++)
		{
			for(int k1=i;k1<=100;k1++)
			{
				for(int k2=j;k2<=100;k2++)
				{
					if(f[k1][k2]-f[i-1][k2]-f[k1][j-1]+f[i-1][j-1]==2022)
					{
						minn=min(minn,(k1+1-i)*(k2+1-j));
					}
				}
			}
		}
	}
	cout<<minn;
	return 0;
}