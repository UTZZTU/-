#include <bits/stdc++.h>
using namespace std;
int f[1010],sum[1010],n,a,b;
int main ()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		cin>>f[i];
		sum[i]=sum[i-1]+f[i];
	}
	cin>>a>>b;
	cout<<sum[b-1]-sum[a-1];
	return 0;
}