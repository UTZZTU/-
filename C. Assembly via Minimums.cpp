#include <bits/stdc++.h>
using namespace std;
int t,n,f[1010000],num,k;
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		map<int,int> mp;
		num=0;
		vector<int> vec;
		scanf("%d",&n);
		for(int i=1;i<=n*(n-1)/2;i++)
		{
			scanf("%d",&k);
			mp[k]++;
			f[i]=0;
		}
		for(auto it=mp.begin();it!=mp.end();it++)
		{
			int fi=it->first,se=it->second;
			if(se<n&&f[se]==0)
			{
				vec.push_back(fi);
				f[se]=1;
				num++;
			}
			else
			{
				int cnt=n-1-num,pp=0,res=0;
				while(res<se)
				{
					res+=cnt;
					f[cnt]=1;
					cnt--;
					pp++;
				}
				for(int i=1;i<=pp;i++)
				{
					vec.push_back(fi);
				}
				num+=pp;
			}
		}
		for(int i=0;i<vec.size();i++)
		{
			printf("%d ",vec[i]);
		}
		printf("1000000000\n");
	}
	return 0;
}
/*
1 2 2 2 3
1 1 1 1 2 2 2 2 2 2
1 10 10
1 1 10
1 2 3 4 5
1 1 1 1 1 2 2 2 3 3 4
*/