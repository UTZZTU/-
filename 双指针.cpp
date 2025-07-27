#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,a[200010],b[200010];
ll res;
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		unordered_map<double,vector<int>> mp;
		res=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&b[i]);
			mp[a[i]*1.0/b[i]].push_back(i);
		}
		for(ll i=1;i<=n;i++)
		{
//			vector<ll> vec=mp[(b[i]/fact)*1.0/(a[i]/fact)];
//			mp[b[i]*1.0/a[i]]
//			for(int j=0;j<vec.size();j++)
//			{
//				cout<<vec[j]<<" ";
//			}
//			cout<<endl;
//			cout<<<<endl;
//			if(vec.empty()) continue;
			int t=(upper_bound(mp[b[i]*1.0/a[i]].begin(),mp[b[i]*1.0/a[i]].end(),i)-mp[b[i]*1.0/a[i]].begin());
			res+=mp[b[i]*1.0/a[i]].size()-t;
		}
		printf("%lld\n",res);
	}
	return 0;
}