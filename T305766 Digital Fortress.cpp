#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,m,k;
ll get_length(ll x)
{
	ll res=1;
	while(x>=2)
	{
		x/=2;
		res++;
	}
	return res;
}
int main ()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		ll u=get_length(m);
		if(u>=n)
		{
			cout<<"Yes"<<endl;
			k=1;
			for(int i=1;i<=n;i++)
			{
				cout<<k<<" ";
				k*=2;
			}
			cout<<endl;
		}
		else
		cout<<"No"<<endl;
	}
	return 0;
}