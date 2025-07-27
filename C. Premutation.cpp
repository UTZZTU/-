#include <bits/stdc++.h>
using namespace std;
int t,n,f[110][110],mb;
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		map<int,int> mp;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<n;j++)
			{
				scanf("%d",&f[i][j]);
				if(j==1)
				{
					mp[f[i][j]]++;
				}
			}
		}
		for(auto it=mp.begin();it!=mp.end();it++)
		{
			if(it->second==n-1)
			{
				mb=it->first;
				break;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(f[i][1]!=mb)
			{
				cout<<mb;
				for(int j=1;j<n;j++)
				{
					cout<<" "<<f[i][j];
				}
				cout<<endl;
				break;
			}
		}
	}
	return 0;
}