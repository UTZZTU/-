#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
int n,pre=1,now,th=1,ppt=2,thh=1;
void solve()
{
//	res=0;
	cin>>n;
	int tt=1;
	if(n==1)
	{
		cout<<0<<endl;
		return;
	}
	else if(n==2)
	{
		cout<<1<<endl;
		return;
	}
	for(int i=3;i<=n;i++)
	{
		now=pre*i;
		now%=mod;
//		for(int j=i+1;j<=n;j++)
//		{
//			double fps=i*j*1.0/(j-i);
//			int cnt=(int)(tt/fps);
//			res+=cnt;
//		}
		th*=i;
		th%=mod;
		thh*=(i-1);
		thh%=mod;
		now=(now+th+thh)%mod;
		th=(th+thh)%mod;
		pre=now;
	}
	cout<<now%mod<<endl;
}
signed main ()
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