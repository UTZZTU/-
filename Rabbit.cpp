#include <bits/stdc++.h>
using namespace std;
map<int,int> mp;
int n,k,judge;
int main ()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k);
		mp[k]++;
	}
	if(mp.count(0)&&mp[0]>1)
	{
		cout<<0;
		return 0;
	}
	else if(mp.count(0)&&mp[0]==1)
	{
		cout<<1;
		return 0;
	}
	else
	{
		if(mp[1]>=1)
		judge=1;
		cout<<mp.size()-judge;
	}
	return 0;
}