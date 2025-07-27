#include <bits/stdc++.h>
using namespace std;
int f[30010],n,m,v[100],p[100];
int main ()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	cin>>v[i]>>p[i];
	for(int i=1;i<=m;i++)
	{
		for(int j=n;j>=v[i];j--)
		f[j]=max(f[j],f[j-v[i]]+v[i]*p[i]);
	}
	cout<<f[n];
	return 0;
}