#include <bits/stdc++.h>
using namespace std;
int f[1010][1010];
int main ()
{
	int m,n;
	while(cin>>m>>n)
	{
		for(int i=0;i<=m;i++)
		f[1][i]=1;
		for(int i=0;i<=n;i++)
		f[i][0]=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(j<i)
				f[i][j]=f[j][j];
				else
				f[i][j]=f[i-1][j]+f[i][j-i];
			}
		}
		cout<<f[n][m]<<endl;
	}
	return 0;
}