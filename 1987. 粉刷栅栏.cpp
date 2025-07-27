#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x,pos,n,ans,sum,q,tt,sc;
char c;
map<ll,ll> mp;
int main ()
{
	cin>>n;
	while(n--)
	{
		cin>>x>>c;
		if(c=='L')
		{
			mp[pos-x]++;
			mp[pos]--;
			pos-=x;
		}
		else
		{
			mp[pos]++;
			mp[pos+x]--;
			pos+=x;
		}
	}
	for(auto it=mp.begin();it!=mp.end();it++)
	{
		tt++;
		if(tt==1)
		{
			q=it->first;
			sum+=it->second;
		}
		else
		{
			if(sum>1)
			{
				ans+=it->first-q;
//				if(sc)
//				{
//					ans++;
//				}
//				sc=1;
			}
//			else
//			sc=0;
			q=it->first;
			sum+=it->second;
//			if(tt==mp.size())
//			{
//				if(sum>1)
//			{
//				ans+=1;
//			}
//			}
		}
	}
	cout<<ans;
	return 0;
}