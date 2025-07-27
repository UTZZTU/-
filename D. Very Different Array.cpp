#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200010],b[200010],res;
void solve()
{
	cin>>n>>m;
	res=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cin>>b[i];
	sort(a+1,a+1+n);
	sort(b+1,b+1+m);
	int l1=1,r1=n,l2=1,r2=m;
	while(l1<=r1)
	{
		if(abs(a[l1]-b[r2])>=abs(a[r1]-b[l2]))
		{
			res+=abs(a[l1]-b[r2]);
			l1++,r2--;
		}
		else
		{
			res+=abs(a[r1]-b[l2]);
			l2++,r1--;
		}
	}
	cout<<res<<endl;
}
signed main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}