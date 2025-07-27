#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k,res,f[5010][5010],vis[5010][5010];
struct node
{
	int x,y;
};
deque<node> q;
int main ()
{
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;i++)
	{
		q.clear();
		for(int j=1;j<=m;j++)
		{
			int t=i*j/__gcd(i,j);
			while(q.size()&&t>=q.back().x) q.pop_back();
			while(q.size()&&j-q.front().y>=k) q.pop_front();
			q.push_back({t,j});
			vis[i][j]=q.front().x;
		}
	}
	for(int i=1;i<=m;i++)
	{
		q.clear();
		for(int j=1;j<=n;j++)
		{
			int t=vis[j][i];
			while(q.size()&&t>=q.back().x) q.pop_back();
			while(q.size()&&j-q.front().y>=k) q.pop_front();
			q.push_back({t,j});
			
			if(i>=k&&j>=k) res+=q.front().x;
		}
	}
	printf("%lld",res);
	return 0;
}