#include <bits/stdc++.h>
using namespace std;
int n,a[15],maxx;
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	cout<<maxx*n;
	return 0;
}