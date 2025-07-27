#include <bits/stdc++.h>
using namespace std;
int n,x[110],d[110];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>x[i]>>d[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(x[i]+d[i]==x[j]&&x[j]+d[j]==x[i])
			{
				cout<<"YES"<<endl;
				return;
			}
		}
	}
	cout<<"NO"<<endl;
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