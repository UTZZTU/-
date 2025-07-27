#include <bits/stdc++.h>
using namespace std;
int t,n,m,f[210],u,v;
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		memset(f,0,sizeof(f));
		while(m--)
		{
			scanf("%d%d",&u,&v);
			f[u]++,f[v]++;
		}
		map<int,int> mp;
		for(int i=1;i<=n;i++)
		{
			if(f[i]) mp[f[i]]++;
		}
		vector<int> vec;
		for(auto it=mp.begin();it!=mp.end();it++)
		{
			vec.push_back(it->second);
		}
		sort(vec.begin(),vec.end());
		if(vec.size()==3)
		{
			printf("%d %d\n",vec[1],vec[2]/vec[1]);
		}
		else
		{
			printf("%d %d\n",vec[0]-1,vec[1]/(vec[0]-1));
		}
	}
	return 0;
}