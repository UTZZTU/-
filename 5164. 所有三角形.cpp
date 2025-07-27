#include <bits/stdc++.h>
using namespace std;
int c,f[3][200010],res;
int main ()
{
	scanf("%d",&c);
	for(int i=1;i<=2;i++)
	{
		for(int j=1;j<=c;j++)
		{
			scanf("%d",&f[i][j]);
		}
	}
	for(int i=1;i<=2;i++)
	{
		for(int j=1;j<=c;j++)
		{
			if(f[i][j]) res+=3;
			if(f[i][j]&&f[i][j-1]) res-=2;
			if(f[i][j]&&f[i-1][j]&&j&1) res-=2;
		}
	}
	cout<<res;
	return 0;
}