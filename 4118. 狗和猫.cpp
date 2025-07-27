#include <bits/stdc++.h>
using namespace std;
#define int long long
int t,n,d,c,m;
string s;
signed main ()
{
	scanf("%lld",&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%lld%lld%lld%lld",&n,&d,&c,&m);
		getchar();
		cin>>s;
		int judge=1;
		int j=0;
		for(j;j<s.size();j++)
		{
			if(s[j]=='D')
			{
				if(d>0)
				{
					d--,c+=m;
				}
				else
				{
					judge=0;
					break;
				}
			}
			else
			{
				if(c>0)
				{
					c--;
				}
				else
				{
					break;
				}
			}
		}
		for(j;j<s.size();j++)
		{
			if(s[j]=='D')
			{
				judge=0;
				break;
			}
		}
		if(judge) printf("Case #%lld: YES\n",i);
		else printf("Case #%lld: NO\n",i);
	}
	return 0;
}