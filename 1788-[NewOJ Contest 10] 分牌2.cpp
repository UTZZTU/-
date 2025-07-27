#include <bits/stdc++.h>
using namespace std;
int n,k,f[1000010],u;
priority_queue<pair<int,int>> q;
int main ()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&u);
		f[u]++;
	}
	for(int i=1;i<=1000000;i++)
	{
		if(f[i]) q.push({f[i],i});
	}
	while(q.size()>=k)
	{
		vector<pair<int,int>> vec;
		int cnt=0;
		while(cnt<k)
		{
			vec.push_back(q.top());
			q.pop();
			cnt++;
		}
		for(int i=0;i<cnt;i++)
		{
			printf("%d ",vec[i].second);
			vec[i].first--;
			if(vec[i].first)
			q.push(vec[i]);
		}
		printf("\n");
	}
	return 0;
}