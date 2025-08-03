#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
4
12
123
1234
23
234
34
*/
ll b[200010][31][2],a[200010][31],f[200010],n,sum,res,t[200010][31];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>f[i];
		for(ll j=0;j<30;j++)
		{
			if((f[i]>>j)&1)
			{
				a[i][j]++;
				t[i][j]++;
			}
			a[i][j]+=a[i-1][j];
		}
		for(ll j=0;j<30;j++)
		{
			if(a[i][j]&1) b[i][j][1]++;
			else b[i][j][0]++;
			b[i][j][1]+=b[i-1][j][1];
			b[i][j][0]+=b[i-1][j][0];
		}
	}
//	cout<<b[n][0][1]-b[1][0][1]<<endl;
	for(int i=1;i<n;i++)
	{
		for(ll j=0;j<30;j++)
		{
			if(t[i][j])
			{
				if(a[i][j]&1)
				{
					ll cnt=b[n][j][1]-b[i][j][1];
					res+=(cnt)*(1ll<<j);
				}
				else
				{
					ll cnt=b[n][j][0]-b[i][j][0];
					res+=(cnt)*(1ll<<j);
				}
			}
			else
			{
				if(a[i][j]&1)
				{
					ll cnt=b[n][j][0]-b[i][j][0];
					res+=(cnt)*(1ll<<j);
				}
				else
				{
					ll cnt=b[n][j][1]-b[i][j][1];
					res+=(cnt)*(1ll<<j);
				}
			}
		}
	}
	cout<<res<<endl;
}
int main ()
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