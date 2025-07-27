#include <bits/stdc++.h>
using namespace std;
int n,k;
bool check(int x)
{
	return n/x>=k;
}
int main ()
{
	cin>>n>>k;
	int l=1,r=n,mid;
	while(l<r)
	{
		mid=(l+r+1)/2;
		if(check(mid))
		l=mid;
		else
		r=mid-1;
	}
	cout<<l;
	return 0;
}