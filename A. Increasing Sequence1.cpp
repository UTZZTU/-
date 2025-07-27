#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,d,b[2010],res;
void solve()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	for(int i=2;i<=n;i++)
	{
		if(b[i]>b[i-1]) continue;
		int cnt=ceil((b[i-1]-b[i])*1.0/d);
		res+=cnt;
		b[i]+=cnt*d;
		if(b[i]==b[i-1]) 
		{
			res++;
			b[i]+=d;
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
//	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}