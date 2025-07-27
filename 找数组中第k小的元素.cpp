#include <bits/stdc++.h>
using namespace std;
int n,k,f[1010];
int main ()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>f[i];
	}
	sort(f+1,f+1+n);
	cout<<f[k];
	return 0;
}