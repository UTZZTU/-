#include <bits/stdc++.h>
using namespace std;
int n,m,f[110],res,cnt;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>f[i];
	sort(f+1,f+1+n);
	for(int i=1;i<=n;i++)
	{
		if(f[i]<0)
		{
			res+=abs(f[i]);
			cnt++;
			if(cnt==m) break;
		}
		else break;
	}
	cout<<res;
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