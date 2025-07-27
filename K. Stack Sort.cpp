#include <bits/stdc++.h>
using namespace std;
int t,n,k;
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		multiset<int> st;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&k);
			auto it=st.upper_bound(k);
			if(it==st.end()||*it!=k+1)
			{
				st.insert(k);
			}
			else
			{
				st.erase(it);
				st.insert(k);
			}
		}
		printf("%d\n",(int)st.size());
	}
	return 0;
}