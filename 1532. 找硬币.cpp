#include <bits/stdc++.h>
using namespace std;
map<int,int>mp;
int n,m,k;
int main ()
{
	scanf("%d %d",&n,&m);
	while(n--)
	{
		scanf("%d",&k);
		mp[k]++;
	}
	for(auto it=mp.begin();it!=mp.end();it++)
	{
		k=m-it->first;
		if(k==it->first&&it->second>=2||k!=it->first&&mp.count(k))
		{
			cout<<it->first<<" "<<k;
			return 0;
		}
	}
	cout<<"No Solution";
	return 0;
}