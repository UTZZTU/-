#include <bits/stdc++.h>
using namespace std;
int n,k,a[1010];
int main ()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+1+n);
	cout<<a[n-k+1];
	return 0;
}