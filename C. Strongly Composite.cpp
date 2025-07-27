#include <bits/stdc++.h>
using namespace std;
int t,n,k,res;
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		res=0;
		map<int,int> mp;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&k);
			for(int j=2;j*j<=k;j++)
			{
				if(k%j==0)
				{
					while(k%j==0)
					{
						mp[j]++;
						k/=j;
					}
				}
			}
			if(k>1) mp[k]++;
		}
		int num=0;
		for(auto it=mp.begin();it!=mp.end();it++)
		{
			int v=it->second;
			res+=v/2;
			num+=v%2;
		}
		res+=num/3;
		printf("%d\n",res);
	}
	return 0;
}
/*
2 2  3 5 
*/