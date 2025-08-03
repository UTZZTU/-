#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k,a[200010];
void solve()
{
	map<int,int> mp;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	mp[a[n]]++;
	mp[a[n]+k]--;
	for(int i=1;i<n;i++)
	{
		int cnt=(a[n]-a[i])/(2*k);
//		cout<<"cnt:"<<cnt<<endl;
		mp[a[i]+2*k*cnt]++;
		mp[a[i]+2*k*cnt+k]--;
		mp[a[i]+2*k*cnt+2*k]++;
		mp[a[i]+2*k*cnt+3*k]--;
	}
	int res=0,flag=0,jl;
	for(auto [u,v]:mp)
	{
//		cout<<u<<" "<<v<<endl;
		res+=v;
		if(res==n)
		{
			flag=1;
			jl=u;
			break;
		}
	}
	if(!flag) cout<<-1<<endl;
	else cout<<jl<<endl;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int _=1;
	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}