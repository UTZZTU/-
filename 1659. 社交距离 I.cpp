#include <bits/stdc++.h>
using namespace std;
int a[100010],k,n,zdz=1000000;
string u;
bool check(int x)
{
	int ans=0;
	for(int i=2;i<=k;i++)
	{
		if(a[i]-a[i-1]>2*x-1)
		{
			ans+=1+(a[i]-a[i-1]-(2*x-1))/x;
		}
	}
	if(a[1]!=1&&a[1]!=0)
	{
		ans+=(a[1]-1)/x;
	}
	if(a[k]!=n)
	{
		if(a[k]==0)
		{
		ans++;
		ans+=(n-1)/x;
		}
		else
		{
			ans+=(n-a[k])/x;
		}
	}
	return ans>=2;
}
int main ()
{
	cin>>n;
	getchar();
	getline(cin,u);
	for(int i=0;i<u.size();i++)
	{
		if(u[i]=='1')
		{
			a[++k]=i+1;
		}
	}
	for(int i=2;i<=k;i++)
	{
		zdz=min(zdz,a[i]-a[i-1]);
	}
	int l=0,r=n;
	while(l<r)
	{
		int mid=(l+r+1)/2;
		if(check(mid))
		l=mid;
		else
		r=mid-1;
	}
	cout<<min(l,zdz);
	return 0;
}