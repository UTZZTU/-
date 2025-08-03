#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200010],b[200010],n,x,y;
void solve()
{
	cin>>n>>x>>y;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	ll minn=n;
	for(int i=n;i>=1;i--)
	{
		x-=a[i];
		if(x<0)
		{
			minn=min(minn,n-i+1);
			break;
		}
	}
	for(int i=n;i>=1;i--)
	{
		y-=b[i];
		if(y<0)
		{
			minn=min(minn,n-i+1);
			break;
		}
	}
	cout<<minn<<endl;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int _=1;
//	cin>>_;
	while(_--)
	{
		solve();
	}	
	return 0;
}