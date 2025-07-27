#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,x,y,res;
ll A(ll x)
{
	return x*(x-1);
}
int main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		map<ll,ll> mp1,mp2,mp3,mp4;
		res=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld",&x,&y);
//			if(x==0&&y==0)
//			{
//				mp1[x]++;
//				mp2[x]++;
//				mp3[x]++;
//				mp4[x]++;
//			}
//			else if(x==0)
//			{
//				mp1[]
//			}
//			else if(y==0)
//			{
//				
//			}
//			else
//			{
//				
//			}
			mp1[x-y]++;
			mp2[x+y]++;
			mp3[x]++;
			mp4[y]++;
		}
		for(auto it=mp1.begin();it!=mp1.end();it++)
		{
			if(it->second>=2)
			{
				res+=A(it->second);
			}
		}
		for(auto it=mp2.begin();it!=mp2.end();it++)
		{
			if(it->second>=2)
			{
				res+=A(it->second);
			}
		}
		for(auto it=mp3.begin();it!=mp3.end();it++)
		{
			if(it->second>=2)
			{
				res+=A(it->second);
			}
		}
		for(auto it=mp4.begin();it!=mp4.end();it++)
		{
			if(it->second>=2)
			{
				res+=A(it->second);
			}
		}
		printf("%lld\n",res);
	}
	return 0;
}