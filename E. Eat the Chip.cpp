#include <bits/stdc++.h>
using namespace std;
int h,w,xa,ya,xb,yb;
void solve()
{
	cin>>h>>w>>xa>>ya>>xb>>yb;
	if(xa>=xb||(xb-xa)<abs(ya-yb)) 
	{
		cout<<"Draw"<<endl;
		return;
	}
	int cnt=xb-xa;
	int r1=ya+(cnt+1)/2,l1=ya-(cnt+1)/2;
	int r2=yb+cnt/2,l2=yb-cnt/2;
	r1=min(r1,w),l1=max(l1,1);
	r2=min(r2,w),l2=max(l2,1);
	if(l2>=l1&&r2<=r1&&cnt&1)
	{
		cout<<"Alice"<<endl;
		return;
	}
	if(l1>=l2&&r1<=r2&&cnt%2==0)
	{
		cout<<"Bob"<<endl;
		return;
	}
	cout<<"Draw"<<endl;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}