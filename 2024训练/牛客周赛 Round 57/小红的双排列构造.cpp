#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
int n,k;
void solve()
{
	cin>>n>>k;
	if(k>=2)
	{
		for(int i=1;i<=n;i++)
		{
			cout<<i<<" ";
		}
		int cnt=n+1-k;
		int i=2;
		for(i;i<=2+cnt-1;i++)
		{
			cout<<i<<" ";
		}
		cout<<1<<" ";
		for(i;i<=n;i++) cout<<i<<" ";
		return;
	}
	else if(k==1)
	{
		if(n==1)
		{
			cout<<-1<<endl;
		}
		else if(n==2)
		{
			cout<<1<<" "<<1<<" "<<2<<" "<<2<<endl;
		}
		else
		{
			cout<<1<<" ";
			for(int i=1;i<=n;i++) cout<<i<<" ";
			for(int i=2;i<=n;i++) cout<<i<<" ";
		}
	}
	else
	{
		if(n<=2)
		{
			cout<<-1<<endl;
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				cout<<i<<" "<<i<<" ";
			}
		}
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