#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,d,a[5010],b[5010],maxx;
set<int> st;
signed main ()
{
	scanf("%lld%lld",&n,&d);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		st.insert(a[i]);
	}
	for(auto it=st.begin();it!=st.end();it++)
	{
		int x=*it,res=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]<x)
			b[i]=x;
			else if(a[i]>x+d)
			{
				b[i]=x+d;
			}
			else b[i]=a[i];
			if(i>=2)
			{
				res+=abs(b[i]-b[i-1]);
			}
//			cout<<res<<endl;
		}
		maxx=max(maxx,res);
		res=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]>x)
			b[i]=x;
			else if(a[i]<x-d)
			{
				b[i]=x-d;
			}
			else b[i]=a[i];
			if(i>=2)
			{
				res+=abs(b[i]-b[i-1]);
			}
		}
		maxx=max(maxx,res);
	}
	printf("%lld",maxx);
	return 0;
}