#include <bits/stdc++.h>
using namespace std;
#define int long long
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
int s[100010],k[100010],n,p,f,res;
vector<int> vec[100010];
signed main ()
{
	scanf("%lld%lld",&n,&p);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld%lld",&f,&s[i],&k[i]);
		vec[f].push_back(i);
	}
	q.push({k[1],(long long)1});
	while(!q.empty())
	{
		pair<int,int> pa=q.top();
		q.pop();
		int u=pa.first,v=pa.second;
		if(p>=u)
		{
			res++;
			p+=s[v];
			for(int i=0;i<vec[v].size();i++)
			{
				int j=vec[v][i];
				q.push({k[j],j});
			}
		}
		else
		{
			break;
		}
	}
	printf("%lld",res);
	return 0;
}