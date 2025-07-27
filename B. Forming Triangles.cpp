#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[300010],res;
int num(int x)
{
	return x*(x-1)*(x-2)/6;
}
void solve()
{
	map<int,int> mp;
	res=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mp[a[i]]++;
	}
	sort(a+1,a+1+n);
	for(auto it=mp.begin();it!=mp.end();it++)
	{
		int x=it->first;
		int cnt=it->second;
		if(cnt>=3)
		{
			res+=num(cnt);
		}
		if(cnt>=2)
		{
			int pos=upper_bound(a+1,a+1+n,x)-a;
			pos--;
			res+=(cnt)*(cnt-1)/2*(pos-cnt);
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