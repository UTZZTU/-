#include <bits/stdc++.h>
using namespace std;
int n,m,a[100],b[100],c[100],res;
int main ()
{
	c[0]=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		c[i]=c[i-1]*a[i];
	}
	for(int i=1;i<=n;i++)
	{
		b[i]=((m%c[i])-res)/c[i-1];
		cout<<b[i]<<" ";
		res+=b[i]*c[i-1];
	}
	return 0;
}