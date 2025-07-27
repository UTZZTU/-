#include <bits/stdc++.h>
using namespace std;
int n,f[110];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>f[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				if(i==j||i==k||j==k) continue;
				if(f[i]==f[j]+f[k])
				{
					cout<<i<<" "<<j<<" "<<k<<endl;
					return;
				}
			}
		}
	}
	cout<<-1<<endl;
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