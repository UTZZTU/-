#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[200010],sum,res;
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		res+=(sum-a[i])*a[i];
	}
	cout<<res;
	return 0;
}