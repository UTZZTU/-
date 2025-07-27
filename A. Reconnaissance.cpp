#include <bits/stdc++.h>
using namespace std;
int n,d,res,f[1010];
void solve()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>f[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j) continue;
			if(abs(f[i]-f[j])<=d) res++;
		}
	}
	cout<<res<<endl;
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