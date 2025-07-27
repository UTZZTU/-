#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[100010],pre[100010],res;
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		pre[i]=pre[i-1]+a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int pos=lower_bound(pre+1,pre+1+n,pre[i-1]+k)-pre;
		if(pos<=n)
		{
			res+=n-pos+1;
		}
        else break;
	}
	cout<<res<<endl;
}
signed main ()
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