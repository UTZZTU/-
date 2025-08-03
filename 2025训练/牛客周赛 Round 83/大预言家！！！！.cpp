#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
// 1 4 8 15 23 34 46
//  3 4 7 8 11 12
//   1 3 1 3 1
//ll x=1,y=3,z=1,w=3,p=0;
void solve()
{
//	for(int i=1;i<=100000000;i++)
//	{
////		cout<<x<<" ";
//		x+=y;
//		if(p==0)
//		{
//			p=1;
//			y+=z;
//		}
//		else
//		{
//			p=0;
//			y+=w;
//		}
//	}
//	cout<<x<<endl;
	ll l=0,r=1e9,mid,n,x,y;
	cin>>n;
	while(l<r)
	{
		mid=l+r+1>>1;
		if((2*mid+1)*(2*mid+1)<=n)
		{
			l=mid;
		}
		else r=mid-1;
	}
	n-=(2*l+1)*(2*l+1);
	x=y=l;
	if(n>0)
	{
		n--;
		x++;
	}
	if(n>0)
	{
		ll minn=min(l+l+1,n);
		y-=minn;
		n-=minn;
	}
	if(n>0)
	{
		ll minn=min(2ll*l+2,n);
		x-=minn;
		n-=minn;
	}
	if(n>0)
	{
		ll minn=min(2ll*l+2,n);
		y+=minn;
		n-=minn;
	}
	if(n>0)
	{
		x+=n;
	}
	cout<<x<<" "<<y<<endl;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int _=1;
	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}