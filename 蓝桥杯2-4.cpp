#include <bits/stdc++.h>
using namespace std;
char s[31][61];
int f[31][61];
int main ()
{
	for(int i=1;i<=30;i++)
	{
		scanf("%s",s[i]+1);
	}
	f[1][1]=s[1][1]-'0';
	for(int i=2;i<=60;i++)
	f[1][i]=f[1][i-1]+s[1][i]-'0';
	for(int i=2;i<=30;i++)
	f[i][1]=f[i-1][1]+s[i][1]-'0';
	for(int i=2;i<=30;i++)
	{
		for(int j=2;j<=60;j++)
		{
			f[i][j]=max(f[i][j-1],f[i-1][j])+s[i][j]-'0';
		}
	}
	cout<<f[30][60];
	return 0;
}