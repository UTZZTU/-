#include <bits/stdc++.h>
using namespace std;
int x,y,m,f[1010],a[3];
int main ()
{
	cin>>x>>y>>m;
	a[1]=x,a[2]=y;
	for(int i=1;i<=2;i++)
	{
		for(int j=a[i];j<=m;j++)
		f[j]=max(f[j],f[j-a[i]]+a[i]);
	}
	cout<<f[m];
	return 0;
}