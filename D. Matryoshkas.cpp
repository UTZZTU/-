#include <bits/stdc++.h>
using namespace std;
int t,n,k,num,ans,nc,pre,js;
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		map<int,int> mp;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&k);
			mp[k]++;
		}
		ans=0;
		for(auto it=mp.begin();it!=mp.end();it++)
		{
			if(it==mp.begin())
			{
				num=it->first;
				js=it->second;
				pre=it->second;
				nc=0;
			}
			else
			{
				if(it->first==num+1)
				{
					num++;
					if(it->second>pre)
					{
						nc+=it->second-pre;
					}
					pre=it->second;
				}
				else
				{
					ans+=js+nc;
					nc=0;
					pre=it->second;
					num=it->first;
					js=it->second;
				}
			}
		}
		ans+=js+nc;
		cout<<ans<<endl;
	}
	return 0;
}