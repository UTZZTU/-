#include <bits/stdc++.h>
using namespace std;
#define int long long
int t,n,k,a[200010],h[200010],maxx,len;
void solve(vector<int> vec)
{
	int cnt=0;
	deque<int> q;
	for(int i=0;i<vec.size();i++)
	{
		q.push_back(vec[i]);
		cnt+=vec[i];
		if(cnt<=k) 
		{
			len=max(len,(int)q.size());
		}
		while(cnt>k&&q.size())
		{
			cnt-=q.front();
			q.pop_front();
		}
		if(cnt<=k) 
		{
			len=max(len,(int)q.size());
		}
	}
}
signed main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		maxx=0;
		len=0;
		scanf("%lld%lld",&n,&k);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
		}
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&h[i]);
		}
		vector<int> vec;
		for(int i=1;i<=n;i++)
		{
			if(i==1)
			{
				vec.push_back(a[i]);
			}
			else
			{
				if(h[i-1]%h[i]==0)
				{
					vec.push_back(a[i]);
				}
				else
				{
					solve(vec);
					vec.clear();
					vec.push_back(a[i]);
				}
			}
		}
		solve(vec);
		printf("%lld\n",len);
	}
	return 0;
}