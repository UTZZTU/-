#include <bits/stdc++.h>
using namespace std;
int n,maxx,f[1000000],q;
int main ()
{
	cin>>n;
	for(int i=2;i<=n/i;i++)
	{
		if(n%i==0)
		{
			int p=n;
			for(int j=i;p%j==0;p/=j,j++)
			{
				f[i]++;
			}
			if(f[i]>maxx)
			{
				maxx=f[i];
				q=i;
			}
		}
	}
	if(maxx==0)
	{
		cout<<1<<endl<<n;
		return 0;
	}
	cout<<f[q]<<endl;
	for(int i=q;i<=q+f[q]-1;i++)
	{
		if(i!=q) cout<<"*";
		cout<<i;
	}
	return 0;
}