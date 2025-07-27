#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define il inline
#define re register
il ll read()
{
	ll x=0,k=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')k=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*k;
}
ll t,n,m,pd,sum,a[200010],value,k,l,r;
int main ()
{
	t=read();
	while(t--)
	{
		n=read();
		m=read();
		sum=0;
		pd=0;
		value=0;
		map<ll,int> mp;
		for(re int i=1;i<=n;i++)
		{
			k=read();
			sum+=k;
			mp[k]++;
		}
		if(sum%m==0)
		l=m,r=2*m;
		else
		l=sum%m,r=sum%m+m;
		for(auto it=mp.begin();it!=mp.end();it++)
		{
			k=l-it->first;
			if(k==it->first)
			{
				if(it->second>=2)
				{
					pd=1;
					if(l%m==0)
					value=m;
					else
					value=l%m;
				}
			}
			else
			{
				if(mp.count(k))
				{
					pd=1;
					if(l%m==0)
					value=m;
					else
					value=l%m;
				}
			}
			k=r-it->first;
			if(k==it->first)
			{
				if(it->second>=2)
				{
					pd=1;
					if(r%m==0)
					value=m;
					else
					value=r%m;
				}
			}
			else
			{
				if(mp.count(k))
				{
					pd=1;
					if(r%m==0)
					value=m;
					else
					value=r%m;
				}
			}
			if(pd)
			break;
		}
		printf("%lld\n",value);
	}
	return 0;
}