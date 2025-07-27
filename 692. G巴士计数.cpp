#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> q;
vector<int> vec;
int t,n,p;
int main ()
{
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		vec.clear();
		q.clear();
		scanf("%d",&n);
		for(int j=1,x,y;j<=n;j++)
		{
			scanf("%d %d",&x,&y);
			q.push_back({x,y});
		}
		scanf("%d",&p);
		for(int j=1,x;j<=p;j++)
		{
			int ans=0;
			scanf("%d",&x);
			for(int k=0;k<q.size();k++)
			{
				if(q[k].first<=x&&q[k].second>=x)
				ans++;
			}
			vec.push_back(ans);
		}
		cout<<"Case #"<<i<<":";
		for(int j=0;j<vec.size();j++)
		cout<<" "<<vec[j];
		cout<<endl;
	}
	return 0;
}