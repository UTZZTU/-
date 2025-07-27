#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,res,p,f[1000010];
set<int> st;
signed main ()
{
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&p);
		if(f[p]==0)
		{
			f[p]=i;
		}
		else
		{
			if(i-f[p]<=k)
			{
				st.insert(p);
			}
			f[p]=i;
		}
	}
	for(auto it=st.begin();it!=st.end();it++)
	{
		res^=*it;
//		cout<<*it<<endl;
	}
	printf("%d",res);
	return 0;
}