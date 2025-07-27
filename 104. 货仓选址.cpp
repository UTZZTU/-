#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans;
int a[100010],n;
int main ()
{
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<n;i++)
	ans+=abs(a[i]-a[n/2]);
	cout<<ans;
	return 0;
}