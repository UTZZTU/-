#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 998244353;
priority_queue<int,vector<int>,greater<int> > q[10010];
int n,w,p,res=1;
signed main ()
{
	scanf("%lld%lld",&n,&w);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&p);
		for(int j=2;j*j<=p;j++)
		{
			if(p%j==0)
			{
				int cnt=0;
				while(p%j==0)
				{
					p/=j;
					cnt++;
				}
				q[j].push(cnt);
			}
		}
		if(p>1)
		{
			q[p].push(1);
		}
	}
	for(int i=2;i*i<=w;i++)
	{
		if(w%i==0)
		{
			while(w%i==0)
			{
				w/=i;
				if(q[i].size()<n)
				{
					q[i].push(1);
				}
				else
				{
					int u=q[i].top();
					q[i].pop();
					q[i].push(u+1);
				}
			}
		}
	}
	if(w>1)
	{
		if(q[w].size()<n)
		{
			q[w].push(1);
		}
		else
		{
			int u=q[w].top();
			q[w].pop();
			q[w].push(u+1);
		}
	}
	for(int i=2;i<=10000;i++)
	{
		if(q[i].size())
		{
			while(q[i].size())
			{
				int u=q[i].top();
				q[i].pop();
				res=(res*(u+1)%MOD)%MOD;
			}
		}
	}
	printf("%lld",res);
	return 0;
}