#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,a[200010],res;
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int i=1,j=n;
	while(k--)
	{
		if(a[i]*a[i+1]>=a[j]*a[j-1])
		{
			res+=a[i]*a[i+1];
			i+=2;
		}
		else
		{
			res+=a[j]*a[j-1];
			j-=2;
		}
	}
	cout<<res;
	return 0;
}