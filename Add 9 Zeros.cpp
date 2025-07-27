#include <bits/stdc++.h>
using namespace std;
map<int,int> mp;
int a[500010],n,sum;
int main ()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		mp[a[i]]++;
	}
	for(int i=1;i<=n;i++)
	{
		if(!mp.count(a[i]+9))
		sum++;
	}
	cout<<sum;
	return 0;
}