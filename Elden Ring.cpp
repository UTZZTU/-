#include <bits/stdc++.h>
using namespace std;
int a[2020],n,m,k,k1,k2;
int main ()
{
	cin>>n>>m>>k;
	for(int i=1;i<=2*n;i++)
	a[i]=i;
	k1=0;
	k2=n;
	for(int i=1;i<=k;i++)
	{
		k1++;
		k2++;
		if(k1>n)
		k1=1;
		if(k2>2*n)
		k2=n+1;
		if(i%m==0)
		swap(a[k1],a[k2]);
	}
	for(int i=1;i<=2*n;i++)
	cout<<a[i]<<" ";
	return 0;
}