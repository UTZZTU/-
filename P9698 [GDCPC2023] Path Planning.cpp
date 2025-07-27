#include <bits/stdc++.h>
using namespace std;
int t,n,m,f1,f2,k;
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		map<int,pair<int,int> >mp;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				scanf("%d",&k);
				mp[k]={i,j};
				if(i==1&&j==1) f1=k;
				if(i==n&&j==m) f2=k;
			}
		}
		multiset<pair<int,int> >st;
		st.insert(mp[f1]);
		st.insert(mp[f2]);
		int i=0;
		for(i;i<=n*m-1;i++)
		{
			if(i==f1||i==f2) continue;
			pair<int,int> p=mp[i];
			auto post=st.lower_bound(p);
			auto pre=prev(post);
			if(p.second>=(*pre).second&&p.second<=(*post).second)
			{
				st.insert(p);
			}
			else break;
		}
		printf("%d\n",i);
	}
	return 0;
}