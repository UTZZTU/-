#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
set<int> st;
int n,f[1000010];
unordered_map<int,int> mp;
int main ()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&f[i]);
	}
	sort(f+1,f+1+n);
	for(int i=n;i>=1;i--)
	{
		if(mp[f[i]]) continue;
		for(int j=1;j*j<=f[i];j++)
		{
			if(f[i]%j==0)
			{
				mp[j]=1;
				mp[f[i]/j]=1;
			}
		}
		st.insert(f[i]);
		mp[f[i]]=1;
	}
	ll res=0;
	for(auto it=st.begin();it!=st.end();it++)
	{
		res+=*it-1;
	}
	printf("%lld",res);
	return 0;
}