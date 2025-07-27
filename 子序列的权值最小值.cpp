#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[25],minn=0x3f3f3f3f3f3f3f3f,res;
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		minn=min(minn,a[i]);
	}
	for(int i=1;i<n;i++)
	{
		res=a[i];
		for(int j=i+1;j<=n;j++)
		{
			res&=a[j];
			minn=min(minn,res);
		}
	}
	cout<<minn;
	return 0;
}