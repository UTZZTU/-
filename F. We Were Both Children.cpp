#include <bits/stdc++.h>
using namespace std;
int t,n,f[200010],maxx,res;
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		map<int,int> mp1,mp2;
		maxx=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&f[i]);
			if(f[i]<=n)
			mp1[f[i]]++;
		}
		for(auto it=mp1.begin();it!=mp1.end();it++)
		{
			int i=it->first,j=it->second;
			int k=i;
			while(k<=n)
			{
				mp2[k]+=j;
				k+=i;
			}
		}
		for(auto it=mp2.begin();it!=mp2.end();it++)
		{
			maxx=max(maxx,it->second);
		}
		printf("%d\n",maxx);
	}
	return 0;
}