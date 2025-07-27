#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,f[200010];
int main ()
{
	cin>>n;
	if(n==0)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=200000;i++) f[i]=i;
	ll l=1,r=200010;
	while(l<r)
	{
		ll mid=l+r>>1;
		if(mid*(mid+1)*(mid+2)/6>=n) r=mid;
		else l=mid+1;
	}
	cout<<l<<endl;
	for(int i=1;i<=l;i++)
	{
		ll minn=min((ll)i,n/(l-i+1));
		n-=minn*(l-i+1);
		cout<<minn<<" ";
	}
	return 0;
}