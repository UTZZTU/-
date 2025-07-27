#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,v,a[1010],b[1010],f[1010];
int main ()
{
	cin>>n>>v;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=v;j>=a[i];j--)
		f[j]=max(f[j],f[j-a[i]]+b[i]);
	}
	cout<<f[v];
	return 0;
}