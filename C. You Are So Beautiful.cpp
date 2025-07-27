#include <bits/stdc++.h>
using namespace std;
//#define int long long
typedef long long ll;
int t,n,a[100010],cnt,f[100010];
ll res;
signed main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		cnt=res=0;
		map<int,int> mp;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(!mp[a[i]])
			{
				cnt++;
				mp[a[i]]=i;
				f[i]=cnt;
				res+=cnt;
			}
			else
			{
				f[i]=cnt;
				res-=f[mp[a[i]]];
				res+=f[i];
				mp[a[i]]=i;
			}
		}
		printf("%lld\n",res);
	}
	return 0;
}
