#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
ll n,m,a,b,f[1010][1010],yy[1010][1010],hh[1010][1010],res;
int main ()
{
	scanf("%lld%lld%lld%lld",&n,&m,&a,&b);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%lld",&f[i][j]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		deque<ll> d,q;
		int cnt=1;
		for(int j=1;j<=m;j++)
		{
			while(d.size()&&d.back()>f[i][j])
			{
				d.pop_back();
			}
			d.push_back(f[i][j]);
			if(j>b&&d.front()==f[i][j-b])
			d.pop_front();
			if(j>=b)
			{
				yy[i][cnt++]=d.front();
			}
		}
		cnt=1;
		for(int j=1;j<=m;j++)
		{
			while(q.size()&&q.back()<f[i][j])
			{
				q.pop_back();
			}
			q.push_back(f[i][j]);
			if(j>b&&q.front()==f[i][j-b])
			q.pop_front();
			if(j>=b)
			{
				hh[i][cnt++]=q.front();
			}
		}
	}
	for(int i=1;i<=m-b+1;i++)
	{
		deque<ll> d,q;
		for(int j=1;j<=n;j++)
		{
			while(d.size()&&d.back()>yy[j][i])
			{
				d.pop_back();
			}
			d.push_back(yy[j][i]);
			if(j>a&&d.front()==yy[j-a][i])
			d.pop_front();
			while(q.size()&&q.back()<hh[j][i])
			{
				q.pop_back();
			}
			q.push_back(hh[j][i]);
			if(j>a&&q.front()==hh[j-a][i])
			q.pop_front();
			if(j>=a)
			{
				res=(res+d.front()*q.front()%mod)%mod;
			}
		}
	}
	cout<<res;
	return 0;
}