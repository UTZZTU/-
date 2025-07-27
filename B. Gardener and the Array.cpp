#include <bits/stdc++.h>
using namespace std;
int t,n,k,tt,flag,judge;
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		flag=0;
		map<int,int> mp;
		scanf("%d",&n);
		vector<int> vec[n+10];
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&k);
			for(int j=1;j<=k;j++)
			{
				scanf("%d",&tt);
				mp[tt]++;
				vec[i].push_back(tt);
			}
		}
		for(int i=1;i<=n;i++)
		{
			judge=0;
			for(int j=0;j<vec[i].size();j++)
			{
				if(mp[vec[i][j]]<2)
				{
					judge=1;
					break;
				}
			}
			if(!judge)
			{
				flag=1;
				break;
			}
		}
		if(flag)
		printf("Yes\n");
		else
		printf("No\n");
	}
	return 0;
}