#include <bits/stdc++.h>
using namespace std;
int n,f[110],res;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>f[i];
		if(f[i]&1) res++;
	}
	if(res==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(f[i]&1)
			{
				cout<<i<<endl;
				return;
			}
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(f[i]%2==0)
			{
				cout<<i<<endl;
				return;
			}
		}
	}
}
int main ()
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