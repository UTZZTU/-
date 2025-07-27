#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[30][10010],v,n,w[30];
int main ()
{
	cin>>v>>n;
	for(int i=1;i<=v;i++)
	cin>>w[i];
	f[0][0]=1;
	for(int i=1;i<=v;i++)
	{
		for(int j=0;j<=n;j++)
		{
			for(int k=0;k*w[i]<=j;k++)
			f[i][j]+=f[i-1][j-k*w[i]];
		}
	}
	cout<<f[v][n];
	return 0;
}