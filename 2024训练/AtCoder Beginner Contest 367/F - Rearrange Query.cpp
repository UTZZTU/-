#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
ll n,q,a[200010],b[200010],hs[200010];
void solve()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++) hs[i]=mrand();
	for(int i=1;i<=n;i++)
	{
		ll k;
		cin>>k;
		a[i]=a[i-1]+hs[k];
	}
	for(int i=1;i<=n;i++)
	{
		ll k;
		cin>>k;
		b[i]=b[i-1]+hs[k];
	}
	while(q--)
	{
		ll l1,r1,l2,r2;
		cin>>l1>>r1>>l2>>r2;
		if(a[r1]-a[l1-1]==b[r2]-b[l2-1]) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
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