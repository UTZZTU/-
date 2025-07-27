#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<pair<int,int>> res[1010];
ll n,h,m,q,pd;
int main ()
{
	scanf("%lld %lld %lld %lld",&n,&h,&m,&q);
	for(int i=1;i<=n;i++)
	{
	    ll  a,b,c,d,ti;
		scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
		if(a==0)
		a=h;
		if(c==0)
		c=h;
		ti=(c-a)*m+d-b;
		res[c].push_back({d,ti});
	}
	while(q--)
	{
		pd=0;
		ll x,y;
		scanf("%lld %lld",&x,&y);
		for(int i=x;i<=h;i++)
		{
			if(res[i].empty())
			continue;
			for(int j=0;j<res[i].size();j++)
			{
				if(res[i][j].first>=y||i>x)
				{
				    int ti=res[i][j].second-min(res[i][j].second,res[i][j].first),qh,qm;
				    qm=res[i][j].first-(res[i][j].second-ti);
				    qh=i-ceil(ti*1.0/m);
				    ti%=m;
				    if(ti)
				    qm+=m-ti;
				    if(qh<x||qh==x&&qm<=y)
				    {
				    	pd=1;
				    	break;
					}
				}
			}
			if(pd)
			break;
		}
		if(pd)
		cout<<"No"<<endl;
		else
		cout<<"Yes"<<endl;
	}
	return 0;
}