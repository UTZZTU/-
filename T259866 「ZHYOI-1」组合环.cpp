#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll fun(ll n,ll m)
{
	if(m==0||n==m)
	return 1;
	ll res=1;
	m=min(m,n-m);
	for(int i=n;i>=n-m+1;i--)
	res=res*i;
	for(int i=2;i<=m;i++)
	res=res/i;
	return res;
}
ll f[30],n,sc,ans,jj=1;
int main ()
{
	cin>>n;
	for(int i=0;i<=n;i++)
	{
		f[i]=fun(n,i);
		ans+=f[i];
	}
	if(n==0)
	sc=0;
	else
	{
		if(n%4==0)
		sc=(n/4-1)*2+1;
		else
		sc=n/4*2+1;
	}
	cout<<sc;
	ans--;
	f[sc]--;
	while(ans)
	{
		if(jj)
		{
			if(f[sc+1])
			{
				sc++;
				cout<<" "<<sc;
				f[sc]--;
				if(sc==n)
				jj=0;
			}
			else
			{
				jj=0;
				sc--;
				cout<<" "<<sc;
				f[sc]--;
			}
		}
		else
		{
			if(f[sc-1])
			{
				sc--;
				cout<<" "<<sc;
				f[sc]--;
				if(sc==0)
				jj=1;
			}
			else
			{
				jj=1;
				sc++;
				cout<<" "<<sc;
				f[sc]--;
			}
		}
		ans--;
	}
	return 0;
}