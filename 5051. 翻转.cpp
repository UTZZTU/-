#include <bits/stdc++.h>
using namespace std;
int n,a[1010],l=-1,r=-1,judge,ll,rr;
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==i)
		l=i;
		else break;
	}
	for(int i=n;i>=1;i--)
	{
		if(a[i]==i)
		r=i;
		else break;
	}
	l++,r--;
	if(l>r)
	{
		printf("0 0");
		return 0;
	}
	ll=l,rr=r;
	while(l<=r)
	{
		swap(a[l],a[r]);
		l++,r--;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=i) judge=1;
	}
	if(!judge) printf("%d %d",ll,rr);
	else printf("0 0");
	return 0;
}