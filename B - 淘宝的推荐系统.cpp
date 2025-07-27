#include <bits/stdc++.h>
using namespace std;
#define il inline
#define re register
int t,n,d,f[50010],a[50010];
il int read()
{
	int x=0,k=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
		k=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return x*k;
}
int main ()
{
	t=read();
	while(t--)
	{
		map<int,set<int>> mp;
		int maxx=1,pos;
		n=read(),d=read();
		for(re int i=1;i<=n;i++)
		{
			a[i]=read();
			f[i]=1;
		}
		mp[f[1]].insert(a[1]);
		for(re int i=2;i<=n;i++)
		{
			pos=0;
		    for(auto it=mp.rbegin();it!=mp.rend();it++)
		    {
		    	set<int> st=it->second;
		    	if(st.empty())
		    	continue;
		    	int x=*st.lower_bound(a[i]-d);
		    	if(x<=a[i]+d&&x>=a[i]-d)
		    	{
		    		pos=it->first;
		    		break;
				}
			}
			f[i]+=pos;
		    maxx=max(maxx,f[i]);
		    mp[f[i]].insert(a[i]);
		}
		printf("%d\n",maxx);
	}
	return 0;
}