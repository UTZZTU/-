#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[100010],l,r=(ll)pow(2,31),mid,n;
bool check(ll x)
{
	for(int i=1;i<n;i++)
	{
		cout<<f[i]&x<<" "<<f[i+1]&x<<endl;
		if(!(f[i]&x<f[i+1]&x))
	    return false;
	}
	return true;
}
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>f[i];
	while(l<r)
	{
		mid=(l+r)/2;
		if(check(mid))
		r=mid;
		else
		l=mid+1;
	}
	cout<<l;
	return 0;
}