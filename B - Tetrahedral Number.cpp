#include <bits/stdc++.h>
using namespace std;
int n;
void solve()
{
	cin>>n;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			for(int k=0;k<=n;k++)
			{
				if(i+j+k<=n) cout<<i<<" "<<j<<" "<<k<<endl;
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