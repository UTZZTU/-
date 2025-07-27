#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,f[200010],sum,ans;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>f[i];
	sort(f+1,f+1+n);
	for(int i=1;i<n;i++) ans+=f[i];
	if(f[n]>ans*2) cout<<ans<<endl;
	else cout<<(ans+f[n])/3<<endl;
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