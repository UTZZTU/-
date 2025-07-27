#include <bits/stdc++.h>
using namespace std;
int t,n,k,temp;
void solve()
{
	scanf("%d",&n);
	vector<vector<int> > vec(n+1);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&k);
			vec[i].push_back(k);
		}
	}
	set<pair<int,int> >st;
	temp=n;
	while(st.size()<n-1)
	{
		for(int i=0;i<n;i++)
		{
			int x=vec[i][0],y=vec[i][1];
			if(x>y) swap(x,y);
			st.insert({x,y});
		}
		if(st.size()==n-1) break;
		int del=vec[0][--temp];
		for(int i=0;i<n;i++)
		{
			for(auto it=vec[i].begin();it!=vec[i].end();it++)
			{
				if((*it)==del)
				{
					vec[i].erase(it);
					break;
				}
			}
		}
	}
	for(auto x:st)
	{
		printf("%d %d\n",x.first,x.second);
	}
	return;
}
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		solve();
	}
	return 0;
}