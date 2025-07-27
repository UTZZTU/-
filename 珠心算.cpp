#include <bits/stdc++.h>
using namespace std;
map<int, int> mp;
int n,a[110],ans;
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mp[a[i]]=1;
	}
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(mp.count(a[i]+a[j])&&mp[a[i]+a[j]]==1)
			{
				ans++;
				mp[a[i]+a[j]]=2;
			}
		}
	}
	cout<<ans;
	return 0;
}