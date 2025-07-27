#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<ll,ll> mp;
ll n,k,f[4000010],res,cnt,ans;
struct node
{
	ll first,second,flag;
}s[4000010];
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>f[i];
		mp[f[i]]++;
	}
	if(mp[f[1]]==n)
	{
		cout<<0;
		return 0;
	}
	for(int i=2;i<=n;i++)
	{
		if(i==2)
		res=__gcd(f[1],f[2]);
		else
		res=__gcd(res,f[i]);
	}
	for(int i=1;i<=n;i++)
	{
		f[i]/=res;
	}
	for(int i=1;i<=n;i++)
	{
		if(f[i]==1)
		continue;
		int j=i;
		res=f[i];
		while(j<=n&&f[j]!=1)
		{
			res=__gcd(res,f[j]);
			j++;
		}
		s[++cnt].first=i;
		s[cnt].second=j-1;
		if(res==1)
		s[cnt].flag=0;
		else
		s[cnt].flag=1;
		i=j-1;
	}
	for(int i=1;i<=cnt;i++)
	{
		if(s[i].flag==0)
		ans+=s[i].second-s[i].first+1+k;
		else
		{
			int j=i+1;
			while(j<=cnt&&s[j].flag==1)
			{
				if(s[j].first-s[j-1].second-1<=2*k+2&&j<=i+1)
				{
					j++;
				}
				else
				break;
			}
			j--;
			if(j==i)
			ans++;
			ans+=s[j].second-s[i].first+1+k;
			i=j;
		}
	}
	cout<<ans;
	return 0;
}