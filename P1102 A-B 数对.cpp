#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;
int main ()
{
	ll n,c,a[200010],i,ans=0;
	map<ll,ll>mp;
	cin>>n>>c;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		mp[a[i]]++;
		a[i]-=c;
	}
	for(i=1;i<=n;i++)
	ans+=mp[a[i]];
	cout<<ans;
	return 0;
}