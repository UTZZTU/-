#include <bits/stdc++.h>
using namespace std;
int f[100000];
int a[1010],c[1010],n,m,sum;
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(f,30000,sizeof(f));
	cin>>n>>m;
	f[0]=0;
	for(int i=1;i<=n;i++)
	cin>>c[i];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=sum;j>=a[i];j--)
		f[j]=min(f[j],f[j-a[i]]+c[i]);
	}
	for(int i=sum;i>=0;i--)
	{
		if(f[i]<=m)
		{
			cout<<i;
			return 0;
		}
	}
}