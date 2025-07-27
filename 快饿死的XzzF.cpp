#include <bits/stdc++.h>
using namespace std;
int f[50][2],n;
int main ()
{
	cin>>n;
	f[1][1]=1;
	f[1][0]=1;
	for(int i=2;i<=n;i++)
	{
		f[i][1]+=f[i-1][0]+f[i-1][1];
		f[i][0]+=f[i-1][1];
	}
	cout<<f[n][0]+f[n][1];
	return 0;
}