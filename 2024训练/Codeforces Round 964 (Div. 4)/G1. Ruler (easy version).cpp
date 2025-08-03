#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int ask(int a,int b)
{
	cout<<"? "<<a<<" "<<b<<endl;
	int tt;
	cin>>tt;
	if(tt==a*b) return true;
	else return false;
}
void solve()
{
	int l=2,r=999;
	while(l<r)
	{
		int mid=l+r>>1;
		if(!ask(mid,mid)) r=mid;
		else l=mid+1;
	}
	cout<<"! "<<l<<endl;
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