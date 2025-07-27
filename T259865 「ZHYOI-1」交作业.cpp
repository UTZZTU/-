#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll,ll> mp;
ll n,k,ans,pd,ti,zy;
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		mp[k]++;
	}
	for(auto it=mp.begin();it!=mp.end();it++)
	{
		if(it->first==ti)
		{
			zy+=it->second;
			ans+=it->second;
			ti++;
		}
		else
		{
			if(zy>=it->first-ti)
			{
				zy-=it->first-ti;
				zy+=it->second;
			    ans+=it->second;
			    ti=it->first+1;
			}
			else
			break;
		}
		zy--;
	}
	cout<<n-ans;
	return 0;
}