#include <bits/stdc++.h>
using namespace std;
int main ()
{
	int n,m,a[110],js=0;
	cin>>n>>m;
	m=m%n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=(n-m+1)%n;i<=n;i++,js++)
	{
		if(i==0)
		i=n;
		if(js!=0)
		cout<<" ";
		cout<<a[i];
	}
	for(int i=1;i<=(n-m)%n;i++,js++)
	{
		if(js!=0)
		cout<<" ";
		cout<<a[i];
	}
	return 0;
}