#include <bits/stdc++.h>
using namespace std;
int x,y,z;
bool check(int tt)
{
	long long res=0;
	res+=(long long)tt*x+(long long)y*ceil(tt/3.0);
	return res>=z;
}
int main ()
{
	cin>>x>>y>>z;
	int l=1,r=z;
	while(l<r)
	{
		int mid=l+r>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	cout<<l;
	return 0;
}