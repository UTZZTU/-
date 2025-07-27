#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[100010],f[100010],res;
bool check(int x,int y)
{
	int tt=a[y];
	if(tt>a[x]) return true;
	for(int i=1;i<=min((int)35,f[y]);i++)
	{
		tt*=2;
		if(tt>a[x]) return true;
	}
	return false;
}
void solve()
{
	cin>>n;
	res=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		f[i]=0;
	}
	for(int i=2;i<=n;i++)
	{
		if(check(i,i-1))
		{
			if(a[i]>=a[i-1])
			{
				int cnt=0;
				int tt=a[i-1];
				while(tt<a[i])
				{
					tt*=2;
					cnt++;
				}
				if(tt==a[i])
				{
					f[i]=f[i-1]-cnt;
				}
				else
				{
					f[i]=f[i-1]-cnt+1;
				}
			}
			else
			{
				int cnt=0;
				int tt=a[i];
				while(tt<a[i-1])
				{
					tt*=2;
					cnt++;
				}
				f[i]=f[i-1]+cnt;
			}
		}
		res+=f[i];
	}
	cout<<res<<endl;
}
signed main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}