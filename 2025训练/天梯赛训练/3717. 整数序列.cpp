#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
ll n,flag;
void solve()
{
	cin>>n;
	for(ll i=n-1;i>=2;i--)
	{
		if((2ll*n)%i==0&&(2ll*n/i-i+1)%2==0&&(2ll*n/i-i+1)>0)
		{
			ll j=((2ll*n)/i-i+1)/2;
			for(ll k=j;k<=j+i-1;k++)
			{
				cout<<k<<" ";
			}
			flag=1;
			cout<<endl;
		}
	}
	if(!flag) cout<<"NONE"<<endl;
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