#include <bits/stdc++.h>
using namespace std;
int minn=0x3f3f3f3f,n,m,k,a[1010],b[1010];
int main ()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	for(int i=1;i<=k;i++)
	{
		minn=min(minn,a[i]+b[k+1-i]);
	}
	if(m>=minn)
	cout<<"Yes";
	else
	cout<<"No";
	return 0;
}