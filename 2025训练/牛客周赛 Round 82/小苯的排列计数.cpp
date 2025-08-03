#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
ll n,p[200010],q;
ll res;
ll MOD=998244353;
void solve()
{
	res=1;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
	}
	q=0;
	if(n==1)
	{
		if(p[1]==1) cout<<1<<endl;
		else cout<<0<<endl;
		return;
	}
	for(int i=2;i<=n;i++)
	{
		if(p[i]>p[i-1])
		{
			cout<<0<<endl;
			return;
		}
	}
	if(p[n]!=1)
	{
		cout<<0<<endl;
		return;
	}
	for(int i=2;i<=n;i++)
	{
		if(p[i]==p[i-1])
		{
			if(n-p[i-1]-q<=0) res=0;
			else
			res=(res*(n-p[i-1]-q))%MOD;
			q++;
		}
		else
		{
			q++;
		}
	}
	cout<<res<<endl;
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