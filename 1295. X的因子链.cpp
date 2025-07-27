#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x,pos,res,tt,ans;
struct node{
	ll num;
	ll cs;
}s[100010];
int main ()
{
	while(~scanf("%lld",&x))
	{
		tt=x;
		pos=1;
		res=0;
		for(int i=2;i*i<=x;i++)
		{
			if(tt%i==0)
			{
				s[pos].num=i;
				s[pos].cs=0;
				while(tt%i==0)
				{
					tt/=i;
					s[pos].cs++;
				}
				res+=s[pos].cs;
				pos++;
			}
		}
		if(tt>1)
		{
			s[pos].num=tt;
			s[pos].cs=1;
			res+=s[pos].cs;
			pos++;
		}
		ans=1;
		for(int i=2;i<=res;i++)
		{
			ans*=i;
		}
		for(int i=1;i<pos;i++)
		{
			for(int j=2;j<=s[i].cs;j++)
			ans/=j;
		}
		cout<<res<<" "<<ans<<endl;
	}
	return 0;
}