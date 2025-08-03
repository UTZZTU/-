#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
int n,a[200010],b[200010],res;
map<int,int> mp;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
		mp[b[i]]++;
	}
	for(auto [u,v]:mp)
	{
		if(v==1)
		{
			cout<<-1<<endl;
			return;
		}
		else if(v&1)
		{
			res+=(v+1)/2;
		}
		else res+=v/2;
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