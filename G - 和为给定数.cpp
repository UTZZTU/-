#include <bits/stdc++.h>
using namespace std;
int n,m,k;
map<int,int> mp;
int main ()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k);
		mp[k]++;
	}
	scanf("%d",&m);
	for(auto it=mp.begin();it!=mp.end();it++)
	{
		k=m-it->first;
		if(mp.count(k))
		{
			printf("%d %d",it->first,k);
			return 0;
		}
	}
	printf("No");
	return 0;
}