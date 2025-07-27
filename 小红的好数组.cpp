#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;
int qmi(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1) res=res*a%MOD;
		b>>=1;
		a=a*a%MOD;
	}
	return res;
}
int n,k,sum=1,jd;
void solve()
{
	cin>>n>>k;
	sum=(sum*qmi(k/2,n))%MOD;
	int cnt=n/3;
	jd=(qmi(k/2,cnt)%MOD*qmi((k+1)/2,cnt*2))%MOD;
//	cout<<sum<<" "<<jd<<endl;
	if(n%3==0)
	{
		sum=(sum+jd*3)%MOD;
	}
	else if(n%3==1)
	{
		sum=(sum+((jd*((k+1)/2))%MOD*2)%MOD+((jd*(k/2))%MOD)%MOD)%MOD;
	}
	else
	{
		sum=((sum+(((jd*((k+1)/2))%MOD*(k/2))%MOD*2)%MOD+((jd*((k+1)/2))%MOD*((k+1)/2)))%MOD)%MOD;
	}
	cout<<sum<<endl;
}
signed main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}