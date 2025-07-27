#include <bits/stdc++.h>
using namespace std;
int n,k,flag=1,pre;
set<int> st;
int main ()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k);
		st.insert(k);
	}
	for(auto it=st.begin();it!=st.end();it++)
	{
		if(it==st.begin())
		{
			pre=*it;
		}
		else
		{
			if(*it-pre!=1)
			{
				flag=0;
				break;
			}
			pre=*it;
		}
	}
	if(flag) puts("YES");
	else puts("NO");
	return 0;
}