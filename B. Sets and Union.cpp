#include <bits/stdc++.h>
using namespace std;
int t,n,k,x;
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		map<int,int> mp;
		scanf("%d",&n);
		vector<int> vec[55];
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&k);
			for(int j=1;j<=k;j++)
			{
				scanf("%d",&x);
				vec[i].push_back(x);
				mp[x]++;
			}
		}
		int maxx=0;
		for(auto it=mp.begin();it!=mp.end();it++)
		{
//			minn=min(minn,it->second);
			int u=it->first;
			set<int> st;
			for(int i=1;i<=n;i++)
			{
				int flag=1;
				for(int j=0;j<vec[i].size();j++)
				{
					if(vec[i][j]==u)
					{
						flag=0;
						break;
					}
				}
				if(flag)
				{
					for(int j=0;j<vec[i].size();j++)
					{
						st.insert(vec[i][j]);
					}
				}
			}
			maxx=max(maxx,(int)st.size());
		}
		printf("%d\n",maxx);
	}
	return 0;
}