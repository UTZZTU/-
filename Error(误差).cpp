#include <bits/stdc++.h>
using namespace std;
int a[100],n,l,r,mid,b[100];
bool check(int x)
{
	memset(b,0,sizeof(b));
	int l,r;
	for(int i=1;i<=n;i++)
	{
		b[i]=max(b[i-1]+1,a[i]-x);
		if(b[i]>a[i]+x)
		return false;
	}
	return true;
}
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	l=0,r=1000000000;
	while(r>l)
	{
		mid=(r+l)/2;
		if(check(mid))
		r=mid;
		else
		l=mid+1;
	}
	cout<<l;
	return 0;
}