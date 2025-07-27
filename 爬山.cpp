#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,p,f[100010],res,maxx;
bool check(ll x)
{
	ll sum=0;
	for(int i=1;i<=n;i++)
	{
		if(f[i]>x)
		{
			sum+=f[i]-x;
		}
	}
//	cout<<x<<" "<<sum<<endl;
	return sum*2>=p;
}
int main ()
{
	cin>>n>>p;
	for(int i=1;i<=n;i++)
	{
		cin>>f[i];
		res+=f[i];
		maxx=max(maxx,f[i]);
	}
	if(res*2<p)
	{
		cout<<"-1";
		return 0;
	}
	ll l=0,r=maxx,mid;
	while(l<r)
	{
		mid=l+r+1>>1;
//		cout<<mid<<endl;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
}