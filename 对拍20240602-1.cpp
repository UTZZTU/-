#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
int n,res,f[100010],pp,npp;
void solve()
{
//	res=0;
	cin>>n;
	int tt=1,ttt;
//	int tt=1;
	
//	for(int i=1;i<=n;i++)
//	{
//		tt*=i;
//	}
//	tt=60;
	for(int i=1;i<=n;i++)
	{
		int gcd=__gcd(i,tt);
		ttt=(tt*i)/gcd;
		ttt%=mod;
		cout<<" ttt "<<ttt<<endl;
		f[i]=f[i-1]*(ttt/tt);
		f[i]%=mod;
//		f[i]=f[i-1]*i;
//		tt*=i;
		for(int j=1;j<i;j++)
		{
			double fps=i*j*1.0/(i-j);
			int cnt=(int)(ttt*1.0/fps);
			f[i]+=cnt;
			f[i]%=mod;
//			res+=cnt;
			cout<<i<<" "<<j<<" "<<cnt<<endl;
		}
		cout<<endl<<"f[i]:  "<<f[i]<<endl;
		npp=f[i]-f[i-1]*(ttt/tt);
		cout<<npp<<endl;
//		pp=npp;
		tt=ttt;
	}
	cout<<f[n]<<endl;
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