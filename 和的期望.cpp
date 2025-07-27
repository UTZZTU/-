#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
int n,f[1000100],sum;
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
int exgcd(int a,int b,int &x,int &y)
{
    if(!b)
    {
        x=1,y=0;
        return a;
    }
    int d=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}
int qmi(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res;
}
void solve()
{
	vector<int> vec;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>f[i];
		sum+=f[i];
	}
	for(int i=1;i<=n;i++)
	{
		int p=((sum%mod)*i)%mod;
		int x=(p*qmi(n,mod-2)%mod)%mod;
		vec.push_back(x);
	}
	for(int i=0;i<n;i++) cout<<vec[i]<<" ";
}
signed main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)
	{
		solve();
	}
	return 0;
}