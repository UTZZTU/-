#include <bits/stdc++.h>
using namespace std;
int n,k,i,j;
int main ()
{
	cin>>n>>k;
	i=n-k+1;
	j=1;
	while(i<=n)
	{
		cout<<i<<" ";
		if(j<=n-k)
		{
			cout<<j<<" ";
		}
		i++,j++;
	}
	while(j<=n-k)
	{
		cout<<j<<" ";
		j++;
	}
	return 0;
}