#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
ll n,q,a[100010],cf[100010],pp[100010];
void solve()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]+=a[i-1];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			ll num=a[j]-a[i-1];
			ll x=sqrt(num);
			if(x*x==num)
			{
				cf[i]++;
				cf[j+1]--;
			}
		}
	}
	ll sum=0;
	for(int i=1;i<=n;i++)
	{
		sum+=cf[i];
		pp[i]=sum;
	}
	while(q--)
	{
		ll x;
		cin>>x;
		cout<<pp[x]<<endl;
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