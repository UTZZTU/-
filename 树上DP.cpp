#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,u,v,vis[200010],cnt;
ll a[200010],res;
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		res=0;
		cnt=0;
		vector<int> vec[n+10];
		for(int i=1;i<n;i++)
		{
			
			scanf("%d%d",&u,&v);
			vec[u].push_back(v);
			vec[v].push_back(u);
		}
		for(int i=1;i<=n;i++)
		{
			vis[i]=0;
			scanf("%lld",&a[i]);
		}
		sort(a+1,a+1+n);
		queue<pair<int,int>> q;
		q.push({1,1});
		while(!q.empty())
		{
			pair<int,int> p=q.front();
			u=p.first,v=p.second;
			q.pop();
			if(vis[u]) continue;
			vis[u]=1;
			cnt++;
			res+=a[cnt]*v;
			for(int i=0;i<vec[u].size();i++)
			{
				int j=vec[u][i];
				if(vis[j]) continue;
				q.push({j,v+1});
			}
		}
		printf("%lld\n",res);
	}
	return 0;
}